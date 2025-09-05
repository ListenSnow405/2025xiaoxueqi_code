#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    long long T, n;
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld", &n);
        if(n==1)
        {
            puts("0");
            continue;
        }
        long long ans = static_cast<long long>(floor(log2(n - 1)) + 1);
        printf("%lld\n", ans);
    }
    return 0;
}