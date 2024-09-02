#include <stdio.h>
#include <string.h>
#include "report.h"

char strBuff[ 256 ];
char listPass [ 600 ];                 // Список пассажиров оплативших проезд по безналу
int i = 0;                             // Порядковый номер строки в массиве listPass
char * p_lP = listPass;                // Указатель на начало списка пассажиров
char * p_b;                            // Указатель на strBuff
char * fileName = "Водители.html";

struct{
		char name [ 120 ];
		char status [ 20 ];
		char numberOfSeats [ 2 ];
		char payment [ 50 ];
} passenger;

char * p_pN = passenger.name;
char * p_pS = passenger.status;
char * p_nOS = passenger.numberOfSeats;
char * p_pmnt = passenger.payment;
int nameSize = 120;
int statusSize = 20;
int numberOfSeatsSize = 2;
int paymentSize = 50;

int main(){

		
		/****************************/
		/* Процедура открытия файла */

		printf("Opening file...");
		printf("%s\n", fileName);
		FILE * p_f = fopen ( fileName, "r" );

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
								printf("%s", passenger.payment);
								continue;
							}
				}
		}
	  //printf("%s", listPass);
	  //  printf("%s", p_lP);
		printf("\nЗакрываю файл\n");
		if ( fclose (p_f) == EOF){
				printf ("ошибка :(\n");
		} else printf ("выполнено :)\n");
		return 1; // Конец программы.
}
