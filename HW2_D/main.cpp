#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    const int BASE = 20010000;
    const int SIZE = BASE / 8 + 1;
    const int BS = 8;
    int m, k = 0;
    int n, c = 1;
    cin >> m >> n;
    if (m > n)
    {
        cout << -1;
        return 0;
    }
    vector<char> prime(BASE+1,true);
    prime[0] = prime[1] = false;
    for (int i=2;i<=BASE; ++i)
        if (prime[i])
            if (i*1ll*i<=BASE)
                for (int j = i*i;j<=BASE;j+=i)
                    prime[j] = false;


    vector<char> set(SIZE, false);
    for (int i=0;i<BASE+1;i++)
    {
        set[i/BS] = set[i/BS]|(prime[i]<<i%BS);
    }
    vector<char>().swap(prime);
    vector<int> array;
    array.push_back(1);
    int b = 0;
    for (int i=0;i<BASE+1;i++){
        if (set[i/BS]&1<<i%BS) array.push_back(i);
        if ((c!=0)&&(i>20000000))
        {
            c = 0;
            b =array.size();
        }
    }

    int z1, z2;
    int siz = array.size();
    c = m;
    for (int i = 1; i<b; i++, c++){
        if (c+1>siz){
            cout << -1;
            return 0;
        }
        if (array[c] >= array[i] + n) continue;
        if (array[c + 1] >= array[i] + n) k = array[i];
        else if (array[c + 1] >= array[i - 1]+n+1) k=array[c + 1]-n;
        else k = 0;
        if (k) {
            for (int count =array[i - 1]+1 ; count <= array[c + 1]-n+1; count++) {
                z1 = (int)(lower_bound(array.begin(), array.end(), count) - array.begin());
                z2 = (int)(lower_bound(array.begin(), array.end(), count + n) - array.begin());
                if ((z2 - z1) == m) { cout << count;  return 0; }
            }

            break;
        }
    }
    cout << -1;
    return 0;
}