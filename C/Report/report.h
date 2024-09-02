#define     OpenTag     '<'      //  Открывающий тег 60
#define     CloseTag    '>'      //  Закрывающий тег 62

#define     yes         1       //  да - 1
#define     no          0       //  нет - 0
#define     buffSize    256

#define     ERR         "Ошибка открытия... :(\n"
#define     SUCS        "Файл открыт. :)\n"
#define     OPENING     "Открытие файла:\n"

/*
struct file_message_struct {
  char * err;
  char * sucs;
  char * opening;
} f_message = {ERR, SUCS, OPENING};
*/
struct reportPass {
        int half;                                                       //      Количество пассажиров оплативших 17 рублей.
        int discount;                                                   //      Количество пассажиров оплативших 30 рублей.
        int full;                                                       //      Количество пассажиров оплативших 35 рублей.
        int noCash;                                                     //      Количество пассажиров по безналу.
};
/*
        Функция передвигает указатель до указанного символа chr.
Возвращаемое значение указатель на следующий за указанным символом.
*/
extern char* movePointerToChar(char * p_b, char chr, int display);
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
extern int isDigit (int c);
/**/
extern void printPointerAddr(char * pointer);
/**/
extern int charToDigit(char *p);
/*      Функция подсчитывает количество вхождений подстроки pattern в строку.
Функция возвращает количество вхождений.*/
extern int strInStrCount(char * str, char * pattern);
/**/
extern void addStr(char * p_b, char * target, char start, char end);
/**/
extern int getDiscountCount(char * srcStr);
/**/
extern int getNoCashCount(char * srcStr);
/**/
extern int strIsName(char * srcStr);
/**/
extern int strIsNumberOfSeats(char * srcStr);
/**/
extern int strIsPayment(char * srcStr);
/**/
extern int strIsStatus(char * srcStr);
/**/
extern int isNoCash(char * srcStr);
/**/
extern void getContent(char * srcPointer, char * targetPointer);
/**/
extern void appendPassName(char * srcPointer, char * targetPointer);
/**/
extern void clearString(char * string, int sizeOfString);
