#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char *name)
{
    int n = strlen(name);
    for (int i = 0; i < n / 2; i++)
    {
        char temp = name[i];
        name[i] = name[n - i - 1];
        name[n - i - 1] = temp;
    }
}

int main()
{
    char name[(int)4e5 + 1];
    scanf("%s", name);
    int n;
    scanf("%d", &n);
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
            char j[(int)(4e5 + 1)];
            scanf("%d %s", &l, j);
            if (l == 1)
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
    printf("%s\n", name);
    return 0;
}
