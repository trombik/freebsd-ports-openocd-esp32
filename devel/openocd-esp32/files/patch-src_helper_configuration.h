--- src/helper/configuration.h.orig	2024-11-14 10:16:33 UTC
+++ src/helper/configuration.h
@@ -11,6 +11,7 @@
 #ifndef OPENOCD_HELPER_CONFIGURATION_H
 #define OPENOCD_HELPER_CONFIGURATION_H
 
+#include <stdio.h>
 #include <helper/command.h>
 
 int parse_cmdline_args(struct command_context *cmd_ctx,
