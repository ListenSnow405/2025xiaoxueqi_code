#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

inline int check(char c) {
    c = toupper(c);

    if (c == 'Q' || c == 'Z') return -1;
    if (c >= 'A' && c <= 'C') return 2;
    if (c >= 'D' && c <= 'F') return 3;
    if (c >= 'G' && c <= 'I') return 4;
    if (c >= 'J' && c <= 'L') return 5;
    if (c >= 'M' && c <= 'O') return 6;
    if (c >= 'P' && c <= 'S') return 7;
    if (c >= 'T' && c <= 'V') return 8;
    if (c >= 'W' && c <= 'Y') return 9;
    return -1;
}

const int total = 2000000;
const int N = 2000000/8;

map<int, int> duplication;
string s;
bool wrog;

int main() {
    char bitmap[N]={0};

    while (getline(cin, s)) {
        int num = 0;
        int digitCount = 0;
        bool error = false;
        
        for (char c : s) {
            if (c == '-') continue;
            if (isdigit(c)) {
                if (digitCount >= 7) {
                    error = true;
                    break;
                }
                num = num * 10 + (c - '0');
                digitCount++;
            } else if (isalpha(c)) {
                int digit = check(c);
                if (digit == -1) {
                    error = true;
                    break;
                }
                if (digitCount >= 7) {
                    error = true;
                    break;
                }
                num = num * 10 + digit;
                digitCount++;
            } else {
                error = true;
                break;
            }
        }
        
        if (!error && digitCount != 7) error = true;
        
        if (!error) {
            int firstDigit = num / 1000000;
            if (firstDigit != 3 && firstDigit != 6) error = true;
        }
        
        if (error) {
            if (!wrog) {
                cout << "Error:" << endl;
                wrog = true;
            }
            cout << s << endl;
        } 
        else 
        {
            int index;
            if (num >= 3000000 && num <= 3999999) index = num - 3000000;
            else index = num - 6000000 + 1000000;
            
            int byteIndex = index / 8;
            int bitIndex = index % 8;
            if (bitmap[byteIndex] & (1 << bitIndex)) {
                duplication[num]++;
            } else {
                bitmap[byteIndex] |= (1 << bitIndex);
            }
        }
    }
    
    if (!wrog)
    {
        puts("Error:");
        puts("Not found.");
    }

    puts("");
    puts("Duplication:");

    if (duplication.empty()) puts("Not found.");
    else 
    {
        for (auto& p : duplication) 
        {
            string numStr = to_string(p.first);
            cout << numStr.substr(0, 3) << "-" << numStr.substr(3) << " " << p.second+1 << endl;
        }
    }
    
    return 0;
}