# $NetBSD: Makefile,v 1.12 2020/11/28 01:20:03 gutteridge Exp $
#

DISTNAME=	xhtml1
PKGNAME=	xhtml-1.0
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.w3.org/TR/xhtml1/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.w3.org/MarkUp/
COMMENT=	DTDs for the Extensible Hypertext Markup Language

NO_BUILD=	yes
USE_LANGUAGES=	# empty
USE_TOOLS+=	pax
WRKSRC=		${WRKDIR}/xhtml1-20020801

SGML_CATALOGS=	${PREFIX}/share/xml/xhtml/1.0/xhtml.soc
XML_CATALOGS=	${PREFIX}/share/xml/xhtml/1.0/catalog

INSTALLATION_DIRS=	share/xml/xhtml/1.0

do-install:
	cd ${WRKSRC}/DTD && pax -rwppm . ${DESTDIR}${PREFIX}/share/xml/xhtml/1.0
	${INSTALL_DATA} ${FILESDIR}/catalog10 \
	    ${DESTDIR}${PREFIX}/share/xml/xhtml/1.0/catalog

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
