# $NetBSD: Makefile,v 1.20 2021/05/24 19:55:41 wiz Exp $

DISTNAME=	Kwiki-ModPerl-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki integration with ModPerl

DEPENDS+=	p5-Kwiki>=0.38:../../www/p5-Kwiki

PERL5_PACKLIST=		auto/Kwiki/ModPerl/.packlist

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../mk/apache.mk"
.include "../../www/ap2-perl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
