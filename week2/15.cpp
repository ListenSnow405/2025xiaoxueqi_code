#include <iostream>  
#include <vector>  
#include <algorithm>  
using namespace std;  
#define ll long long  
const int N=2e5+10;  
struct Dragon {  
    ll x,y;  
}pos[N],neg[N];  
bool cmp1(const Dragon &a, const Dragon &b) {  
    return a.x < b.x;  
}  
bool cmp2(const Dragon &a, const Dragon &b) {  
    return a.x+a.y > b.x+b.y;  
}  
int n,len1,len2;  
int main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(0);  
      
    scanf("%d",&n);  
      
    for (int i = 0; i < n; i++){  
        ll x,y;  
        scanf("%lld %lld",&x,&y);  
        if (y >= 0) pos[len1++]=Dragon{x,y};  
        else neg[len2++]=Dragon{x,y};  
    }  
    sort(pos,pos+len1,cmp1);  
    sort(neg,neg+len2,cmp2);  
    ll now=0,ans=0;  
    for(int i=0;i<len1;i++)  
    {  
        if(now<pos[i].x)  
        {  
            ans+=pos[i].x-now;  
            now=pos[i].x;  
        }  
        now+=pos[i].y;  
    }  
    for(int i=0;i<len2;i++)  
    {  
        if(now<neg[i].x)  
        {  
            ans+=neg[i].x-now;  
            now=neg[i].x;  
        }  
        now+=neg[i].y;  
    }  
    printf("%lld\n",ans);  
    return 0;  
}  