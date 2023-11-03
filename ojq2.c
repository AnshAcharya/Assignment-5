#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

char *reverse(char *str)
{
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++)
    {
        swap(&str[i], &str[n - i - 1]);
    }
    return str;
}

void name_the_dog(char *name, int n)
{
    for (int i = 0; i < n; i++)
    {
        int q;
        scanf("%d", &q);
        if (q == 1)
        {
            reverse(name);
        }
        else
        {
            int l;
            char j[2];
            scanf("%d %s", &l, j);
            if(l == 1)
            {
                strcat(j, name);
                strcpy(name, j);
            }
            else
            {
                strcat(name, j);
            }
        }
    }
}

int main()
{
    char name[(int)1e5 + 1];
    scanf("%s", name);
    int n;
    scanf("%d", &n);
    name_the_dog(name, n);
    printf("%s\n", name);
    return 0;
}
