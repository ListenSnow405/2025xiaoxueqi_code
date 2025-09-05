#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int a[110][110], rm[110], cm[110];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] > rm[i])
                rm[i] = a[i][j];
            if (a[i][j] > cm[j])
                cm[j] = a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            if (a[i][j] != min(rm[i], cm[j]))
            {
                puts("NO");
                return 0;
            }
    }
    puts("YES");
    return 0;
}