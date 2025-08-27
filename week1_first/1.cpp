#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
string s;
bool wr[11];
int main()
{
    int n;
    scanf("%d", &n);
    while (n != 0)
    {
        getline(cin, s);
        if (s == "too low")
        {
            for (int i = 1; i <= n; i++)
                wr[i] = true;
        }
        else if (s == "too high")
        {
            for (int i = n; i <= 10; i++)
                wr[i] = true;
        }
        else if (s == "right on")
        {
            if (wr[n])
                printf("Tom is dishonest\n");
            else
                printf("Tom may be honest\n");
            for (int i = 1; i <= 10; i++)
                wr[i] = false;
        }
        scanf("%d", &n);
    }
    return 0;
}
/*
5
too low
7
too high
6
right on
10
too high
3
too low
4
too high
2
right on
0
*/