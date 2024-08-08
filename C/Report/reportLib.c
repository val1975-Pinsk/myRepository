# include <stdio.h>
# include <string.h>
# include "report.h"


enum month {Январь = 1, Февраль, Март, Апрель, Май, Июнь, Июль, Август, Сентябрь, Октябрь, Ноябрь, Декабрь} ;
/*
  Функция запроса на получение месяца в числовом выражении версия 2.
*/
int getMonthDigit_2 () {
        int month ;
        printf ( "Введите порядковый номер месяца: " ) ;
        scanf ( "%d", &month ) ;
        return month ;
}
/*
  Функция запроса на получение месяца в числовом выражении.
*/
int getMonthDigit () {
        int c, month ;
        month = 0 ;
        while ( 1 ) {
                c = getchar () ;
                if ( c == 10 ) {
                        if ( month == 0 ) {
                                printf ( "Ноль недопустимое значение!\n" ) ; 
                        } else if ( month > 12 ) {
                                printf ( "Недопустимое значение, больше 12!\n" ) ;
                                month = 0 ;
                        } else return month ;
                }
                if ( isDigit ( c ) ){
                        if ( month != 0 ){
                                month = month * 10 + ( c - 48 ) ;
                        } else {
                                month = c - 48 ;
                        }
                }
        }
}
/*
        Проверка символа на число.
        Функция возвращает 1 - если символ число, иначе возвращается 0.
*/
int isDigit ( int c ){
        if ( c >= '0' && c <= '9'){
                return 1;
        } else return 0;
}
/**/
void printStr (char *p_b, int size){
        for (int c = 0; c < size; c++) {
                printf("%c", *p_b);
                p_b ++;
        }
}
/*
        Функция ищет подстроку pattern в искомой строке str. Если находит возращает 1, иначе 0.
*/
int strInStr(char * str, char * pattern){
        char * ptn = pattern;
        while(*str != '\0'){
                if(*str == *ptn){
                        //*(ptn++);
                        ptn += 1;
                        if(*ptn == '\0'){
                                return 1;
                        }
                }else ptn = pattern;
                //*(str++);
                str += 1;
        }
        return 0;
}
/*
        Функция передвигает указатель до указанного символа chr.
Принимаемые переменные:

        char * p_b - указатель на начало строки;
        char chr - символ до которого передвинуть указатель;
        int display - 1:сдвиг с выводом в терминал;
                      0:просто сдвиг.
Возвращаемое значение:

        указатель на следующий за указанным символом.
*/
char * movePointerToChar(char * p_b, char chr, int display){
        while(1){
                if(*p_b == chr){
                        //*(p_b++);
                        p_b += 1;
                        return p_b;
                }
                if(display) printf("%c", *p_b);
                //*(p_b++);
                p_b += 1;
        }
}
/**/
int charToDigit(char *p){
        printf("%c", *p);
        switch(*p){
                case '1':
                        return 1;
                case '2':
                        return 2;
                case '3':
                        return 3;
                case '4':
                        return 4;
                case '5':
                        return 5;
                case '6':
                        return 6;
                case '7':
                        return 7;
                case '8':
                        return 8;
                case '9':
                        return 9;
                case '0':
                        return 0;
        }
        return -1;
}
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
                        //*(ptn++);
                        ptn += 1;
                        if(*ptn == '\0'){
                                count++;
                                ptn = pattern;
                        }
                }else ptn = pattern;
                //*(str++);
                str += 1;
        }
        return count;
}
/**/
int getDiscountCount(char * srcStr){
        int count = 0;
        count = strInStrCount(srcStr, "Д.К.");
        count += strInStrCount(srcStr, "Дк");
        count += strInStrCount(srcStr, "д.к."); 
        count += strInStrCount(srcStr, "дк");
	return count;
}
/**/
int getNoCashCount(char * srcStr){
        int count = 0;
        count = strInStr(srcStr, "бесплатно");
        count += strInStr(srcStr, "б/н");
        count += strInStr(srcStr, "безнал");
        count += strInStr(srcStr, "безнл");
        count += strInStr(srcStr, "оплачено");
        return count;
}
/**/
void printHeaderPart_1(char * p_b){
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
/**/
int printHeaderPart_2(char * p_b){
  int digit, count;
  p_b = movePointerToChar(p_b, CloseTag, 0);
  printf("\nЗанято: \t   ");
  digit = charToDigit(p_b);               //      Конвертируем количество занятых 
  if(digit != -1){                        //мест в числовое выражение.
    count = digit;                  //
  //*(p_b++);                       //warning: value computed is not used
  }                                       //
  p_b += 1;
  digit = charToDigit(p_b);               //
  if(digit != -1){                        //
    count = count * 10 + digit;           //
  }                                       //
  digit = count;
  p_b += 1; 
  p_b = movePointerToChar(p_b, ',', 1);
  printf(",");
  p_b = movePointerToChar(p_b, ',', 1);
  printf("\nАвтомобиль: \t  ");
  p_b = movePointerToChar(p_b, OpenTag, 1);
  printf("\n");
  printf("__________________________________________________\n");
  return digit;
}
