#include <stdio.h>
#include <string.h>
#include "report.h"

struct message messg = { ERR, SUCS };
struct reportPass {
        int half;
        int discount;
        int full;
        int noCash;
};
char * fileName = "Водители.html";
char buffer [ 256 ];
char * p_b;

void main ( void ) {
        printf ( "Открытие файла:\n");
        printf ( "%s\n", fileName ) ;
        FILE * p_f = fopen ( fileName, "r" );                                   //Открываем файл.
        if ( p_f == NULL ) {
                printf ( "%s", messg.err );
        } else {
                printf ( "%s", messg.sucs );
                struct reportPass rP = {.half = 0, .discount = 0, .full = 0, .noCash = 0};
                char * colspan_5 = "colspan=\"5\"";
                char * selected = "selected=\"selected\"";
                char * pattern;
                int go;
                while ((fgets(buffer, 256, p_f)) != NULL){
                        p_b = buffer;
                        go = no;
                        if(strInStr(p_b, colspan_5)){
                                //Здесь ищем строку с названием маршрута."
                                if(strInStr(p_b, pattern = "Пинск")){
                                        //rP = {.half = 0, .discount = 0, .full = 0, .noCash = 0};
                                        printf("==================================================\n");
                                        //Перемещаем указатель к началу содержимого строки/
                                        p_b = movePointerToChar(p_b, CloseTag, 0);
                                        printf("Дата: \t\t   ");
                                        p_b = movePointerToChar(p_b, ',', 1);
                                        printf("\nВремя отправления:");
                                        p_b = movePointerToChar(p_b, ',', 1);
                                        printf("\nМаршрут: \t  ");
                                        p_b = movePointerToChar(p_b, OpenTag, 1);
                                        //printf("\n");
                                }
                                //Здесь ищем строку с названием автомобиля.
                                if(strInStr(p_b, pattern = "свободно")){
                                        p_b = movePointerToChar(p_b, CloseTag, 0);
                                        printf("\nЗанято: \t   ");
                                        p_b = movePointerToChar(p_b, ',', 1);
                                        printf(",");
                                        p_b = movePointerToChar(p_b, ',', 1);
                                        printf("\nАвтомобиль: \t  ");
                                        p_b = movePointerToChar(p_b, OpenTag, 1);
                                        printf("\n");
                                        printf("__________________________________________________\n");
                                        //printf("\n");
                                }
                                if(strInStr(p_b, pattern = "Дк")){
                                        printf("Дк\n");
                                        rP.discount += 1;
                                        printf("%d\n", rP.discount);
                                }
                        }
                        if(strInStr(p_b, pattern = selected) && strInStr(p_b, pattern = "Поехал")){
                                go = yes;
                        }
                                                
                }
        }
}
