#include<bits/stdc++.h>  
using namespace std;  
int main()  
{  
    int n,x,ans;  
    priority_queue<int,vector<int>,greater<int> >q;  
    cin>>n;  
    for(int i=1;i<=n;i++)   
    {  
        cin>>x;  
        q.push(x);  
    }  
    while(q.size()>=2)  
    {  
        int a,b;  
        a=q.top();   
        q.pop();  
        b=q.top();  
        q.pop();  
        ans+=a+b;  
        q.push(a+b);  
    }  
    cout<<ans<<endl;  
    return 0;  
}  