# $NetBSD: Makefile,v 1.19 2021/02/07 12:38:29 adam Exp $

DISTNAME=	python-stdnum-1.16
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-stdnum/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://arthurdejong.org/python-stdnum
COMMENT=	Python module to handle standardized numbers and codes
LICENSE=	gnu-lgpl-v3

TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	nosetests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
