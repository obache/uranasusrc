$NetBSD: patch-uxspec.c,v 1.3 2015/04/12 15:56:08 tnn Exp $

Fix build on systems without lchown.
Fix CVE-2015-0556. Via Debian security-traversal-symlink.patch.

--- uxspec.c.orig	2004-04-17 11:39:42.000000000 +0000
+++ uxspec.c
@@ -120,6 +120,58 @@ int query_uxspecial(char FAR **dest, cha
 }
 #endif
 
+#if TARGET==UNIX
+static int is_link_traversal(const char *name)
+{
+  enum {
+    STATE_NONE,
+    STATE_DOTS,
+    STATE_NAME,
+  } state = STATE_NONE;
+  int ndir = 0;
+  int dots = 0;
+
+  while(*name) {
+    int c = *name++;
+
+    if (c == '/')
+    {
+      if ((state == STATE_DOTS) && (dots == 2))
+        ndir--;
+      if (ndir < 0)
+        return 1;
+      if ((state == STATE_DOTS && dots == 1) && ndir == 0)
+        return 1;
+      if (state == STATE_NONE && ndir == 0)
+        return 1;
+      if ((state == STATE_DOTS) && (dots > 2))
+        ndir++;
+      state = STATE_NONE;
+      dots = 0;
+    }
+    else if (c == '.')
+    {
+      if (state == STATE_NONE)
+        state = STATE_DOTS;
+      dots++;
+    }
+    else
+    {
+      if (state == STATE_NONE)
+        ndir++;
+      state = STATE_NAME;
+    }
+  }
+
+  if ((state == STATE_DOTS) && (dots == 2))
+    ndir--;
+  if ((state == STATE_DOTS) && (dots > 2))
+    ndir++;
+
+  return ndir < 0;
+}
+#endif
+
 /* Restores the UNIX special file data */
 
 int set_uxspecial(char FAR *storage, char *name)
@@ -156,6 +208,8 @@ int set_uxspecial(char FAR *storage, cha
      l=sizeof(tmp_name)-1;
     far_memmove((char FAR *)tmp_name, dptr, l);
     tmp_name[l]='\0';
+    if (is_link_traversal(tmp_name))
+      return(UXSPEC_RC_ERROR);
     rc=(id==UXSB_HLNK)?link(tmp_name, name):symlink(tmp_name, name);
     if(!rc)
      return(0);
