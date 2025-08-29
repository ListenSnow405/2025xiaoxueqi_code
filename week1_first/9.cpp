#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=(1<<16)+5;
const int M=20;
int a[M][M],b[M][M],n,m;
char s[M];

int main()
{
    int ans = 1e9;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        for(int j=0;j<m;j++) a[i][j]=s[j]=='1'?1:0;
    }   
    for(int t=0;t<(1<<m);t++)
    {
        int sum=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) 
                b[i][j]=a[i][j];
        for(int j=0;j<m;j++)
        {
            if((t>>j)&1)
            {
                b[0][j] ^= 1;
                b[1][j] ^= 1;
                b[0][j-1]^=1;
                b[0][j+1]^=1;
                sum++;
                /*if(t==1)
                {
                    printf("0 %d\n",j);
                    for(int x=0;x<n;x++)
                    {
                        for(int y=0;y<m;y++)
                            printf("%d ", b[x][y]);
                        puts("");
                    }
                }*/
            }
        }
        for(int i=1;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(b[i-1][j]==1)
                {
                    b[i][j]^=1;
                    b[i-1][j]^=1;
                    b[i+1][j]^=1;
                    b[i][j-1]^=1;
                    b[i][j+1]^=1;    
                    sum++;     
                /*   if(t==1)
                {
                    for(int i=0;i<n;i++)
                    {
                        for(int j=0;j<m;j++)
                            printf("%d ", b[i][j]);
                        puts("");
                    }
                } */          
                }
            }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(b[i][j]==1) sum=1e9;
                // printf("%d ", b[i][j]);
            }
            // puts("");
        }
        ans=min(ans,sum);
    }
    printf("%d\n", ans);
    return 0;
}