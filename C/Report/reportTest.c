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
char * hlf = "17р";
char * dsc = "Д.К.";
char * dsc1 = "Дк";
char * dsc2 = "д.к.";

int strInStrCount(char * str, char * pattern){  //Ln 97
        //printf("from strInStrCount: %s\n", str);
        char * ptn = pattern;
        int count = 0;
        while(*str != '\0'){
                if(*str == *ptn){
                        *(ptn++);
                        if(*ptn == '\0'){
                                count++;
                                ptn = pattern;
                        }
                }else ptn = pattern;
                *(str++);
        }
        //printf("pattern: %s\n", pattern);
        //printf("count: %d\n", count);
        return count;
}

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
                char * endOfReport = "tr height=\"40px\"";
                //char * pattern;
                int go = no;
                int count = 0;
                int total;
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
                                total = charToDigit(p_b);
                                if(total != -1){
                                        count = total;
                                        *(p_b++);
                                }
                                total = charToDigit(p_b);
                                if(total != -1){
                                        count = count * 10 + total;
                                        *(p_b++);
                                }
                                total = count;
                                p_b = movePointerToChar(p_b, ',', 1);
                                printf(",");
                                p_b = movePointerToChar(p_b, ',', 1);
                                printf("\nАвтомобиль: \t  ");
                                p_b = movePointerToChar(p_b, OpenTag, 1);
                                printf("\n");
                                printf("__________________________________________________\n");
                                
                        }
                        if(strInStr(p_b, selected) && strInStr(p_b, "Поехал")){
                                //printf("go!\n");
                                go = yes;
                        }
                        if(strInStr(p_b, colspan_5) && strInStr(p_b, "+")){
                                //int count;
                                p_b = buffer;
                                count = strInStrCount(p_b, "Д.К.");   //Ln 20
                                if(count != 0 && go == yes){
                                        rP.discount += count;
                                }
                                count = strInStrCount(p_b, "Дк");
                                if(count != 0 && go == yes){
                                        rP.discount += count;
                                }
                                count = strInStrCount(p_b, "д.к.");
                                if(count != 0 && go == yes){
                                        rP.discount += count;
                                }
                                count = strInStrCount(p_b, "17р");
                                if(count != 0 && go == yes){
                                        rP.half += count;
                                }
                                count = strInStrCount(p_b, "дк");
                                if(count != 0 && go == yes){
                                        rP.discount += count;
                                }
                                count = strInStrCount(p_b, "бесплатно");
                                if(count != 0 && go == yes){
                                        rP.noCash += count;
                                }
                                count = strInStrCount(p_b, "б/н");
                                if(count != 0 && go == yes){
                                        rP.noCash += count;
                                }
                                go = no;
                        }
                        if(strInStr(p_b, endOfReport)){
                                printf("17р %d человек\n", rP.half);
                                printf("30р %d человек\n", rP.discount);
                                rP.full = total - (rP.half + rP.discount + rP.noCash);
                                printf("35р %d человек\n", rP.full);
                                printf("б/н или без оплаты %d человек\n", rP.noCash);
                                rP.full = 0;
                                rP.discount = 0;
                                rP.noCash = 0;
                                rP.half = 0;
                        }
                }
        }
}
