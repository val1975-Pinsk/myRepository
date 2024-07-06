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
                        *(ptn++);
                        if(*ptn == '\0'){
                                return 1;
                        }
                }else ptn = pattern;
                *(str++);
        }
        return 0;
};
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
char* movePointerToChar(char * p_b, char chr, int display){
        while(1){
                if(*p_b == chr){
                        *(p_b++); 
                        return p_b;
                }
                if(display) printf("%c", *p_b);
                *(p_b++);
        }
}

