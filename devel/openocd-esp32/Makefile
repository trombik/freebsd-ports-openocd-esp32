# $FreeBSD:$

PORTNAME=	openocd-esp32
PORTVERSION=	20210401
CATEGORIES=	devel

MAINTAINER=	y@trombik.org
COMMENT=	Open On-Chip Debugger for ESP32

LICENSE=	GPLv2

LIB_DEPENDS=		libftdi.so:devel/libftdi

USES=		gmake libtool makeinfo pkgconfig autoreconf
USE_GITHUB=	yes
GH_TUPLE=	espressif:openocd-esp32:v0.10.0-esp32-${PORTVERSION} \
	msteveb:jimtcl:0.77:jimtcl/jimtcl \
	syntacore:libjaylink:835e45b:libjaylink/src/jtag/drivers/libjaylink

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	\
				--disable-werror \
				--disable-doxygen-html \
				--disable-doxygen-pdf \
				--enable-internal-jimtcl \
				--enable-ftdi \
				--enable-jlink \
				--enable-ulink

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -Wno-error
INFO=	openocd-esp32

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/openocd ${STAGEDIR}${PREFIX}/bin/openocd-esp32
	${MV} ${STAGEDIR}${PREFIX}/man/man1/openocd.1 ${STAGEDIR}${PREFIX}/man/man1/openocd-esp32.1
.for F in info info-1 info-2
	${MV} ${STAGEDIR}${PREFIX}/share/info/openocd.${F} ${STAGEDIR}${PREFIX}/share/info/openocd-esp32.${F}
.endfor

.include <bsd.port.mk>
