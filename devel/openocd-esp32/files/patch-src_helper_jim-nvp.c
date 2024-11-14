--- src/helper/jim-nvp.c.orig	2024-11-14 10:18:57 UTC
+++ src/helper/jim-nvp.c
@@ -21,6 +21,7 @@
 #endif
 
 #include "jim-nvp.h"
+#include <stdio.h>
 #include <string.h>
 
 int jim_get_nvp(Jim_Interp *interp,
