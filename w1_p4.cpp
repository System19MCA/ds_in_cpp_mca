#include <iostream>

using namespace std;

int strlen(char *str)
{
    int len = 0;
    while (*str++)
        len++;
    return len;
}

int strcmp(char *str1, char *str2)
{
    while (*str1 && *str2)
    {
        if (*str1 > *str2)
            return 1;
        else if (*str1 < *str2)
            return -1;
        *str1++;
        *str2++;
    }
    if (!(*str1) && !(*str2))
        return 0;
    if (*str1)
        return 1;
    return -1;
}

char *strcpy(char *dest, char *src)
{
    char *result = dest;
    while (*src)
    {
        *dest = *src;
        *dest++;
        *src++;
    }
    *dest = '\0';
    return result;
}

char *strcat(char *str1, char *str2)
{
    char *result = str1;
    while (*str1)
        *str1++;
    while (*str2)
    {
        *str1++ = *str2++;
    }
    *str1 = '\0';
    return result;
}

char *strrev(char *str)
{

    int len = strlen(str);
    for (int i = 0; i <= len / 2; i++)
    {
        swap(str[i], str[len - 1 - i]);
    }
    return str;
}

int main()
{
    char s[] = "hello";
    char p[] = "psdf";
    cout << strlen(s) << endl;
    cout << strcmp(s, p) << endl;
    // cout << strcpy(s, p);
    cout << strcat(s, p) << endl;
    cout << strrev(s) << endl;
    return 0;
}