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

    // 计算当年的1月1日是周几的公式，同时在输出过程中随时表示每一天是星期几
    week = GetWeek(year);

    for (i = 0; i < 12; i++)
    {
        // pCurMonth指向当前的月份
        pCurMonth = &g_Month[i];

        // 填写月份名称
        pStr = GetMonthStr(i + 1);
        SetMonthName(pCurMonth, pStr);

        StringInit(&str);
        for (k = 0; k < week; k++)
        {
            sprintf(pStr, "    ");
            StringAppend(&str, pStr);
        }

        // 这个月的每一天和星期对齐输出
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

        // 填写一行日期字符串
        AddDaysLine(pCurMonth, &str);
    }

    // 打印12个月的日历
    for (i = 0; i < 12; i++)
    {
        //PrintMonth(&g_Month[i]);
        PrintTwoMonth(&g_Month[i++], &g_Month[i]);
        printf("\n");
    }

    return 0;
}
