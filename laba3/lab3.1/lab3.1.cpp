#include <cstdio>

int main()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if ('A' <= c && c <= 'Z')
        {
            c += 'a' - 'A';
        }
        putchar(c);
    }
    return 0;
}