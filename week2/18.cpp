#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e6+10;
int c[N], h[N], ans[N], n,stk[N],top,tot,cnt[N],num[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        top=tot=0;
        for (int i = 0; i < n; ++i) scanf("%d", &c[i]),ans[i]=0,num[i]=c[i];
        for (int i = 0; i < n; ++i) scanf("%d", &h[i]),cnt[i]=0;
        // 离散化h数组
        sort(num, num + n);
        int m = unique(num, num + n) - num;
        for (int i = 0; i < n; ++i) c[i] = lower_bound(num, num + m, c[i]) - num;
        int now=0;
        for (int i = 0; i < n; ++i)
        {
            while (top && h[stk[top]] < h[i]) {
                if(--cnt[c[stk[top]]]==0) now--;
                top--;
            }
            if(cnt[c[i]]==0) now++;
            cnt[c[i]]++;
            stk[++top] = i;
            ans[i] = now;
        }
        for (int i = 0; i < n; ++i) {
            printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');
        }
    }
    return 0;
}
