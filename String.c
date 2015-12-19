#include "String.h"

void StringInit(String* pStr)
{
    pStr->buf[0] = 0;
    pStr->len = 0;
}

void StringSet(String* pStr, char* pBuf)
{
    int i = 0;
    while (*pBuf != 0)
    {
        pStr->buf[i++] = *pBuf++;
    }

    pStr->buf[i] = 0;
    pStr->len = i;
}

void StringCopy(String* pDes, String* pSrc)
{
    StringSet(pDes, pSrc->buf);
}

void StringAppend(String* pStr, char* pBuf)
{
    int i = pStr->len;

    while (*pBuf != 0)
    {
        pStr->buf[i++] = *pBuf++;
    }

    pStr->buf[i] = 0;
    pStr->len = i;
}
