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
            if (!stk.empty() && a[i] == stk.top()) stk.pop();
            else
            {
                if(!stk.empty()&& a[i]>stk.top()) break;
                else stk.push(a[i]);
            }
        }
        if(stk.empty() || stk.size()==1 && stk.top()==maxh) puts("YES");
        else puts("NO");
        while (!stk.empty()) stk.pop();
    }

    return 0;
}