PORTNAME=	openocd-esp32
PORTVERSION=	20241016
CATEGORIES=	devel

MAINTAINER=	y@trombik.org
COMMENT=	Open On-Chip Debugger for ESP32

LICENSE=	GPLv2

LIB_DEPENDS=		libftdi1.so:devel/libftdi1

USES=		gmake libtool makeinfo pkgconfig autoreconf:build
USE_GITHUB=	yes
USE_GITLAB=	yes
OPENOCD_VERSION=	0.12.0
GH_TUPLE=	\
	msteveb:jimtcl:${OCDESP_JIMTCL_GITREF}:jimtcl_group/jimtcl \
	espressif:openocd-esp32:v${OPENOCD_VERSION}-esp32-${PORTVERSION}

# XXX undocumented feature, `nodefault`, in bsd.sites.mk
USE_GITLAB=	nodefault
GL_TUPLE=	https://gitlab.zapb.de:libjaylink:libjaylink:${OCDESP_LIBJAYLINK_GITREF}:libjaylink/src/jtag/drivers/libjaylink
GNU_CONFIGURE=	yes
# use ${LOCALBASE}/${PORTNAME} as PREFIX like xtensa-esp32-elf.
PREFIX=	${LOCALBASE}/${PORTNAME}

# see https://github.com/espressif/openocd-esp32/blob/master/.gitlab-ci.yml
OCDESP_CONFIGURE_ARGS=	\
	--disable-doxygen-html \
	--enable-remote-bitbang

OCDESP_CONFIGURE_ARGS+=	--enable-internal-libjaylink
CONFIGURE_ARGS=	\
				${OCDESP_CONFIGURE_ARGS} \
				--disable-werror
OCDESP_JIMTCL_GITREF=	f160866

# see openocd-esp32/.gitmodules.
# XXX commit ref in GL_TUPLE must be full ref, not short one
OCDESP_LIBJAYLINK_GITREF=	f73ad5e667ae8b26a52b847c603fdadaabf302a6
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -Wno-error
INFO=	openocd-esp32
SUB_FILES=	pkg-message
SUB_LIST=	DOCSDIR=${DOCSDIR}

pre-configure:
	${REINPLACE_CMD} \
		-e 's|%%OPENOCD_VERSION%%|${OPENOCD_VERSION}|g' \
		${WRKSRC}/configure.ac
	(cd ${WRKSRC} && ${SETENV} SKIP_SUBMODULE=y ${SH} ./bootstrap)

post-install:
.for F in info info-1 info-2
	${MV} ${STAGEDIR}${PREFIX}/share/info/openocd.${F} ${STAGEDIR}${PREFIX}/share/info/openocd-esp32.${F}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/espressif.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
