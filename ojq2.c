#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char *name)
{
    int n = strlen(name);
    for (int i = 0, j = n - 1; i < n / 2 && j >= n / 2; i++, j--)
    {
        name[i] = name[i] ^ name[j];
        name[j] = name[i] ^ name[j];
        name[i] = name[i] ^ name[j];
    }
}

int main()
{
    char *name = (char *)malloc(((int)(4e5 + 1)) * sizeof(char));
    scanf("%s", name);
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int q;
        scanf("%d", &q);
        if (q == 1)
        {
            cnt++;
        }
        else
        {
            int l;
            char *j = (char *)malloc(((int)(4e5 + 1)) * sizeof(char));
            scanf("%d %s", &l, j);
            if (((l == 1) && (cnt % 2 == 0)) || ((l == 2) && (cnt % 2 == 1)))
            {
                strcat(j, name);
                strcpy(name, j);
            }
            else
            {
                strcat(name, j);
            }
            free(j);
        }
    }
    if (cnt % 2 == 1)
    {
        reverse(name);
    }
    printf("%s\n", name);
    free(name);
    return 0;
}
