#include <stdio.h>
#include "Month.h"

// 填写月份英文名
void SetMonthName(Month* pMonth, char* pBuf)
{
    StringSet(&pMonth->_strName, pBuf);
}

// 在Month的_arrayDays中添加一行新字符串
void AddDaysLine(Month* pMonth, String* pStr)
{
    StringAppend(pStr, " ");

    pStr->buf[27] = 0;
    pStr->len = 27;

    StringCopy(&pMonth->_arrayDays[pMonth->_nArraySize++], pStr);
}

// 返回月份名称
char* GetMonthName(Month* pMonth)
{
    return pMonth->_strName.buf;
}

// 返回日期列表的字符串数组
String* GetDaysArray(Month* pMonth)
{
    return pMonth->_arrayDays;
}

// 返回日期列表的行数
int GetDaysArraySize(Month* pMonth)
{
    return pMonth->_nArraySize;
}

// 打印某个月的日历
void PrintMonth(Month* pMonth)
{
    int i;

    // 打印月名
    printf("%27s\n", pMonth->_strName.buf);
    // 打印分割线
    printf("----------------------------\n");
    // 打印星期列表
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    // 打印每行日期列表
    for (i = 0; i < pMonth->_nArraySize; i++)
    {
      printf("%27s\n", pMonth->_arrayDays[i].buf);
    }
}
