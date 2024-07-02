#define     OpenTag     60      //  Открывающий тег
#define     CloseTag    62      //  Закрывающий тег

#define     yes         1       //  да - 1
#define     no          0       //  нет - 0

#define     ERR         "ошибка\n"
#define     SUCS        "успешно\n"

struct message {
        char * err;
        char * sucs;
} ;
/*
        Функция проверяет содержит ли строка подстроку.
Функция принимает указатель на искомую строку str и указатель на шаблон pattern.
Возвращаемое значение:
        1-строка содержит шаблон;
        0-не содержит.        
*/
extern int strInStr(char *str, char *pattern);
/**/
extern int getMonthDigit ();
extern int getMonthDigit_2 ();
/*
        Функция проверяет является ли символ числом.
Функция возвращает 1 - если символ число, иначе возвращается 0.
*/
extern int isDigit ( int c );
/**/
extern void printStr (char *p_b, int size);
