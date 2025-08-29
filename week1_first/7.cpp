#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);

    unordered_set<string> s;
    int ans = 0;

    for (int i = 0; i < n; i++) {

        string say;

        cin >> say;

        if (say.length() <= 10)
            continue;
         
        if (s.find(say) == s.end()) {
            ans++;
            s.insert(say);
        }
        
    }

    printf("%d\n",ans);
    
    return 0;
}