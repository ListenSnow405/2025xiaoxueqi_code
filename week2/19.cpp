#include<cstdio>
#include<cstring>
#include<stack>
 
using namespace std;
 
const int N = 2e5+10;
int a[N],n;
stack<int> stk;
 
int main() {
    while (EOF != scanf("%d", &n))
    {
        int maxh = 0;  
        
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] > maxh) maxh = a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            int temp=(maxh - a[i]) % 2;
            if (!stk.empty() && temp == stk.top()) stk.pop();
            else stk.push(temp);
        }
        puts(stk.size()<=1 ? "YES" : "NO");
        while (!stk.empty()) stk.pop();
    }

    return 0;
}