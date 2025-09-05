
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int N=5e5+10;
int n,left[N],right[N],ans;
char s[N];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        int balance = 0;
        int min_prefix = 0;
        int len = strlen(s);
        for (int j = 0; j < len; ++j) {
            char c = s[j];
            if (c == '(') balance++;
            else balance--;
            
            if (balance < min_prefix) min_prefix = balance;
        }
        if (min_prefix >= 0)  left[balance]++;
        else {
            if (min_prefix == balance) right[-balance]++;
        }
    }
    for (int i= 1;i<N;i++) {
        if(left[i]==0) continue;
        ans += min(left[i], right[i]);
    }
    ans += left[0] / 2;
    printf("%d\n", ans);
    return 0;
}
/*
7
)())
)
((
((
(
)
)
*/