#include <iostream>  
#include <algorithm>  
#include <vector>  
#include <cmath>  
  
using namespace std;  
 
#define ll long long   
const int N=1e5+10;  
int n;  
long long x[N],y[N],xx[N];  
int main() {  
      
    scanf("%d",&n);  
    for (int i = 0; i < n; i++)  scanf("%lld%lld",&x[i],&y[i]);  
      
    sort(y,y+n);  
    ll mid_y = y[n/2];  
    ll sum = 0;  
    for (int i = 0; i < n; i++) sum += abs(y[i] - mid_y);  
      
    sort(x,x+n);  
    for (int i = 0; i < n; i++) xx[i] = x[i] - i;  
    sort(xx,xx+n);  
  
    ll mid_b =xx[n/2];  
    ll sum_x = 0;  
  
    for (int i = 0; i < n; i++)  sum += abs(xx[i] - mid_b);  
      
    printf("%lld\n",sum);  
      
    return 0;  
}  