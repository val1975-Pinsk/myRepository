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
                char * width_25 = "width=\"25px\"";
                //char * pattern;
                int go = no;
                int count = 0;
                int digit;
                while ((fgets(buffer, 256, p_f)) != NULL){
                        p_b = buffer;
                        //go = no;
                        if(strInStr(p_b, "Пинск")){           //Здесь ищем строку с названием маршрута."
                                printf("==================================================\n");
                                //Перемещаем указатель к началу содержимого строки/
                                p_b = movePointerToChar(p_b, CloseTag, 0);
                                printf("Дата: \t\t   ");
                                p_b = movePointerToChar(p_b, ',', 1);
                                printf("\nВремя отправления:");
                                p_b = movePointerToChar(p_b, ',', 1);
                                printf("\nМаршрут: \t  ");
                                p_b = movePointerToChar(p_b, OpenTag, 1);
                        }
                        if(strInStr(p_b, "свободно")){        //Здесь ищем строку с названием автомобиля.
                                p_b = movePointerToChar(p_b, CloseTag, 0);
                                printf("\nЗанято: \t   ");
                                //конвертируем количество занятых мест в числовое выражение.
                                digit = charToDigit(p_b);
                                if(digit != -1){
                                        count = digit;
                                        *(p_b++);
                                }
                                digit = charToDigit(p_b);
                                if(digit != -1){
                                        count = count * 10 + digit;
                                        *(p_b++);
                                }
                                p_b = movePointerToChar(p_b, ',', 1);
                                printf(",");
                                p_b = movePointerToChar(p_b, ',', 1);
                                printf("\nАвтомобиль: \t  ");
                                p_b = movePointerToChar(p_b, OpenTag, 1);
                                printf("\n");
                                printf("__________________________________________________\n");
//                                printf("Поехало %d\n", count);
                        }
                        if(strInStr(p_b, selected) && strInStr(p_b, "Поехал")){
                                printf("go!\n");
                                go = yes;
                        }
                        /*if(strInStr(p_b, "дк") && go == yes){
                                printf("%s", p_b);
                        }*/
                        if(strInStr(p_b, colspan_5) && strInStr(p_b, "+")){
                                p_b = movePointToChar(p_b, CloseTag);
                                
                        }
                }
        }
}
