#include <iostream>
#include <vector>
#include <map>
#include <set>
typedef unsigned long long ull;

unsigned search(std::vector<ull>&,unsigned, unsigned, std::set<ull>::iterator, std::map<ull,unsigned>&);
unsigned n,max;
void mk_sm(std::vector<ull>& a,std::set<ull>& buf,std::map<ull,unsigned>& mapa,unsigned s,std::set<ull>::iterator z,unsigned i)
{
    auto it2=z++;
    unsigned bufer=s;
    for (;z!=buf.end();++z)
        {
            unsigned s=search(a,i,max,z,mapa);
            if (s==max){ buf.erase(z); break; }
            else if (s>bufer) bufer=s,it2=z;
        }
    if (buf.size() == n) buf.erase(it2);
}

void do_sm(std::vector<ull>& a,std::set<ull>& buf,std::map<ull,unsigned>& mapa,unsigned i)
{
    auto it = buf.begin();
    unsigned s = search(a,i,max,it,mapa); ;
    if (s==max) buf.erase(it);
    else mk_sm(a,buf,mapa,s,it,i);
    buf.insert(a[i]);
}

unsigned search(std::vector<ull>& a,unsigned left, unsigned right, std::set<ull>::iterator z, std::map<ull,unsigned>& mapa)
{
	auto buf = mapa.find(*z); left++;
	if ((buf != mapa.end()) && ((*buf).second>=left)) return (*buf).second;
	for (unsigned i=left;i!=right;++i) if (a[i]==*z){ ((buf!=mapa.end()) ? (*buf).second=i :  mapa[*z]=i); return i; }
	return mapa[*z] = right;
}


int main()
{
	std::cin>>n>>max;
	std::vector<ull> a(max);
	std::set<ull> buf;
	std::map<ull,unsigned> mapa;
    unsigned res=0;
	for (auto& x : a) std::cin>>x;
	for (unsigned i=0;i!=max;++i) if (buf.find(a[i])==buf.end()) { if (buf.size()<n) buf.insert(a[i]),res++; else do_sm(a,buf,mapa,i),res++; }
	std::cout<<res;
	return 0;
}
