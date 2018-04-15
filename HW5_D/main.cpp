#include<iostream>
#include<vector>
#include<iterator>

void prop(std::vector<int>& arr, unsigned i)
{
	if (i == 1) return;
	arr[i >> 1] = arr[i] ^ arr[i ^ 1];
	prop(arr, i >> 1);
}

int op_xor(std::vector<int>& arr, unsigned left, unsigned right)
{
	int res = 0;
	if (left & 1) res ^= arr[left++];
	if (!(right & 1)) res ^= arr[right--];
	if (right > left) res ^= op_xor (arr, left >> 1, right >> 1);
	return res;
}

int main()
{
	unsigned n, m, code, l, r, c;
	std::vector<int> arr;
	std::vector<int> res;
	std::cin>>n>>m;
	for (code = 1; (n - 1) >> code > 0; ++code);
	c = (1 << code);
	arr.reserve(c << 1);
	for (int i = 0; i < n; ++i)
	{
		std::cin>>arr[i+c];
		prop(arr, i+c);
	}
	for (int i = 0; i < m; ++i)
	{
		std::cin>>code>>l>>r;
		if (code==1)
		{
			arr[c + l] = r;
			prop(arr, c + l);
			res.push_back(op_xor (arr, c + l, c + r));
		}
		else
		{
            arr[c + l] = r;
			prop(arr, c + l);
		}
	}
	std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, "\n"));
	return 0;
}
