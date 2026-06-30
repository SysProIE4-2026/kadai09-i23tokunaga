/*
 *  myenv.c : env コマンドのクローン
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*#ifdef __linux__*/
#include "myputenv.h"
/*#endif*/
extern char **environ;


int main(int argc, char *argv[])
{
    int i;
    char **env;
    for (i = 1; i < argc; i++) {
        if (_putenv(argv[i]) == -1) {
            execvp(argv[i], &argv[i]);
            perror("execvp");
            return 1;
        }
    }
    
    for (env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }

    return 0;
}

/* 実行例

ここに実行例を書く
tokunagataisei@tokunagadaishizukanoMacBook-Pro kadai09-i23tokunaga % ./myenv A=100 ls
Makefile	README.pdf	myenv.c		myputenv.h
README.md	myenv		myputenv.c
tokunagataisei@tokunagadaishizukanoMacBook-Pro kadai09-i23tokunaga % ./myenv A=100 ls -l
total 384
-rw-r--r--  1 tokunagataisei  staff     132  6 30 09:02 Makefile
-rw-r--r--  1 tokunagataisei  staff    1268  6 30 09:02 README.md
-rw-r--r--  1 tokunagataisei  staff  139098  6 30 09:02 README.pdf
-rwxr-xr-x  1 tokunagataisei  staff   33328  6 30 09:33 myenv
-rw-r--r--@ 1 tokunagataisei  staff     583  6 30 09:32 myenv.c
-rwxr-xr-x@ 1 tokunagataisei  staff     216  6 30 09:02 myputenv.c
-rw-r--r--  1 tokunagataisei  staff      93  6 30 09:02 myputenv.h
tokunagataisei@tokunagadaishizukanoMacBook-Pro kadai09-i23tokunaga % ./myenv LC_TIME=ja_JP.UTF-8 TZ=Cuba ls -l
total 384
-rw-r--r--  1 tokunagataisei  staff     132  6 29 20:02 Makefile
-rw-r--r--  1 tokunagataisei  staff    1268  6 29 20:02 README.md
-rw-r--r--  1 tokunagataisei  staff  139098  6 29 20:02 README.pdf
-rwxr-xr-x  1 tokunagataisei  staff   33328  6 29 20:33 myenv
-rw-r--r--@ 1 tokunagataisei  staff     583  6 29 20:32 myenv.c
-rwxr-xr-x@ 1 tokunagataisei  staff     216  6 29 20:02 myputenv.c
-rw-r--r--  1 tokunagataisei  staff      93  6 29 20:02 myputenv.h
tokunagataisei@tokunagadaishizukanoMacBook-Pro kadai09-i23tokunaga % ./myenv A=100 aaa
execvp: No such file or directory
tokunagataisei@tokunagadaishizukanoMacBook-Pro kadai09-i23tokunaga % 

*/
