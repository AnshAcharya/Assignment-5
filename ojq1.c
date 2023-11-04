#include <stdio.h>

int check_unique(char str[], int start, int end)
{
    int flag = 1;
    for(int i = start; i < end; i++)
    {
        if(str[i] == str[i + 1])
        {
            continue;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main()
{
    int n, k, cnt = 0;
    scanf("%d %d", &n, &k);
    char str[n + 1];
    scanf("%s", str);
    //printf("%s\n", str);
    for (int i = 0; i < n; i++)
    {
        if(check_unique(str, i, i + k) == 1);
            {
                cnt++;
                i += k;
            }
    }
    printf("%d\n", cnt);
    return 0;
}