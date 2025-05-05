#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "report.h"

/**/

int main(){
	struct DirectReport curent_report = {.done = 0, .places_occupied = 0, .halfcost = 0, .discount = 0, .nocost = 0};
	struct Length len = {.buffer = 256, .myDate = 10, .directName = 21, .myTime = 5};
	struct Payment pay = {.fullcost = 37, .discount = 35, .halfcost = 17}; 
	char* p_strstr;
	int fullcost = 0, discount = 0, nocost = 0;
	int count = 0, total_count = 0;
	char* p_strBuff = getMallocCharBuff(len.buffer);
	if(p_strBuff == NULL){
		return 0;
	}
	curent_report.date = getMallocCharBuff(len.myDate);
	if(curent_report.date == NULL){
		return 0;
	}
	curent_report.name = getMallocCharBuff(len.directName);
	if(curent_report.name == NULL){
		return 0;
	}
	curent_report.time = getMallocCharBuff(len.myTime);
	if(curent_report.name == NULL){
		return 0;
	}
	printf("Открывается файл \"Водители.html\"...\n");
	FILE* p_f = fopen("Водители.html", "r");
	if(p_f == NULL){
		printf("Ошибка открытия файла!\nПрограмма остановлена.\n");
		return 0;
	}
	printf("Файл открыт...\nОбработка...\n");
	while(1){
		if(fgets(p_strBuff, len.buffer, p_f) == NULL) return 1;
		if(strstr(p_strBuff, "Пинск") != NULL){
			if(curent_report.done == 0){
				creatHeader(p_strBuff, &curent_report, &len);
			}else{
				printHeader(&curent_report, &pay);
				creatHeader(p_strBuff, &curent_report, &len);
			}
			continue;
		}
		/*	Выясняем количество забронированных мест.  */
		if(strstr(p_strBuff, "width=\"25px\"") != NULL){
			count = getCount(p_strBuff);
			continue;
		}
		/*	Статус - поехал или нет.  */
		if(strstr(p_strBuff, "selected=\"selected\"") != NULL){
			if(getStatus(p_strBuff) == 1){
				curent_report.places_occupied += count;
				/*	Выясняем оплату.*/
				while(1){
					fgets(p_strBuff, len.buffer, p_f);
					if(strstr(p_strBuff, "colspan=\"5\"") != NULL){
						curent_report.discount += getDiscountCount(p_strBuff);
						curent_report.halfcost += strInStrCount(p_strBuff, "17р");
						curent_report.nocost += getNoCostCount(p_strBuff);
						break;
					}
				}
			}
			continue;
		}
		/*	КОНЕЦ  */
		if(strstr(p_strBuff, "</html>") != NULL){
			printHeader(&curent_report, &pay);
		}
	}
	return 1;
}

