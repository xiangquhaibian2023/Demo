#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool checkLastTwoChars(const char* str) {
    int strLength = std::strlen(str);

    const char* lastTwoChars = str + strLength - 2;
    return std::strcmp(lastTwoChars, "sz") == 0 || std::strcmp(lastTwoChars, "sh") == 0;

    return false;
}

inline int countUnderscores(const std::string& str) 
{
    return std::count(str.begin(), str.end(), '_');
}


int GetSplitString(char* pszInBuf, int iInLen, const char* pszSplitStr, int iFieldIndex, char* pszOutBuf, int iOutLen)
{
    int iSplitLen = (int)strlen(pszSplitStr);
    char* pszSrc = pszInBuf;
    char* pszSplit = strstr(pszSrc, pszSplitStr);
    int iIndex = 1;
    while (pszSplit != nullptr && iIndex < iFieldIndex)
    {
        if (pszSplit - pszInBuf <= iInLen)
        {
            iIndex++;
            pszSrc = pszSplit + iSplitLen;
            pszSplit = strstr(pszSrc, pszSplitStr);
        }
        else
        {
            break;
        }
    }
    if (iIndex < iFieldIndex)
    {
        pszOutBuf[0] = '\0';
        return 0;
    }
    else if (pszSplit == nullptr)
    {
        int iCopyLen = min(iOutLen - 1, iInLen - (int)(pszSrc - pszInBuf));
        memcpy(pszOutBuf, pszSrc, iCopyLen);
        pszOutBuf[iCopyLen] = '\0';
        return iCopyLen;
    }
    else
    {
        int iCopyLen = min(iOutLen - 1, (int)(pszSplit - pszSrc));
        memcpy(pszOutBuf, pszSrc, iCopyLen);
        pszOutBuf[iCopyLen] = '\0';
        return iCopyLen;
    }
}

void SpiltString(char* str, int strlen, char* str1, int str1len, char* str2, int str2len, int count)
{
    switch (count)
    {
    case 3:
    {
        GetSplitString(str, strlen, "_", 2, str1, str1len);
        GetSplitString(str, strlen, "_", 3, str2, str2len);
    }
    break;
    case 2:
    {
        if (checkLastTwoChars(str))
        {
            GetSplitString(str, strlen, "_", 2, str1, str1len);
            GetSplitString(str, strlen, "_", 2, str2, str2len);
        }
        else
        {
            GetSplitString(str, strlen, "_", 2, str1, str1len);
            GetSplitString(str, strlen, "_", 3, str2, str2len);
        }
    }
    break;
    case 1:
    {
        GetSplitString(str, strlen, "_", 2, str1, str1len);
        GetSplitString(str, strlen, "_", 2, str2, str2len);
    }
    break;
    default:
        break;
    }
}


void PrintOut(char* str)
{
    int count = 0;
    char out1[32] = { 0 };
    char out2[32] = { 0 };

    memset(out1, 0, sizeof(out1));
    memset(out2, 0, sizeof(out2));

    count = countUnderscores(str);

    cout << str <<"         " << "Number of underscores: " << count << std::endl;

    SpiltString(str, strlen(str), out1, sizeof(out1), out2, sizeof(out2), count);

    cout << str <<"         " << "out1:" << out1 << "   " << "out2:" << out2 << endl;
}


int main() 
{
    char str[120] = "797979_4101_sh";

    PrintOut(str);

    memset(str, 0, sizeof(str));

    snprintf(str, sizeof(str), "797979_4101_4102_sh");

    PrintOut(str);

    memset(str, 0, sizeof(str));

    snprintf(str, sizeof(str), "797979_4101_sz");

    PrintOut(str);

    memset(str, 0, sizeof(str));

    snprintf(str, sizeof(str), "797979_4101_4102_sz");

    PrintOut(str);

    memset(str, 0, sizeof(str));

    snprintf(str, sizeof(str), "797979_4101_4102");

    PrintOut(str);

    memset(str, 0, sizeof(str));

    snprintf(str, sizeof(str), "797979_4101");

    PrintOut(str);

    return 0;
}