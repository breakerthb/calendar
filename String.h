#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#define BUF_SIZE 100

typedef struct _tagString
{
    char buf[BUF_SIZE];
    int len;
}String;

void StringInit(String* pStr);
void StringSet(String* pStr, char* pBuf);
void StringCopy(String* pDes, String* pSrc);
void StringAppend(String* pStr, char* pBuf);

#endif // STRING_H_INCLUDED
