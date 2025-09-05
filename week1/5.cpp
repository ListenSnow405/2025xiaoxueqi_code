#include <cstdio>
#include <cmath> 
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
long long ans = 0;
int n, a[N],l[N],r[N],stk[N],top;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            l[i] = r[i] = 0;
        }
        l[0]=r[n+1]=0;
        for(int i=1;i<=n;i++)
        {
            l[i] = max(l[i - 1], a[i]);
        }
        for(int i=n;i>=1;i--)
        {
            r[i] = max(r[i + 1], a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            //printf("%d %d\n",l[i],r[i]);
            if(min(l[i],r[i])>a[i])
                ans += min(l[i],r[i]) - a[i];
        }
        printf("%lld\n", ans);    
    }
    return 0;
}