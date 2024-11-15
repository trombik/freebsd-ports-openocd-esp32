--- guess-rev.sh.orig	2024-11-15 11:04:51 UTC
+++ guess-rev.sh
@@ -52,4 +52,4 @@ fi
 fi
 
 # There's no recognized repository; we must be a snapshot.
-printf -- '-snapshot'
+printf -- '-esp32-%%PORTVERSION%%'
