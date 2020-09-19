--- src/jtag/drivers/bitbang.h.orig	2020-07-06 11:28:07 UTC
+++ src/jtag/drivers/bitbang.h
@@ -57,7 +57,7 @@ struct bitbang_interface {
 	void (*swdio_drive)(bool on);
 };
 
-const struct swd_driver bitbang_swd;
+extern const struct swd_driver bitbang_swd;
 
 extern bool swd_mode;
 
