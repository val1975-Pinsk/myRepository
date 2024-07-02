#include <stdio.h>
#include <string.h>
#include "report.h"

struct message messg = { ERR, SUCS } ;
char * fileName = "Водители.html";
char buffer [ 256 ];
char * p_b = buffer;

void main ( void ) {
        printf ( "Открытие файла:\n");
        printf ( "%s\n", fileName ) ;
        FILE * p_f = fopen ( fileName, "r" );
        if ( p_f == NULL ) {
                printf ( "%s", messg.err );
        } else {
                printf ( "%s", messg.sucs );
                //      Чтение строки из файла
                //char * str = "			<td colspan=\"5\">2024-06-16, 17:45, Пинск-Минск</td>";
                char * pattern = "colspan=\"5\"";
                while ((fgets(buffer, 256, p_f)) != NULL){
                        if(strInStr(p_b, pattern)){
                                printf("%s\n", p_b);
                        }//else printf("Pattern not in string!\n");
                                                
                }
        }
}
