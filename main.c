#include <stdio.h>
#include <string.h>
int mystrlen(char *s);
char *mystrncpy(char *dest, char *source, int n);
char *mystrcat(char *dest, char *source);
int mystrcmp(char *s1, char *s2);
char *mystrchr(char *s, char c);

int main()
{
    char str[40] = "Hello World";
    char str2[40] = "Goodbye";
    printf("String: %s\n", str);
    printf("Sizeof: %lu\n", sizeof(str));
    printf("mystrlen: %d\n\n", mystrlen(str));
    printf("String 1: %s\n", str);
    printf("String 2: %s\n\n", str2);
    printf("mystrncpy: %s\n", mystrncpy(str, str2, 7));
    printf("mystrncpy, but exceed len of src: %s\n\n", mystrncpy(str, str2, 12));
    mystrncpy(str, "Hi", 3);
    mystrncpy(str2, "World", 8);
    printf("String 1: %s\n", str);
    printf("String 2: %s\n", str2);
    printf("mystrcat: %s\n\n", mystrcat(str, str2));
    printf("String 1: %s\n", str);
    printf("String 2: %s\n", str2);
    printf("mystrcmp(str1,str2): %d\n", mystrcmp(str, str2));
    printf("mystrcmp(str2,str1): %d\n", mystrcmp(str2, str));
    printf("mystrcmp(str1,str1): %d\n\n", mystrcmp(str, str));
    printf("*str1: %p\n", &str);
    printf("mystrchr(str1,'W'): %p\n", mystrchr(str, 'W'));
    return 0;
}

int mystrlen(char *s)
{
    int size = 0;
    while (*s)
    {
        ++size;
        *s++;
    }
    return size;
}

char *mystrncpy(char *dest, char *source, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        dest[i] = source[i];
        if (source[i] == '\0')
            break;
    }
    for (; i < n; i++)
    {
        dest[i] = '\0';
    }
    return dest;
}

char *mystrcat(char *dest, char *source)
{
    int dest_len = mystrlen(dest);
    int j;
    for (j = 0; source[j] != '\0'; j++)
    {
        dest[dest_len + j] = source[j];
    }
    dest[dest_len + j] = '\0';
    return dest;
}

int mystrcmp(char *s1, char *s2)
{
    int size_1 = 0;
    int size_2 = 0;
    int i;
    for (i = 0; i < mystrlen(s1); i++)
    {
        size_1 += s1[i];
    }
    for (i = 0; i < mystrlen(s2); i++)
    {
        size_2 += s2[i];
    }
    return size_1 - size_2;
}

char *mystrchr(char *s, char c)
{
    int i;
    for (i = 0; i < mystrlen(s) + 1; i++)
    {
        if (s[i] == c)
        {
            break;
        }
    }
    return (s+i);
}