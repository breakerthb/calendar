#ifndef MONTH_H_INCLUDED
#define MONTH_H_INCLUDED

#include "String.h"

typedef struct _tagMonth
{
    String _strName; // �·�����
    String _arrayDays[6]; // �����б�
    int _nArraySize; // �����б��������
}Month;

void SetMonthName(Month* pMonth, char* pBuf);
void AddDaysLine(Month* pMonth, String* pStr);
char* GetMonthName(Month* pMonth);
String* GetDaysArray(Month* pMonth);
int GetDaysArraySize(Month* pMonth);
void PrintMonth(Month* pMonth);

#endif // MONTH_H_INCLUDED
