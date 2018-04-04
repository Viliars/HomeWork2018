#include<iostream>
#include<string>
#include<vector>

using namespace std;
int sizeS;
struct BigInteger
{
	vector<int> value; // ������ ������� - ����� ����� � ������� ��������� � ���������� base,
					   //�� ������� � �������, �.�. � value[0] �������� ����� ������, ��� 0 ������ ������.
					   //��� ������������� ������ ��� ����� ����������� �� -1
	static const int base = 1000000000;
	static const int bpow = 9;
	int sign; //�������� � ������� 1 ��� -1, ��� ���� ������ 1
	BigInteger(int sign_, const vector<int>& value_);
	BigInteger() : BigInteger(1, vector<int>()) {}
	BigInteger(string str);  // �� ������
	BigInteger(long long v); // �� ����� (��������� � ��� ����������)
	size_t       Size(); // ���������� ���� (������ �������)
	string       ToString();
	void         Swap(BigInteger & another);
	bool         IsZero(); // ��� � �������� ���������� ����
	BigInteger   MulNative(BigInteger & another); // �������� ���������
	BigInteger   operator +  (); // ������� + �� ������ ������
	BigInteger   operator -  (); // ������� -
	BigInteger   operator +  (BigInteger & another);// �������� + �������� ��� ����� ����� ������
	BigInteger   operator -  (BigInteger & another);// �������� - ���������� ����� ������� - � �������� +
	BigInteger & operator += (BigInteger & another);// ������������ �� ���������, ����� ����, ��� ������ �������
};

