#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    //cout<<(long long)(30000*30000*sizeof(char))/(1024*1024);
    cout<<(long long)(64*1024*1024)/(sizeof(char)*30000);

    string s1,s2;
    cin>>s1;
    cin>>s2;
/*
    char* A=new char[30000];
    strcpy(A,s1.c_str());
    char* B=new char[30000];
    strcpy(B,s2.c_str());
*/
    vector<vector<int> > L(s1.length()+1);
	for(int i=0;i<L.size();++i)
        for(int j=0;j<s2.length()+1;++j) L[i].push_back(0);

	for ( int i = 1; i<=s1.length(); ++i)
	    for ( int j = 1; j<=s2.length(); ++j)
            {
                //std::cout<<"YES"<<std::endl;
                if (s1[i-1] == s2[j-1])  L[i][j] = 1 + L[i-1][j-1];
            }
/*
        for(int i = 0;i<L.size();++i)
        {
            for(int j=0;j<L[i].size();++j)
                cout<<L[i][j]<<" ";
            cout<<endl;
        }*/
        vector<string> ans;
        int max=0;
        for(int i=0;i<L.size();++i)
            for(int j=0;j<L[i].size();++j)
                if(max<L[i][j])
                {
                    max=L[i][j];
                }
            for(int i=0;i<L.size();++i)
                for(int j=0;j<L[i].size();++j)
                    if(L[i][j]==max)
                {
                    string buf="";
                    for(int k=0;k<max;++k) buf+=s1[i-max+k];
                    //cout<<buf<<endl;
                    ans.push_back(buf);
                }
                cout<<*min_element(ans.begin(),ans.end());
    return 0;

}
/*std::string S = "";

     i = 0;

     j = 0;

    while (i < s1.length() && j < s2.length())

    {

	if (s1[i]==s2[j])

	{

	    S+=s1[i];

	    i++; j++;

	}

	else if (L[i+1][j] >= L[i][j+1]) i++;

	else j++;

    }
    std::cout<<S;*/
