#include <iostream>
using namespace std;

int main()
{
    int n;
    int p=0;
    int rez=0;
    int a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a==5) p+=5;
        else {
            if(a-5>p) { rez+=(a-5)-p; p=0; }
            else p-=(a-5);
        }
    }
    cout<<rez/5;

    return 0;
}