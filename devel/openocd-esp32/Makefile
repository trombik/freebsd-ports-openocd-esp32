PORTNAME=	openocd-esp32
PORTVERSION=	20210721
CATEGORIES=	devel

MAINTAINER=	y@trombik.org
COMMENT=	Open On-Chip Debugger for ESP32

LICENSE=	GPLv2

LIB_DEPENDS=		libftdi.so:devel/libftdi

USES=		gmake libtool makeinfo pkgconfig autoreconf
USE_GITHUB=	yes
USE_GITLAB=	yes
GH_TUPLE=	\
	msteveb:jimtcl:${OCDESP_JIMTCL_GITREF}:jimtcl_group/jimtcl \
	espressif:openocd-esp32:v0.10.0-esp32-${PORTVERSION}

# XXX undocumented feature, `nodefault`, in bsd.sites.mk
USE_GITLAB=	nodefault
GL_TUPLE=	https://gitlab.zapb.de:libjaylink:libjaylink:${OCDESP_LIBJAYLINK_GITREF}:libjaylink/src/jtag/drivers/libjaylink
GNU_CONFIGURE=	yes

# see https://github.com/espressif/openocd-esp32/blob/master/.gitlab-ci.yml
OCDESP_CONFIGURE_ARGS=	\
	--disable-doxygen-html --disable-doxygen-pdf --enable-ftdi --enable-jlink --enable-ulink
CONFIGURE_ARGS=	\
				${OCDESP_CONFIGURE_ARGS} \
				--disable-werror
OCDESP_JIMTCL_GITREF=	0aa0fb4
# XXX commit ref in GL_TUPLE must be full ref, not short one
OCDESP_LIBJAYLINK_GITREF=	f73ad5e667ae8b26a52b847c603fdadaabf302a6
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -Wno-error
INFO=	openocd-esp32
SUB_FILES=	pkg-message
SUB_LIST=	DOCSDIR=${DOCSDIR}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/openocd ${STAGEDIR}${PREFIX}/bin/openocd-esp32
	${MV} ${STAGEDIR}${PREFIX}/man/man1/openocd.1 ${STAGEDIR}${PREFIX}/man/man1/openocd-esp32.1
.for F in info info-1 info-2
	${MV} ${STAGEDIR}${PREFIX}/share/info/openocd.${F} ${STAGEDIR}${PREFIX}/share/info/openocd-esp32.${F}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/espressif.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
