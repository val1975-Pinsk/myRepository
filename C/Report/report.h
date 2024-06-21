#define     OpenTag                 60      //  Открывающий тег
#define     CloseTag                  62       //  Закрывающий тег

#define     yes                           1                   //  да - 1
#define     no                            0                    //  нет - 0

#define     ERR                         "ошибка\n"
#define     SUCS                       "успешно\n"

struct message {
        char * err;
        char * sucs ;
} ;
/**/
extern int getMonthDigit () ;
extern int getMonthDigit_2 () ;
/*
                Функция проверяет является ли символ числом.
        Функция возвращает 1 - если символ число, иначе возвращается 0.
*/
extern int isDigit ( int c ) ;
/**/
//extern char getStrContent ( char *str ) ;
