# $NetBSD: Makefile,v 1.10 2021/04/21 08:54:35 wiz Exp $

DISTNAME=	ack139
PKGNAME=	ack-1.39
PKGREVISION=	1
CATEGORIES=	japanese converters
MASTER_SITES=	# ftp://ftp.tohoku.ac.jp/pub/unix/ack/

MAINTAINER=	kei_sun@ba2.so-net.ne.jp
COMMENT=	Japanese code converter

BUILD_TARGET=	ack

INSTALLATION_DIRS=	bin ${PKGMANDIR}/ja_JP.eucJP/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ack ${DESTDIR}${PREFIX}/bin/ack
	${INSTALL_DATA} ${WRKSRC}/ack.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/ja_JP.eucJP/man1/ack.1

.include "../../mk/bsd.pkg.mk"
