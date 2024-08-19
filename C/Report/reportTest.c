#include <stdio.h>
#include <string.h>
#include "report.h"

struct message messg = { ERR, SUCS };
struct reportPass rPCount = {.half = 0, .discount = 0, .full = 0, .noCash = 0};

char * fileName = "Водители.html";
char buffer [ buffSize ];
char noCashList[ 5 ][ buffSize ];
char * p_b;
char * colspan_5 = "colspan=\"5\"";
char * selected = "selected=\"selected\"";
char * width_25 = "width=\"25px\"";
char * endOfReport = "tr height=\"40px\"";
char * bgColorWhite = "bgcolor=\"white\""; // bgcolor="white"
int prevColorWhite = no;
int go = no;
int count = 0;
int total;

int main () {
        printf ( "Открытие файла:\n");
        printf ( "%s\n", fileName ) ;
        FILE * p_f = fopen ( fileName, "r" );                           //      Открываем файл.
        if ( p_f == NULL ) {
                printf ( "%s", messg.err );
        } else {
                printf ( "%s", messg.sucs );
                
                while ((fgets(buffer, buffSize, p_f)) != NULL){
                        p_b = buffer;
                        if(strInStr(p_b, "Пинск")){                     //      Здесь ищем строку с названием маршрута.
			  printHeaderPart_1(p_b);
                          continue;
                        }
                        if(strInStr(p_b, "свободно")){                  //      Здесь ищем строку с названием автомобиля.
                          total = printHeaderPart_2(p_b);
                          continue;
                                
                        }
                        if(strInStr(p_b, bgColorWhite)){
                                prevColorWhite = yes;
                                continue;
                        }
			// if(strInStr(p_b, colspan_5) && prevColorWhite == yes){
			if(strIsPayment(p_b) && prevColorWhite == yes){
                        /*
                                bug_0
                          ====================================================
                          Здесь может быть косяк. Не всегда ставят плюсик!!!
                          if(strInStr(p_b, colspan_5) && strInStr(p_b, "+")){}
                        */
                                p_b = buffer;
                                prevColorWhite = no;
                                go = no;
				rPCount.discount += getDiscountCount(p_b);
				count = strInStrCount(p_b, "17р");
                                rPCount.half += count;
                                rPCount.noCash += getNoCashCount(p_b);
                                continue;
                        }
                        if(strInStr(p_b, endOfReport)){                 //      Подводим итоги.
                                printf("%d человек за 17р, сумма %d рублей\n", rPCount.half, rPCount.half * 17);
                                printf("%d человек за 30р, сумма %d рублей\n", rPCount.discount, rPCount.discount * 30);
                                rPCount.full = total - (rPCount.half + rPCount.discount + rPCount.noCash);
                                printf("%d человек за 35р, сумма %d рублей\n", rPCount.full, rPCount.full * 35);
                                printf("%d человек по б/н или без оплаты\n", rPCount.noCash);
                                printf("\n\tИтого: %d рублей.\n", rPCount.half * 17 + rPCount.discount * 30 + rPCount.full * 35);
                                rPCount.full = 0;
                                rPCount.discount = 0;
                                rPCount.noCash = 0;
                                rPCount.half = 0;
                        }
                }
        }
}
