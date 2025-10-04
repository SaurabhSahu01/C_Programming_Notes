#include <stdio.h>
void main()
{
    int n;
    scanf("%d", &n);
    float a[n], s = 0;
    char b[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%f%*c%c", &a[i], &b[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] == 'M')
        {
            s = a[i] + a[i] * 0.05;
        }
        else
        {
            s = a[i] + a[i] * 0.1;
        }
        if (a[i] < 10000)
        {
            s = s + a[i] * 0.02;
        }
        printf("%.2f\n", s);
    }
}