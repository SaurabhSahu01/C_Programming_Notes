#include <stdio.h>
void main()
{
    int n, q = 0;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
    {
        int p = 2, z = 0;
        while (p <= a[i])
        {
            for (int t = 2; t < p; t++)
            {
                if (p % t == 0)
                {
                    q = 1;
                    break;
                }
            }
            if (q == 0)
            {
                if (a[i] % p == 0)
                {
                    z++;
                }
            }
            else
                q = 0;
            p++;
        }
        printf("%d\n", z);
    }
}