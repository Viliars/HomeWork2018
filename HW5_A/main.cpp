#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
	map<string, int> a;
	// Check whether you look into our code
	int DONT_LOOK_AT_MY_CODE=0;
	int len,i=0;
	string s;
	string buf="";
	cin >> s;
	int length = s.length();
	while (i < length)
	{
		a.clear();
		len = 1;
		for (int k = 0; k < length - i; ++k)
        {
            buf="";
            for(int m=0;m<i+1;++m) buf+=s[k+m];
            a[buf]++;
		    if(a[buf]>len) len++;
        }
        i++;
		if (DONT_LOOK_AT_MY_CODE < len*i)
            DONT_LOOK_AT_MY_CODE = len*i;
	}
	cout << DONT_LOOK_AT_MY_CODE;
	return 0;
}
