#include <cstdio>  
#include <algorithm>  
using namespace std;  
const int N=3e5+10;  
struct node {  
    int start;  
    int end;  
}nodes[N];  
int n,ans,last;  
bool cmp(const node &a, const node &b) {  
    return a.end < b.end;  
}  
  
int main() {  
    scanf("%d", &n);  
    for (int i = 0; i < n; i++) scanf("%d %d", &nodes[i].start, &nodes[i].end);  
    sort(nodes, nodes + n, cmp);  
  
    for (int i = 0; i < n; i++)  
        if (nodes[i].start >= last) {  
            ans++;  
            last = nodes[i].end;  
        }  
    printf("%d\n", ans);  
    return 0;  
}  