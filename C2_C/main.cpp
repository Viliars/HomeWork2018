#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef enum{b,g,w} Color;
int res = 0;
struct Node
{
	Color color;
	int size;
	bool flag;

	vector<Node*> child;
	Node *father;

    Node(): flag(false),size(0),father(nullptr) { child.reserve(3000); }
	void Seter_Color(char c)
	{
	    switch(c)
	        {
                case 'w': color=w; break;
                case 'b': color=b; flag = true; break;
                case 'g': color=g; break;
	        }
	}
	int test()
	{
	    return (color==w) && flag;
	}
};
void start(Node* node)
{
	for (int i = 0; i < node->size; ++i) start(node->child[i]);
	res+=node->test();
}

int main()
{
    Node* node = new Node;
	string s;
	cin>>s;
    for (auto &x:s)	switch(x)
    {
        case 'g':
        case 'b':
        case 'w': node->Seter_Color(x); break;
        case '(':
                {
                    node->child[node->size] = new Node; node->child[node->size]->father = node; node->child[node->size]->flag = node->flag;
                    node = node->child[node->size]; node->father->size++;
                    break;
                }
        case ')': node = node->father;
    }
    start(node);
    cout<<res;
	return 0;
}
