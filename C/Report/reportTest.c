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
		char numberOfSeats [ 2 ];
		char payment [ 30 ];
} passenger;
char * p_pN = passenger.name;
char * p_pS = passenger.status;
char * p_nOS = passenger.numberOfSeats;
char * p_pmnt = passenger.payment;
struct payValue payVal = {.half = 19, .discount = 35, .full = 37};
int nameSize = sizeof(passenger.name);
int statusSize = sizeof(passenger.status);
int numberOfSeatsSize = sizeof(passenger.numberOfSeats);
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
                                printf("\n");
                                continue;
                        }
                        if(strInStr(p_b, "свободно")){                  //      Здесь ищем строку с названием автомобиля.
                                p_b = movePointerToChar(p_b, CloseTag, 0);
                                printf("\nЗанято: \t   ");
                                p_b = movePointerToChar(p_b, ',', 1);
                                printf(",");
                                p_b = movePointerToChar(p_b, ',', 1);
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
								printf("%s", passenger.name);
								continue;
							}
						/**************************/      
						if(strIsStatus(p_b)){
								clearString(p_pS, statusSize);
								getContent(p_b, p_pS);
								printf("%s", passenger.status);
								continue;
							}
						/**************************/
						if(strIsNumberOfSeats(p_b)){
								clearString(p_nOS, numberOfSeatsSize);
								getContent(p_b, p_nOS);
								printf("%s", passenger.numberOfSeats);
								continue;
							}
						/**************************/
						if(strIsPayment(p_b)){
								clearString(p_pmnt, paymentSize);
								getContent(p_b, p_pmnt);
								/*fputs(passenger.name, p_fPassDat);
								fputs(passenger.status, p_fPassDat);
								fputs(passenger.numberOfSeats, p_fPassDat);
								fputs(passenger.payment, p_fPassDat);*/
								printf("%s", passenger.payment);
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
