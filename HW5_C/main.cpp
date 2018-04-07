#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define NO_DEBUG

namespace tree{
class Tree
{
	string str;
	vector<Tree*> a;
    bool flag;
    static int i;
	Tree(bool flag=0,string str="")
	{
#ifdef DEBUG
cout<<"Constuctor\n";
#endif // DEBUG
	    this->flag=flag;
	    this->str=str;
	}
	~Tree()
	{
#ifdef DEBUG
cout<<"Destructor\n";
#endif // DEBUG
	}
	friend void run(string&);

// reverse
	void reverse_tree()
	{
#ifdef DEBUG
cout<<"Reverse\n";
#endif // DEBUG
        if (this->a.empty()==0)
            {
                Tree* buf;
                int n=this->a.size();
                for(int i=0;i<n/2;++i)
                {
                    buf=this->a[i];
                    this->a[i]=this->a[n-i-1];
                    this->a[n-i-1]=buf;
                }
                for (auto& x:a) x->reverse_tree();
            }
        else
            this->flag = !this->flag;
	}


// cmp
    string func()
    {
#ifdef DEBUG
cout<<"Func\n";
#endif // DEBUG
        if (this->a.empty()==0)
        {
            string buf = "";
            for (auto& x:this->a) buf+=x->func();
#ifdef DEBUG
cout<<"buf = "<<buf<<endl;
#endif // DEBUG
            return buf;
        }
        else
        {
            if(this->flag) reverse(this->str.begin(),this->str.end());
#ifdef DEBUG
cout<<"res = "<<this->str<<endl;
#endif // DEBUG
            return this->str;
        }
    }


// create_tree
    static Tree* create_tree(string& s)
    {
#ifdef DEBUG
cout<<"Create_tree\n";
#endif // DEBUG
        Tree* bufer = new Tree();
        int n=s.length();
        bufer->i++;
        if (s[bufer->i]=='(')
        {
            Tree* buf=create_tree(s);
            while (s[bufer->i++]==',')
            {
#ifdef DEBUG
cout<<s[bufer->i-1]<<endl;
#endif // DEBUG
                bufer->a.push_back(buf);
                buf=create_tree(s);
            }
            bufer->a.push_back(buf);
            if((bufer->i<n)&&(s[bufer->i]=='R')) { bufer->i++; bufer->reverse_tree(); }
        }
        else
        {
#ifdef DEBUG
cout<<s[bufer->i]<<endl;
#endif // DEBUG
            while(s[bufer->i]!=')') bufer->str+=s[bufer->i++];
            bufer->i++;
            if((bufer->i<n)&&(s[bufer->i]=='R')) { bufer->i++; bufer->reverse_tree(); }
        }
        return bufer;
    }

};

void run(string& s)
{
    Tree* kek;
    kek=Tree::create_tree(s);
    cout<<kek->func();
}

int Tree::i=0;
}


using namespace tree;
int main()
{
	string s;
	cin>>s;
	run(s);
	return 0;
}
