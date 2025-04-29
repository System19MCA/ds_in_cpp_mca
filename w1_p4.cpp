#include <iostream>

using namespace std;

class String
{

public:
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
};

int main()
{
    char s[100];
    char p[100];
    cout << "Enter string 1: ";
    gets(s);
    cout << "Enter string 2: ";
    gets(p);
    String ob;
    cout << "Length of string 1 is : " << ob.strlen(s) << endl;
    cout << ob.strcmp(s, p) << endl;
    cout << ob.strcat(s, p) << endl;
    cout << ob.strrev(s) << endl;
    return 0;
}