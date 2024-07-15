#include <stdio.h>
#include <string.h>
#include "report.h"

struct message messg = { ERR, SUCS };
struct reportPass rPCount = {.half = 0, .discount = 0, .full = 0, .noCash = 0};

char * fileName = "Водители.html";
char buffer [ buffSize ];
char list [5][ buffSize ];                                              //      Список оплативших по безналу.
//int listPos = 0;                                                       //      Позиция строки в списке list.
char * p_b;
char * p_l = list[0];
char * colspan_5 = "colspan=\"5\"";                                     //      Паттерны.
char * colspan_3 = "colspan=\"3\"";                                     //
char * selected = "selected=\"selected\"";                              //
char * width_25 = "width=\"25px\"";                                     //
char * endOfReport = "tr height=\"40px\"";                              //
int go = no;
int count = 0;
int total;

void main ( void ) {
        printf ( "Открытие файла:\n");
        printf ( "%s\n", fileName ) ;
        FILE * p_f = fopen ( fileName, "r" );                           //      Открываем файл.
        if ( p_f == NULL ) {
                printf ( "%s", messg.err );
        } else {
                printf ( "%s", messg.sucs );
                
                while ((fgets(buffer, 256, p_f)) != NULL){
                        p_b = buffer;
                        if(strInStr(p_b, "Пинск")){                     //      Здесь ищем строку с названием маршрута.
                                printf("==================================================\n");
                                //Перемещаем указатель к началу содержимого строки/
                                p_b = movePointerToChar(p_b, CloseTag, 0);
                                printf("Дата: \t\t   ");
                                p_b = movePointerToChar(p_b, ',', 1);
                                printf("\nВремя отправления:");
                                p_b = movePointerToChar(p_b, ',', 1);
                                printf("\nМаршрут: \t  ");
                                p_b = movePointerToChar(p_b, OpenTag, 1);
                                continue;
                        }
                        if(strInStr(p_b, "свободно")){                  //      Здесь ищем строку с названием автомобиля.
                                p_b = movePointerToChar(p_b, CloseTag, 0);
                                printf("\nЗанято: \t   ");
                                total = charToDigit(p_b);               //      Конвертируем количество занятых 
                                if(total != -1){                        //мест в числовое выражение.
                                        count = total;                  //
                                        *(p_b++);                       //
                                }                                       //
                                total = charToDigit(p_b);               //
                                if(total != -1){                        //
                                        count = count * 10 + total;     //
                                        *(p_b++);                       //
                                }                                       //
                                total = count;                          //
                                p_b = movePointerToChar(p_b, ',', 1);
                                printf(",");
                                p_b = movePointerToChar(p_b, ',', 1);
                                printf("\nАвтомобиль: \t  ");
                                p_b = movePointerToChar(p_b, OpenTag, 1);
                                printf("\n");
                                printf("__________________________________________________\n");
                                continue;
                                
                        }
                        if(strInStr(p_b, colspan_3)){
                                addStr(p_b, p_l, CloseTag, OpenTag);
                        }
                        if(strInStr(p_b, selected) && strInStr(p_b, "Поехал")){
                                go = yes;
                                continue;
                        }
                        if(strInStr(p_b, colspan_5) && strInStr(p_b, "+")){
                                p_b = buffer;
                                if(go == yes){
                                        count = strInStrCount(p_b, "Д.К.");
                                        rPCount.discount += count;
                                        count = strInStrCount(p_b, "Дк");
                                        rPCount.discount += count;
                                        count = strInStrCount(p_b, "д.к.");
                                        rPCount.discount += count;
                                        count = strInStrCount(p_b, "дк");
                                        rPCount.discount += count;
                                        count = strInStrCount(p_b, "17р");
                                        rPCount.half += count;
                                        count = strInStrCount(p_b, "бесплатно");
                                        rPCount.noCash += count;
                                        count = strInStrCount(p_b, "б/н");
                                        rPCount.noCash += count;
                                        count = strInStrCount(p_b, "безнал");
                                        rPCount.noCash += count;
                                        if(count != 0){
                                                *(p_l += buffSize);
                                        }
                                }
                                go = no;
                                continue;
                        }
                        if(strInStr(p_b, endOfReport)){                 //      Подводим итоги.
                                printf("%d человек за 17р, сумма %d рублей\n", rPCount.half, rPCount.half * 17);
                                printf("%d человек за 30р, сумма %d рублей\n", rPCount.discount, rPCount.discount * 30);
                                rPCount.full = total - (rPCount.half + rPCount.discount + rPCount.noCash);
                                printf("%d человек за 35р, сумма %d рублей\n", rPCount.full, rPCount.full * 35);
                                printf("%d человек по б/н или без оплаты\n", rPCount.noCash);
                                if(rPCount.noCash != 0){
                                        p_l = list[0];
                                        printf("\t%s", p_l);              
                                }
                                printf("\n\tИтого: %d рублей.\n", rPCount.half * 17 + rPCount.discount * 30 + rPCount.full * 35);
                                rPCount.full = 0;
                                rPCount.discount = 0;
                                rPCount.noCash = 0;
                                rPCount.half = 0;
                        }
                }
        }
}
