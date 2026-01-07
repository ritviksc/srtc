#include <stddef.h>
#include <stdint.h>

size_t len(const char *str)
{
    char *start = str;
    if (!str)
    {
        return 0;
    }

    while (*str)
    {
        str++;

    }
    return (size_t)(str - start);
}

size_t nlen(const char *str, size_t maxlen)
{
    if (!maxlen)
    {
        return 0;
    }

    size_t count = 0;

    while (*str && count < maxlen)
    {
        str++;
        count++;
    }
    return count;
}

size_t cpystr(char *dst, const char *src)
{
    size_t i = 0;
    while (src[i]) {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';


    while (src[i])
        i++;

    return i;
}

size_t cpystrn(char *dst, const char *src, size_t maxlen)
{

    size_t i = 0;

    if (maxlen) {
        while (i < maxlen - 1 && src[i]) {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }

    while (src[i])
        i++;

    return i;
}

int cmpstr(const char *s1, const char *s2)
{

    const unsigned char *p1 = (const unsigned char *) s1;
    const unsigned char *p2 = (const unsigned char *) s2;
    while (*p1)
    {
        if (!*p2)
        {
            return 1;
        }
        if (*p1 < *p2)
        {
            return -1;
        }
        if (*p1 > *p2)
        {
            return 1;
        }
        p1++;
        p2++;
    }

    if (*p2)
    {
        return -1;
    }

    return 0;
}

int cmpstrn(const char *s1, const char *s2, size_t maxlen)
{
    const unsigned char *p1 = (const unsigned char *) s1;
    const unsigned char *p2 = (const unsigned char *) s2;
    size_t count = 0;
    while (*p1 && count < maxlen)
    {
        if (!*p2)
        {
            return 1;
        }
        if (*p1 < *p2)
        {
            return -1;
        }
        if (*p1 > *p2)
        {
            return 1;
        }
        p1++;
        p2++;
        count++;
    }

    if (*p2)
    {
        return -1;
    }

    return 0;
}

char *subchr(char *str, int character)
{
    unsigned char c = (unsigned char)(character);
    unsigned char *pstr = (unsigned char*)str;
    
    while(*pstr)
    {
        if (*pstr == c)
        {
            return pstr;
        }
        pstr++;
    }

    if (c == '\0')
    {
        return pstr;
    }

    return NULL;
}