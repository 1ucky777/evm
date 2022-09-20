#include <stdio.h>
using namespace std;
int strlen(char *a)
{
    int i = 0;
    while (a[i] != '\0')
        i++;
    return i;
}
void strcopy(char *a, char *b)
{
    for (int i = 0; b[i] != '\0'; i++)
        a[i] = b[i];
}
int entry(char *a, char *b)
{
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}
void del(char *a)
{
    char *b = new char[strlen(a)];
    strcopy(b, a);
    delete[] a;
    a = new char[strlen(b) - 1];
    for (int i = 0; i < strlen(b) - 1; i++)
    {
        a[i] = b[i];
        a[i + 1] = '\0';
    }
}
char *LongestCommonPrefix(int m)
{
    char *mas[] = {"car", "carier", "case", "cout"};
    int y = 0;
    for (int i = 0; i < m; i++)
    {
        if (strlen(mas[y]) > strlen(mas[i]))
            y = i;
    }
    char *min = new char[y];
    strcopy(min, mas[y]);
    y = 1;
    while (y && strlen(min))
    {
        for (int i = 0; i < m; i++)
        {
            if (!entry(min, mas[i]))
            {
                del(min);
                break;
            }
            if (i == m - 1)
                y = 0;
        }
    }
    return min;
}
int main()
{
    printf("%s", LongestCommonPrefix(4));
}