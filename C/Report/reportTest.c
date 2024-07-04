#include <stdio.h>
#include <string.h>
#include "report.h"

struct message messg = { ERR, SUCS } ;
char * fileName = "Водители.html";
char buffer [ 256 ];
char * p_b = buffer;

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
void main ( void ) {
        printf ( "Открытие файла:\n");
        printf ( "%s\n", fileName ) ;
        FILE * p_f = fopen ( fileName, "r" );                                   //Открываем файл.
        if ( p_f == NULL ) {
                printf ( "%s", messg.err );
        } else {
                printf ( "%s", messg.sucs );
                char * colspan_5 = "colspan=\"5\"";
                while ((fgets(buffer, 256, p_f)) != NULL){
                        if(strInStr(p_b, colspan_5)){
                                char * pattern;
                                if(strInStr(p_b, pattern = "Пинск")){           //Здесь ищем строку с названием маршрута.
                                        //Перемещаем указатель к началу содержимого строки/
                                        p_b = movePointerToChar(p_b, CloseTag, 0);
                                        printf("Дата: \t\t   ");
                                        p_b = movePointerToChar(p_b, ',', 1);
                                        printf("\nВремя отправления:");
                                        while(1){
                                                if(*p_b == ','){
                                                        *(p_b += 2);
                                                        break;
                                                }
                                                printf("%c", *p_b);
                                                *(p_b++);
                                        }
                                        printf("\nМаршрут: \t   ");
                                        while(1){
                                                if(*p_b == OpenTag){
                                                        *(p_b += 2);
                                                        printf("\n");
                                                        break;
                                                }
                                                printf("%c", *p_b);
                                                *(p_b++);
                                        }
                                        //Берём из строки нужное содержимое.
                                        /*int getContent = 0;
                                        char str[256];
                                        char * p_str = str;
                                        printf("before While: getContent = %d\n", getContent);
                                        while(1){
                                                if((*p_b == CloseTag)&&(getContent == 0)){
                                                        getContent = 1;
                                                        *(p_b++);
                                                        printf("after CloseTag: getContent = %d\n", getContent);
                                                }else if((*p_b == OpenTag)&&(getContent == 1)){
                                                        printf("\n");
                                                        getContent = 0;
                                                        break;
                                                }
                                                if(getContent) printf("%c", *p_b);
                                        }*/
                                }
                                if(strInStr(p_b, pattern = "свободно")){   //Здесь ищем строку с названием автомобиля.
                                        printf("%s", p_b);
                                }
                        }
                                                
                }
        }
}
