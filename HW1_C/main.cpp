#include <iostream>
#include <cstdio>
#include <string>
using namespace std;



int main() {
int rez[4];
char c;
    bool flag[4];
    string str="'''''";
    const char z=str[0];
    char pred='1';
    for(int i=0;i<4;i++) {  rez[i]=0; flag[i]=false; }
while(scanf("%c",&c)>0)
{
if(!(flag[0]||flag[1]||flag[2]||flag[3]))
{
    if(c=='*'&&pred=='(') flag[0]=true;
    if(c=='{') flag[1]=true;
    if(c=='/'&&pred=='/') flag[2]=true;
    if(c==z) flag[3]=true;
}
else {
    if(flag[0]&&pred=='*'&&c==')') { flag[0]=false; rez[0]++; }
    if(flag[1]&&c=='}') { flag[1]=false; rez[1]++; }
    if(flag[2]&&c=='\n') { flag[2]=false; rez[2]++; }
    if(flag[3]&&c==z) { flag[3]=false; rez[3]++; }
}
pred=c;
}
for(int i=0;i<4;i++) cout<<rez[i]<<" ";

return 0;
}
