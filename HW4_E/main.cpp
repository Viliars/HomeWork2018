#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
namespace hull{
    typedef int uint;
    const uint FF=256;
    const uint FE=255;
    const uint eight=8;

    class Point {
        public:
            uint x,y;
            Point(uint x=0,uint y=0) { this->x=x; this->y=x; }
            bool operator <(const Point& another)
            {
                return (x < another.x) || ((x == another.x) && (y < another.y));
            }
             friend std::istream& operator >> ( std::istream& os, Point& obj);
             friend std::ostream& operator << ( std::ostream& os, Point& obj);
    };

    std::istream& operator >> ( std::istream& os, Point& obj)
    {
    os>>obj.x>>obj.y;
    return os;
    }

    std::ostream& operator << ( std::ostream& os, Point& obj)
    {
    os<<obj.x<<std::endl<<obj.y;
    return os;
    }

    bool ClockWise (const Point& a,const Point& b,const Point& c)
    {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
    }

    bool CounterClockWise (const Point& a,const Point& b,const Point& c)
    {
        return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
    }

    void convex_hull (std::vector<Point> & a)
    {
        if (a.size() == 1)  return;
        sort(a.begin(),a.end());
        Point p1 = a[0],  p2 = a.back();
        std::vector<Point> up, down;
        up.push_back (p1);
        down.push_back (p1);
        for (size_t i=1; i<a.size(); ++i)
        {
            if (i==a.size()-1 || ClockWise(p1, a[i], p2))
            {
                while (up.size()>=2 && !ClockWise(up[up.size()-2], up[up.size()-1], a[i])) up.pop_back();
                up.push_back (a[i]);
            }
            if (i==a.size()-1 || CounterClockWise(p1, a[i], p2))
            {
                while (down.size()>=2 && !CounterClockWise(down[down.size()-2], down[down.size()-1], a[i])) down.pop_back();
                down.push_back (a[i]);
            }
        }
        a.clear();
        for (size_t i=0; i<up.size(); ++i) a.push_back (up[i]);
        for (size_t i=down.size()-2; i>0; --i) a.push_back (down[i]);
    }

}

using namespace std;
using namespace hull;

int sqr(int x)
{
    return x*x;
}


bool onLine(Point& a,Point& b,Point& c){
return ((c.x-a.x)*(b.y-a.y))==((b.x-a.x)*(c.y-a.y));
}

int main()
{
    vector<Point> a;
    Point c;
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>c;
        a.push_back(c);
    }
    convex_hull(a);
    double per=0;
    cout.precision(3);
    for(size_t i=1;i<a.size();++i)
    {
        per+=sqrt(sqr(a[i].x-a[i-1].x)+sqr(a[i].y-a[i-1].y));
    }
    int flag=0;
    for(size_t i=2;i<a.size();++i)
    {
        flag+=(int)onLine(a[0],a[1],a[i]);
    }
    flag+=2;
    if(flag!=(int)a.size()) per+=sqrt(sqr(a[a.size()-1].x-a[0].x)+sqr(a[a.size()-1].y-a[0].y));
    printf("%.2f\n", per);
    return 0;
}
