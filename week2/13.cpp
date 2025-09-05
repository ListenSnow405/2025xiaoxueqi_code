#include<bits/stdc++.h>  
using namespace std;  
const int M=1e6+10;  
long long a[M],t[M],n,ans;  
void Sort(int l,int r)  
{  
        if(l==r) return ;  
        int mid=(l+r)>>1;  
        Sort(l,mid),Sort(mid+1,r);  
        int i=l,j=mid+1,k=l;  
        while(i<=mid&&j<=r)  
        {  
                if(a[i]<=a[j]) t[k++]=a[i++];  
                else t[k++]=a[j++],ans+=mid-i+1;   
        }  
        while(i<=mid) t[k++]=a[i++];  
        while(j<=r) t[k++]=a[j++];   
        for(int i=l;i<=r;i++) a[i]=t[i];  
}  
int main()  
{  
        cin>>n;  
        for(int i=1;i<=n;i++) cin>>a[i];  
        Sort(1,n);  
        cout<<ans<<endl;  
        return 0;  
}  