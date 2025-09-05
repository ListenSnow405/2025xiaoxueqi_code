#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
const int N=30;
int n;
char op[N], name[N];
queue<string> q;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", op);
        if (strcmp(op, "Arrive") == 0)
        {
            scanf("%s", name);
            q.push(string(name));
        } 
        else if (strcmp(op, "Leave") == 0 && !q.empty()) q.pop();
        else if (strcmp(op, "QueueHead") == 0)
        {
            if (q.empty()) puts("Empty queue");
            else printf("%s\n", q.front().c_str());
            
        } 
        else if (strcmp(op, "QueueTail") == 0)
        {
            if (q.empty()) puts("Empty queue");
            else printf("%s\n", q.back().c_str());
        }
    }
    return 0;
}
