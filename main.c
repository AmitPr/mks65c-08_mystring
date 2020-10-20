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
    printf("mystrlen: %d, strlen: %d\n\n", mystrlen(str), strlen(str));
    printf("String 1: %s\n", str);
    printf("String 2: %s\n\n", str2);
    printf("mystrncpy: %s, ", mystrncpy(str, str2, 7));
    char test1[40] = "Hello World";
    char test2[40] = "Goodbye";
    printf("strncpy: %s\n", strncpy(test1, test2, 7));
    printf("mystrncpy, but exceed len of src: %s\n\n", mystrncpy(str, str2, 12));
    mystrncpy(str, "Hi", 3);
    mystrncpy(str2, "World", 8);
    printf("String 1: %s\n", str);
    printf("String 2: %s\n", str2);
    printf("mystrcat: %s\n\n", mystrcat(str, str2));
    printf("String 1: %s\n", str);
    printf("String 2: %s\n", str2);
    printf("mystrcmp(str1,str2): %d, strcmp: %d\n", mystrcmp(str, str2), strcmp(str,str2));
    printf("mystrcmp(str2,str1): %d, strcmp: %d\n", mystrcmp(str2, str), strcmp(str2,str));
    printf("mystrcmp(str1,str1): %d, strcmp: %d\n\n", mystrcmp(str, str), strcmp(str,str));
    printf("*str1: %p\n", &str);
    printf("mystrchr(str1,'W'): %p, strchr: %p\n", mystrchr(str, 'W'), strchr(str, 'W'));
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
    while (*s1==*s2){
        if(*s1=='\0') return 0;
        *s1++;
        *s2++;
    }
    return (*s1)-(*s2);
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