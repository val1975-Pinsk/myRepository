#include <stdio.h>
#include <string.h>
#include "report.h"

char strBuff[ 256 ];
int count, digit;                             // 
char * p_b;                            // Указатель на strBuff
char * fileName = "Водители.html";
//char * filePassData = "passenger.txt";
struct{
		char name [ 120 ];
		char status [ 20 ];
		char payment [ 30 ];
} passenger;
char * p_pN = passenger.name;
char * p_pS = passenger.status;
char * p_pmnt = passenger.payment;

struct PayValue payVal = {.half = 19, .discount = 35, .full = 37};
struct PayReport payRep = {.half = 0, .discount = 0, .full = 0, .noCash = 0};
struct Total total = {.half = 0, .discount = 0, .full = 0};

int nameSize = sizeof(passenger.name);
int statusSize = sizeof(passenger.status);
int paymentSize = sizeof(passenger.payment);

int main(){

		
		/****************************/
		/* Процедура открытия файла */

		printf(OPENING);
		printf("%s\n", fileName);
		FILE * p_f = fopen ( fileName, "r" );
		//FILE * p_fPassDat = fopen ( filePassData, "a");
		
		/*   Конец процедуры        */
		/****************************/

		/****************************/
		/* Обработка ошибки открытия*/
	  
		if ( p_f == NULL ) {
				printf("File open whith error! :(\n");
		
		/* Конец обработки ошибки   */
		/****************************/
		} else {
		/* */
				printf("File is open :)\n");
				while ((fgets(strBuff, 256, p_f)) != NULL){
						p_b = strBuff;
						
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
                                digit = charToDigit(p_b);
                                if(digit != -1) payRep.full = digit;
                                p_b += 1;
                                digit = charToDigit(p_b);
                                if(digit != -1){
										payRep.full = payRep.full * 10 + digit;
									}
                                printf("%d", payRep.full);
                                p_b = movePointerToChar(p_b, ',', 0);
                                p_b = movePointerToChar(p_b, ',', 0);
                                printf("\nАвтомобиль: \t  ");
                                p_b = movePointerToChar(p_b, OpenTag, 1);
                                printf("\n");
                                printf("__________________________________________________\n");
                                continue;
                                
                        }
						/**************************/
						if(strIsName(p_b)){
								clearString(p_pN, nameSize);
								getContent(p_b, p_pN);
								continue;
							}
						/**************************/      
						if(strIsStatus(p_b)){
								clearString(p_pS, statusSize);
								getContent(p_b, p_pS);
								continue;
							}
						/**************************/
						/*if(strIsNumberOfSeats(p_b)){
								clearString(p_nOS, numberOfSeatsSize);
								getContent(p_b, p_nOS);
								printf("%s", passenger.numberOfSeats);
								continue;
							}*/
						/**************************/
						if(strIsPayment(p_b)){
								clearString(p_pmnt, paymentSize);
								getContent(p_b, p_pmnt);
								if(strInStr(passenger.status, "Поехал")){
										payRep.discount = payRep.discount + getDiscountCount(passenger.payment);
										payRep.noCash = payRep.noCash + getNoCashCount(passenger.payment);
									}
							}
						/**************************/
						if(isEndOfReport(p_b)){
								if(payRep.full != 0){
										payRep.full = payRep.full - payRep.discount - payRep.noCash;
										total.discount = payRep.discount * payVal.discount;
										total.full = payRep.full * payVal.full;
										printf("По безналу      \t%d\n", payRep.noCash);
										printf("По дисконту     \t%d\t%d\n", payRep.discount, total.discount);
										printf("Полная стоимость\t%d\t%d\n", payRep.full, total.full);
										printf("Итого           \t\t%d\n", total.discount + total.full);
										payRep.half = 0;
										payRep.discount = 0;
										payRep.full = 0;
										payRep.noCash = 0;
									}
							}
				}
		}
		printf("\nЗакрываю файл\n");
		if ( fclose (p_f) == EOF){
				printf ("ошибка :(\n");
		} else printf ("выполнено :)\n");
		//fclose (p_fPassDat);
		return 1; // Конец программы.
}
