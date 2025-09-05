#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int lena,lenb;

string Add(const string &a, const string &b)
{
    int max_len = max(lena, lenb);
    string aa = string(max_len - lena, '0') + a;
    string bb = string(max_len - lenb, '0') + b;

    string result;
    int jinwei = 0;

    for (int i = max_len - 1; i >= 0; --i)
    {                                                                                                                                                                                                                        
        int total = (aa[i] - '0') + (bb[i] - '0') + jinwei;
        result.push_back('0' + (total % 2));
        jinwei = total / 2;
    }

    if (jinwei) result.push_back('1');

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        string a, b;
        cin >> a >> b;
        
        lena=a.size();
        lenb=b.size();

        string result = Add(a, b);

        cout << string(result.size() - lena + 2, ' ') + a << "\n+ " << string(result.size() - lenb , ' ') + b << "\n";
        cout << string(result.size()+2, '-') << "\n";
        cout << "  "+result << "\n";
    }

    return 0;
}
