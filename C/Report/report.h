#ifndef REPORTTESTV2_H
#define REPORTTESTV2_H

#define yes	1
#define no	0

struct Length{
	int myDate;
	int directName;
	int myTime;
	int buffer;
};

struct DirectReport{
	char*name;
	char*time;
	char* date;
	int places_occupied;
	int done;
	int halfcost;
	int discount;
	int nocost;
};

struct Payment{
	int fullcost;
	int discount;
	int halfcost;
};

extern char* getMallocCharBuff(int sizeBuff);
extern void printHeader(struct DirectReport* dr, struct Payment* pay);
extern void creatHeaderPM(char* p_strBuff, struct DirectReport* PM, struct Length* Len);
extern void creatHeaderMP(char* p_strBuff, struct DirectReport* MP, struct Length* Len);
//extern void creatHeader(char* p_strBuff, struct DirectReport* PM, struct DirectReport* MP, struct Length* Len);
extern void creatHeader(char* p_strBuff, struct DirectReport* curent_report, struct Length* Len);
extern int getCount(char* p_strBuff);
extern int getStatus(char* p_strBuff);
extern int strInStrCount(char * str, char * pattern);
extern int getDiscountCount(char * srcStr);
extern int getNoCostCount(char * srcStr);
#endif
