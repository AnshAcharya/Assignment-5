#include <stdio.h>
#include <string.h>

int allowed(char *str, int end, int start)
{
    for (int i = start; i < end; i++)
    {
        if(str[i] != str[i + 1])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    char str[n + 1];
    scanf("%s", str);

    int max = 0;
    int arr[26] = {0};
    for (int i = 0; i < n; i++)
    {
        if (allowed(str, i + k - 1, i) == 1)
        {
            arr[str[i] - 'a']++;
            i += k - 1;
        }
    }
    for(int i = 0; i < 26; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    printf("%d\n", max);

    return 0;
}