BigInteger::BigInteger(int sign_, const vector<int>& value_)
{
	sign = sign_;
	value = vector<int>(value_);
	IsZero();
}
BigInteger::BigInteger(string str)
{
	value = vector<int>();
	sign = (str[0] >= '0' && str[0] <= '9') ? 1 : (str[0] == '-') ? -1 : 1;  // ���������� ���� � ����� � ������ �� 1 �������
	if (str[0] < '0' || str[0] > '9') str = str.substr(1, str.length() - 1); // � ������� ��� �� ������ ������ ���� ����
	for (int i = str.length(); i > 0; i -= bpow)
	{
		if (i < bpow) value.push_back(sign * atoi(str.substr(0, i).c_str()));  //�������� �� bpow ���� ���������
		else value.push_back(sign * atoi(str.substr(i - bpow, bpow).c_str()));
	}
	IsZero(); // �������� ���������� ����
}
BigInteger::BigInteger(long long v)
{
	sign = (v >= 0) ? 1 : -1;
	value = vector<int>();
	while (v != 0)
	{
		value.push_back(v % base);
		v /= base;
	}
}
BigInteger   BigInteger::operator +  ()
{
	return *this;
}
BigInteger   BigInteger::operator -  ()
{
	BigInteger res = BigInteger();
	size_t sz = this->Size();
	res.value.reserve(sz);
	for (size_t i = 0; i < sz; ++i) res.value.push_back(-value[i]); //�� �������� ���������� � ���� ������ ����
	res.sign = -sign;
	return res;
}
BigInteger   BigInteger::operator +  (BigInteger & another)
{
	int carry = 0;
	size_t sz1 = value.size(), sz2 = another.value.size(), sz = (sz1 > sz2) ? sz1 : sz2; //���������� ������������ ������
	BigInteger res(1, vector<int>(sz));
	for (size_t i = 0; i < sz; ++i) res.value[sz] = ((i < sz1) ? value[i] : 0) + ((i < sz2) ? another.value[i] : 0); // ��������� ��� carry
	if (sign + another.sign) //������� � �������� carry ��� ���������� ������
	{
		res.sign = sign;
		for (size_t i = 0; i < sz; ++i)
		{
			res.value[i] += carry * sign; //����� res.sign, �� ��� ����� � ������ �������
			carry = sign * res.value[i] >= base;
			if (carry) res.value[i] -= base * sign;
		}
		if (carry) res.value.push_back(1);
	}
	else //������� � �������� carry ��� ������ ������
	{
		if (res.IsZero()) return res;
		sz = res.Size();
		res.sign = (res.value[sz - 1] > 0) ? 1 : -1;
		for (size_t i = 0; i < sz; ++i)
		{
			res.value[i] -= carry * res.sign;
			carry = res.sign * res.value[i] < 0;
			if (carry) res.value[i] += base * res.sign;
		}
		res.IsZero();
	}
	return res;
}
BigInteger   BigInteger::operator -  (BigInteger & another)
{
	BigInteger res = -another;
	res = *this + res;
	return res;
}
BigInteger & BigInteger::operator += (BigInteger & another)
{
	int carry = 0;
	size_t sz2 = another.value.size(), sz = (value.size() > sz2) ? value.size() : sz2; //���������� ������������ ������
	for (size_t i = 0; i < sz; ++i) // ��������� ��� carry
	{
		if (i == value.size()) value.push_back(0);
		value[i] += (i < sz2) ? another.value[i] : 0;
	}
	if (sign + another.sign) //������� � �������� carry ��� ���������� ������
	{
		for (size_t i = 0; i < sz; ++i)
		{
			value[i] += carry * sign;
			carry = sign * value[i] >= base;
			if (carry) value[i] -= base * sign;
		}
		if (carry) value.push_back(1);
	}
	else //������� � �������� carry ��� ������ ������
	{
		if (IsZero()) return *this;
		sz = value.size();
		sign = (value[sz - 1] > 0) ? 1 : -1;
		for (size_t i = 0; i < sz; ++i)
		{
			value[i] -= carry * sign;
			carry = sign * value[i] < 0;
			if (carry) value[i] += base * sign;
		}
		IsZero();
	}
	return *this;
}
size_t       BigInteger::Size()
{
	return value.size();
}
bool         BigInteger::IsZero()
{
	while (value.size() > 0 && value.back() == 0) value.pop_back(); // ������� ���������� ����
	if (value.size() == 0)
	{
		sign = 1;
		return 1;
	}
	return 0;
}
string       BigInteger::ToString()
{
	string res = (sign > 0) ? "" : "-", s;
	size_t sz = Size();
	for (int i = sz - 1; i >= 0; --i) // �������� ��������� �������������, �� �������� ��� - � ����
	{
		s = to_string(sign * value[i]);
		if (i < sz - 1) for (int j = 0; j < bpow - s.length(); ++j) res += "0";
		res += s;
	}
	if (res == "") res = "0";
	return res;
}
void         BigInteger::Swap(BigInteger & another)
{
	swap(sign, another.sign);
	value.swap(another.value);
}
BigInteger   BigInteger::MulNative(BigInteger & another)
{
	if (IsZero() || another.IsZero()) return BigInteger(0);
	size_t sz1 = value.size(), sz2 = another.value.size(), sz = (sz1 * sz2); // ���������� �������
	long long cur;
	BigInteger c(1, vector<int>(sz));
	for (size_t i = 0; i < sz1; ++i)
		for (size_t j = 0, carry = 0; j < sz2 || carry; ++j)
		{
			cur = c.value[i + j] + value[i] * 1ll * (j < sz2 ? another.value[j] : 0) + carry;
			c.value[i + j] = int(cur % base);
			carry = int(cur / base);
		}
	c.IsZero();
	return c;
}

BigInteger sqrt(const BigInteger& another)
{
    string s1(sizeS/2-1,'0');
    string s2((sizeS+1)/2,'0');
    string s3='1'+s1;
    string s4='1'+s2;
    //cout<<"LEN = "<<sizeS<<endl;
    BigInteger l(s3) , r(s4);
    cout<<l<<" "<<r<<endl;
    BigInteger m,res;
    while (l<=r)
    {
      m=(l + r);
      m/=2;
      if (m*m <= another)
      {
        res=m;
        l = m + 1;
      }
      else
        r = m - 1;
    }
    return res;

typedef BigInteger BInt;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
