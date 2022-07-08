#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int     my_puts     (const char *s);
int     my_strcmp   (const char *s1, const char *s2);
size_t  my_strlen   (const char *s);
char    *my_strchr  (const char *s, int c);
char    *my_strcpy  (char *dest, const char *src);
char    *my_strncpy (char *dest, const char *src, size_t n);
char    *my_strdup  (const char *s);
char    *my_fgets   (char *s, int size, FILE *stream);
char    *my_strcat  (char *dest, const char *src);
char    *my_strncat (char *dest, const char *src, size_t n);

int main ()
{
    char s[100];
    FILE* file = fopen ("test.txt", "r");
    printf ("%s\n", fgets (s, 15, file));
    fclose (file);
    return 0;
}


int my_puts (const char *s)
{
    if (s == NULL)
        return EOF;

    size_t i = 0;
    while (s[i] != '\0')
        putchar (s[i++]);
    
    putchar ('\n');
    return i;
}

int my_strcmp (const char *s1, const char *s2)
{
    if (s1 == NULL || s2 == NULL)
        return EOF;
    
    size_t i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    return (s1[i] - s2[i]);
}

size_t my_strlen (const char *s)
{
    if (s == NULL)
        return EOF;
    
    size_t i = 0;
    while (s[i] != '\0')
        i++;
    
    return i;
}

char *my_strchr (const char *s, int c)
{
    int i = -1;
    do {
        i++;
        if (s[i] == c)
            return (char*) s + i;
    } while (s[i] != '\0');
    
    return NULL;
}

char *my_strcpy (char *dest, const char *src)
{
    size_t i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
    return dest;
}

char *my_strncpy (char *dest, const char *src, size_t n)
{
    size_t i = 0;

    for ( ; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    
    for ( ; i < n; i++)
        dest[i] = '\0';

    return dest;
}

char *my_strdup (const char *s)
{
    size_t sz = strlen(s);
    char* res = (char*) malloc (sz + 1);
    if (res == NULL)
        return NULL;
    
    size_t i = 0;
    for ( ; i < sz; i++)
        res[i] = s[i];
    res[i] = '\0';
    
    return res;
}

char *my_fgets (char *s, int size, FILE *stream)
{
    if (s == NULL)
        return NULL;
    
    size_t i = 0;
    while (i < size - 1 && s[i] != EOF)
    {
        s[i] = getc (stream);

        if (s[i] == '\n')
        {
            s[++i] = '\0';
            return s;
        }
        else
            i++;
    }
    s[i] = '\0';
    return s;
}

char *my_strcat (char *dest, const char *src)
{
    size_t len = strlen (dest);
    size_t i = 0;
    do {
        dest[len + i] = src[i];
        i++;
    } while (src[i] != '\0');
    return dest;
}

char *my_strncat (char *dest, const char *src, size_t n)
{
    size_t len = strlen (dest);
    size_t i = 0;
    while (src[i] != '\0' && i < n)
    {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return dest;
}
