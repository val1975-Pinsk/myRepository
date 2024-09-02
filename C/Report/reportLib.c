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
/**/
void printPointerAddr(char * pointer){
  printf("%p\n", &pointer);
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
        Функция ищет подстроку pattern в искомой строке str. Если находит возращает 1, иначе 0.
*/
int strInStr(char * str, char * pattern){
        char * ptn = pattern;
        while(*str != '\0'){
                if(*str == *ptn){
                        //*(ptn++);
                        ptn += 1;
                        if(*ptn == '\0'){
                                return yes;
                        }
                }else ptn = pattern;
                //*(str++);
                str += 1;
        }
        return no;
}
/**/
int strIsName(char * srcStr){
		char * pattern = "colspan=\"3\"";
		return strInStr(srcStr, pattern);
}
/**/
int strIsNumberOfSeats(char * srcStr){
		char * pattern = "width=\"25px\"";
		return strInStr(srcStr, pattern);
}
/**/
int strIsStatus(char * srcStr){
		char * pattern = "selected=\"selected\"";
		return strInStr(srcStr, pattern);
}
/**/
int strIsPayment(char * srcStr){
		char * pattern = "colspan=\"5\"";
		if(strInStr(srcStr, pattern)){
		if(!strInStr(srcStr, "</td>")) return no;
		if(strInStr(srcStr, "height=\"40px\"")) return no;
		if(strInStr(srcStr, "Минск")) return no;
		if(strInStr(srcStr, "свободно")) return no;
		return yes;
  }
}
/*
  Функция проверяет была ли произведена оплата по безналичному расчёту.
 */
int isNoCash(char * srcStr){
		if (strInStr(srcStr, "безнал")){
				return yes;
		}else if (strInStr(srcStr, "б/н")){
				return yes;
		}else if (strInStr(srcStr, "безнл")){
				return yes;
		}else if (strInStr(srcStr, "бесплатно")){
			return yes;
		}else return strInStr(srcStr, "оплачено");
}
/**/
void clearString(char * string, int sizeOfString){
  memset(string, ' ', sizeOfString);
}
/*
      Функция выделяет подстроку между закрывающим тэгом и открывающим.
  srcPointer - указатель на источник(строка HTML).
  targetPointer - указатель адресата, куда нужно записать.!
 */
void getContent(char * srcPointer, char * targetPointer){
	    srcPointer = movePointerToChar(srcPointer, CloseTag, 0);
	    *targetPointer = *srcPointer;
	    while(1){
				targetPointer += 1;
				srcPointer += 1;
				if(*srcPointer == OpenTag){
						*targetPointer = '\n';
				break;
				}
				*targetPointer = *srcPointer;
	  }
				targetPointer += 1;
				*targetPointer = '\0';
}
/**/
/*void appendPassName(char * srcPointer, char * targetPointer){
  targetPointer = movePointerToChar(targetPointer, '\0', 0);
  targetPointer -= 1;
  writePassName(srcPointer, targetPointer);
  }
*/
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
