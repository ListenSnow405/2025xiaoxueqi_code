#include <cstdio>

using namespace std;
const int N=1e5+10;
int a[N];
int main()
{
    int n,h;
    long long ans=0;
    scanf("%d%d",&n,&h);
    scanf("%d",&a[1]);
    ans = h - a[1];
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<a[i-1])
            ans += a[i - 1] - a[i];
    }
    printf("%lld\n", ans);
    return 0;
}