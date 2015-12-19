#include <stdio.h>
#include "Month.h"

// ��д�·�Ӣ����
void SetMonthName(Month* pMonth, char* pBuf)
{
    StringSet(&pMonth->_strName, pBuf);
}

// ��Month��_arrayDays�����һ�����ַ���
void AddDaysLine(Month* pMonth, String* pStr)
{
    StringAppend(pStr, " ");

    pStr->buf[27] = 0;
    pStr->len = 27;

    StringCopy(&pMonth->_arrayDays[pMonth->_nArraySize++], pStr);
}

// �����·�����
char* GetMonthName(Month* pMonth)
{
    return pMonth->_strName.buf;
}

// ���������б���ַ�������
String* GetDaysArray(Month* pMonth)
{
    return pMonth->_arrayDays;
}

// ���������б������
int GetDaysArraySize(Month* pMonth)
{
    return pMonth->_nArraySize;
}

// ��ӡĳ���µ�����
void PrintMonth(Month* pMonth)
{
    int i;

    // ��ӡ����
    printf("%27s\n", pMonth->_strName.buf);
    // ��ӡ�ָ���
    printf("----------------------------\n");
    // ��ӡ�����б�
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    // ��ӡÿ�������б�
    for (i = 0; i < pMonth->_nArraySize; i++)
    {
      printf("%27s\n", pMonth->_arrayDays[i].buf);
    }
}
