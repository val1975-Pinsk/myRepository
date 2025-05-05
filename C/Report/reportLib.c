# include <stdio.h>
# include <string.h>
# include <stlib.h>
# include "report.h"


/**/
char* getMallocCharBuff(int sizeBuff){
	printf("Выделение %d байт памяти...\n", sizeBuff);
	char* strBuff = (char*)malloc(sizeBuff * sizeof(char));
	if(strBuff == NULL){
		printf("Ошибка выделения памяти!\nПрограмма будет остановлена.\n");
	}
	return strBuff;
};
/**/
void printHeader(struct DirectReport* dr, struct Payment* pay){
	//dr->done = 0;
	printf("=============================\nДата \t\t  %s\n", dr->date);
	printf("Направление       %s\n", dr->name);
	printf("Время отправления %s\n=============================\n", dr->time);
	printf("Всего поехало         %d\n", dr->places_occupied);
	printf("За полную стоимость   %d\n", dr->places_occupied - (dr->discount - dr->halfcost - dr->nocost));
	printf("По дисконту           %d\n", dr->discount);
	printf("За полстоимости       %d\n", dr->halfcost);
	printf("По безналу            %d\n", dr->nocost);
	printf("-----------------------------\n");
	printf("Итого:\n");
	printf("	за полную стоимость  \%d рублей;\n", (dr->places_occupied - (dr->discount - dr->halfcost - dr->nocost))*pay->fullcost);
	printf("	по дисконту          \%d рублей;\n", dr->discount*pay->discount);
	printf("	за полстоимости      \%d рублей;\n", dr->halfcost*pay->halfcost);
	printf("\nВсего за рейс \%d рублей.\n\n", dr->discount*pay->discount + dr->halfcost*pay->halfcost + (dr->places_occupied - (dr->discount - dr->halfcost - dr->nocost))*pay->fullcost);
	dr->discount = 0;
	dr->halfcost = 0;
	dr->nocost = 0;
};
/**/
void creatHeaderPM(char* p_strBuff, struct DirectReport* PM, struct Length* Len){
		strncpy(PM->name, "Пинск-Минск", Len->directName);
		char* p_strstr = strchr(p_strBuff, '>')+1;
		strncpy(PM->date, p_strstr, Len->myDate);
		p_strstr = strchr(p_strstr, ',')+2;
		strncpy(PM->time, p_strstr, Len->myTime);
		PM->done = 1;
};
/**/
void creatHeaderMP(char* p_strBuff, struct DirectReport* MP, struct Length* Len){
		printf("Функция creatHeaderMP \%s\n", p_strBuff);
		strncpy(MP->name, "Минск-Пинск", Len->directName);	
		char* p_strstr = strchr(p_strBuff, '>')+1;
		strncpy(MP->date, p_strstr, Len->myDate);
		p_strstr = strchr(p_strstr, ',')+2;
		strncpy(MP->time, p_strstr, Len->myTime);
		MP->done = 1;
};
/**/
void creatHeader(char* p_strBuff, struct DirectReport* curent_report, struct Length* Len){
	char* p_strstr = strchr(p_strBuff, '>')+1;
	strncpy(curent_report->date, p_strstr, Len->myDate);
	p_strstr = strchr(p_strstr, ',')+2;
	strncpy(curent_report->time, p_strstr, Len->myTime);
	p_strstr = strchr(p_strstr, ',')+2;
	strncpy(curent_report->name, p_strstr, Len->directName);
	curent_report->done = 1;
};
/**/
int getCount(char* p_strBuff){
	char strTemp[2];
	char* p_strstr = strchr(p_strBuff, '>')+1;
	strncpy(strTemp, p_strstr, 2);
	if(strTemp[1] == '<'){
		strTemp[1] = '\0';
	}
	return (int)strtol(strTemp, NULL, 10);
};
/**/
int getStatus(char* p_strBuff){
	if(strstr(p_strBuff, "Поехал") != NULL){
		return 1;
	}
	return 0;
};
/*      Функция подсчитывает количество вхождений подстроки pattern в строку.
Принимает переменные:
        указатель на искомую строку char * str;
        указатель на шаблон char * pattern.
Функция возвращает количество вхождений.
*/
int strInStrCount(char * str, char * pattern){
        char * ptn = pattern;
        int count = 0;
        while(*str != '\0'){
                if(*str == *ptn){
                        ptn += 1;
                        if(*ptn == '\0'){
                                count++;
                                ptn = pattern;
                        }
                }else ptn = pattern;
                str += 1;
        }
        return count;
};
/**/
int getDiscountCount(char * srcStr){
    int count = 0;
    count = strInStrCount(srcStr, "Д.К.");
    count += strInStrCount(srcStr, "ДК");
    count += strInStrCount(srcStr, "Дк");
    count += strInStrCount(srcStr, "Д.к.");
    count += strInStrCount(srcStr, "д.к."); 
    count += strInStrCount(srcStr, "дк");
	return count;
};
/**/
int getNoCostCount(char * srcStr){
    int count = 0;
    count = strInStrCount(srcStr, "бесплатно");
    count += strInStrCount(srcStr, "б/н");
    count += strInStrCount(srcStr, "безнал");
    count += strInStrCount(srcStr, "безнл");
    count += strInStrCount(srcStr, "оплачено"); 
	return count;
};
