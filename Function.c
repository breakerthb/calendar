char g_month[12][10] = { "January", "February", "March", "April", "May", "June",
"July", "August", "September", "October", "November", "December" };

int g_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// ͨ���·����ִ�ӡ�·�����
char* GetMonthStr(int month)
{
    return g_month[month - 1];
}

// �ж����꣬�����귵��1����ƽ�귵��0
int IsLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

// ����������ݵ�1��1�����ܼ�
int GetWeek(int year)
{
    return (35 + year + year / 4 - year / 100 + year / 400) % 7;
}

// ��������������������·�����
int GetDays(int year, int month)
{
    if (month == 2 && IsLeapYear(year))
    {
        return g_days[month - 1] + 1;
    }
    else
    {
        return g_days[month - 1];
    }
}
