#include <iostream>
#include<stack>
#include<string>
#include <vector>
using namespace std;

bool IsOp(char c)
{
    if(c=='-'||c=='+'||c=='/'||c=='*') return true;
    return false;
}

int main() {
    vector<string> s;
    string buf="";
    int i=0;
    char c;
    while((c=getchar())!='\n') {
        if (c == ' ') {
            i++;
            s.push_back(buf);
            buf.clear();
            continue;
        }
        buf+=c;
    }
    s.push_back(buf);
    i=0;
    int a,b;

    while(s.size()!=1) {
        i++;
        if (!IsOp(s[i][0]) && !IsOp(s[i + 1][0])) {
            a = stoi(s[i]);
            b = stoi(s[i + 1]);
            switch (s[i - 1][0]) {
                case '+': {
                    a += b;
                    break;
                }
                case '-': {
                    a -= b;
                    break;
                }
                case '*': {
                    a *= b;
                    break;
                }
                case '/': {
                    a /= b;
                    break;
                }
            }
            s[i - 1] = to_string(a);
            s.erase(s.begin() + i, s.begin() + i + 2);
            i=0;
        }
    }
    cout<<s[0];
    return 0;
}