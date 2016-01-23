#include <stdio.h>

#include "Month.h"
#include "Function.h"

Month g_Month[12];

int main()
{
    int i, j, k;
    int week;
    int days;
    int year = 2016;
    char* pStr;

    Month* pCurMonth;
    String str;

    // ���㵱���1��1�����ܼ��Ĺ�ʽ��ͬʱ�������������ʱ��ʾÿһ�������ڼ�
    week = GetWeek(year);

    for (i = 0; i < 12; i++)
    {
        // pCurMonthָ��ǰ���·�
        pCurMonth = &g_Month[i];

        // ��д�·�����
        pStr = GetMonthStr(i + 1);
        SetMonthName(pCurMonth, pStr);

        StringInit(&str);
        for (k = 0; k < week; k++)
        {
            sprintf(pStr, "    ");
            StringAppend(&str, pStr);
        }

        // ����µ�ÿһ������ڶ������
        days = GetDays(year, i + 1);
        for (j = 1; j <= days; j++)
        {
            sprintf(pStr, "%3d ", j);
            StringAppend(&str, pStr);

            if (++week >= 7)
            {
                AddDaysLine(pCurMonth, &str);
                week = week % 7;

                StringInit(&str);
            }
        }

        // ��дһ�������ַ���
        AddDaysLine(pCurMonth, &str);
    }

    // ��ӡ12���µ�����
    for (i = 0; i < 12; i++)
    {
        //PrintMonth(&g_Month[i]);
        PrintTwoMonth(&g_Month[i++], &g_Month[i]);
        printf("\n");
    }

    return 0;
}
