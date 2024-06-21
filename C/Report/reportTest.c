#include <stdio.h>
#include <string.h>
#include "report.h"

struct message messg = { ERR, SUCS } ;
char * fileName = "Водители.html" ;
char string [ 200 ] ;
char *p_string ;

void main ( void ) {
        printf ( "Открытие файла:\n");
        printf ( "%s\n", fileName ) ;
        FILE *p_f = fopen ( fileName, "r" ) ;
        if ( p_f == NULL ) {
                printf ( "%s", messg.err ) ;
        } else {
                printf ( "%s", messg.sucs ) ;
                //      Чтение строки из файла
                p_string = fgets ( string, sizeof ( string ), p_f ) ;
                printf ( "%s", p_string ) ;
        }
}
