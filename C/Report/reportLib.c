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
/*

struct message {
        char * err_openf;
        char * complete ;
} ;
struct message messg = { "ошибка.\n", "выполнено.\n"} ;
char *fileName = "Водители.html" ;
char string [ 200 ] ;
char str [ 200 ] ;
char *p_string ;
char *p_str ;
int writeStr = no ;

int main ( void ) {
        printf ( "Открытие файла:\n");
        printf ( "%s\n", fileName ) ;
        FILE *p_f = fopen ( fileName, "r" ) ;
        if ( p_f == NULL ) {
                printf ( "%s", messg.err_openf ) ;
                return -1 ;
        } else {
                printf ( "%s", messg.complete ) ;
                //      Чтение строки из файла
                p_string = fgets ( string, sizeof ( string ), p_f ) ;           
                if ( p_string == NULL ) {
                        if ( feof ( p_f ) != 0 ) {
                                printf ( "\nЧтение файла закончено\n" ) ;
                                return 1 ;
                        } else {
                                printf ( "\nОшибка чтения из файла\n" ) ;
                                return -1 ;
                        }
                } else {
                //        Здесь происходит обработка строки.
                        int p_strLen = strlen( p_string ) ;
                        for ( int i = 0; i < p_strLen - 1; i++) {
                                if (*( p_string + i) == CloseTag ) {
                                        writeStr = no ;
                                }
                                if ( writeStr == yes ) {
                                        printf ( "%c", p_string[ i ]) ;
                                }
                                if ( *( p_string + i) == OpenTag ) {
                                        writeStr = yes ;
                                }
                        }
                        //return 1 ;
                }
                printf ( "Закрытие файла:") ;
                if ( fclose ( p_f ) == EOF ) {
                        printf ( " ошибка.\n" ) ;
                        return -1 ;
                }else {
                        printf ( " выполнено.\n" ) ;
                        return 1 ;
                }
        }        
} 
*/


