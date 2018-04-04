#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;
int sizeS;
class big_integer {
    // основание системы счисления (1 000 000 000)
    static const int BASE = 1000000000;

    // внутреннее хранилище числа
    std::vector<int> _digits;

    // знак числа
    bool _is_negative;

    void _remove_leading_zeros();
    void _shift_right();

public:
    big_integer();
    big_integer(string);
    big_integer(int);
    friend ostream& operator <<(ostream&, const big_integer&);
    operator string() const;
    const big_integer operator +() const;
    const big_integer operator -() const;
    friend const big_integer operator *(const big_integer&, const big_integer&);
    friend bool operator ==(const big_integer&, const big_integer&);
    friend bool operator <(const big_integer&, const big_integer&);
    friend bool operator !=(const big_integer&, const big_integer&);
    friend bool operator <=(const big_integer&, const big_integer&);
    friend bool operator >(const big_integer&, const big_integer&);
    friend bool operator >=(const big_integer&, const big_integer&);
    friend const big_integer operator +(big_integer, const big_integer&);
    big_integer& operator +=(const big_integer&);
    friend const big_integer operator -(big_integer, const big_integer&);
    big_integer& operator -=(const big_integer&);
    friend big_integer sqrt(const big_integer&);
    big_integer& operator /=(int b);
};

// создает длинное целое число со значением 0
big_integer::big_integer() {
    this->_is_negative = false;
}

// КОНСТРУКТОР ИЗ STRING
big_integer::big_integer(string str) {
    if (str.length() == 0) {
        this->_is_negative = false;
    }
    else {
        if (str[0] == '-') {
            str = str.substr(1);
            this->_is_negative = true;
        }
        else {
            this->_is_negative = false;
        }

        for (long long i = str.length(); i > 0; i -= 9) {
            if (i < 9)
                this->_digits.push_back(atoi(str.substr(0, i).c_str()));
            else
                this->_digits.push_back(atoi(str.substr(i - 9, 9).c_str()));
        }

        this->_remove_leading_zeros();
    }
}

big_integer::big_integer(int i) {
    if (i < 0) this->_is_negative = true;
    else this->_is_negative = false;
    this->_digits.push_back(std::abs(i) % big_integer::BASE);
    i /= big_integer::BASE;
    if (i != 0) this->_digits.push_back(abs(i));
}

// УДАЛИМ НУЛИ
void big_integer::_remove_leading_zeros() {
    while (this->_digits.size() > 1 && this->_digits.back() == 0) {
        this->_digits.pop_back();
    }

    if (this->_digits.size() == 1 && this->_digits[0] == 0) this->_is_negative = false;
}

const big_integer operator *(const big_integer& left, const big_integer& right) {
    big_integer result;
    result._digits.resize(left._digits.size() + right._digits.size());
    for (size_t i = 0; i < left._digits.size(); ++i) {
        int carry = 0;
        for (size_t j = 0; j < right._digits.size() || carry != 0; ++j) {
            long long cur = result._digits[i + j] +
                            left._digits[i] * 1LL * (j < right._digits.size() ? right._digits[j] : 0) + carry;
            result._digits[i + j] = (int)(cur % big_integer::BASE);
            carry = (int)(cur / big_integer::BASE);
        }
    }

    result._is_negative = left._is_negative != right._is_negative;
    result._remove_leading_zeros();
    return result;
}

// ВЫВОД
ostream& operator <<(ostream& os, const big_integer& bi) {
    if (bi._digits.empty()) os << 0;
    else {
        if (bi._is_negative) os << '-';
        os << bi._digits.back();
        char old_fill = os.fill('0');
        for (long long i = (long long)(bi._digits.size()) - 2; i >= 0; --i) os << setw(9) << bi._digits[i];
        os.fill(old_fill);
    }

    return os;
}

// сравнивает два числа на равенство
bool operator ==(const big_integer& left, const big_integer& right) {
    if (left._is_negative != right._is_negative) return false;
    if (left._digits.empty()) {
        if (right._digits.empty() || (right._digits.size() == 1 && right._digits[0] == 0)) return true;
        else return false;
    }

    if (right._digits.empty()) {
        if (left._digits.size() == 1 && left._digits[0] == 0) return true;
        else return false;
    }

    if (left._digits.size() != right._digits.size()) return false;
    for (size_t i = 0; i < left._digits.size(); ++i) if (left._digits[i] != right._digits[i]) return false;

    return true;
}

// возвращает копию переданного числа
const big_integer big_integer::operator +() const {
    return big_integer(*this);
}

// возвращает переданное число с другим знаком
const big_integer big_integer::operator -() const {
    big_integer copy(*this);
    copy._is_negative = !copy._is_negative;
    return copy;
}

// проверяет, является ли левый операнд меньше правого
bool operator <(const big_integer& left, const big_integer& right) {
    if (left == right) return false;
    if (left._is_negative) {
        if (right._is_negative) return ((-right) < (-left));
        else return true;
    }
    else if (right._is_negative) return false;
    else {
        if (left._digits.size() != right._digits.size()) {
            return left._digits.size() < right._digits.size();
        }
        else {
            for (long long i = left._digits.size() - 1; i >= 0; --i) {
                if (left._digits[i] != right._digits[i]) return left._digits[i] < right._digits[i];
            }

            return false;
        }
    }
}

// сравнивает два числа на неравенство
bool operator !=(const big_integer& left, const big_integer& right) {
    return !(left == right);
}

// проверяет, является ли левый операнд меньше либо равен правого
bool operator <=(const big_integer& left, const big_integer& right) {
    return (left < right || left == right);
}

// проверяет, является ли левый операнд больше правого
bool operator >(const big_integer& left, const big_integer& right) {
    return !(left <= right);
}

// проверяет, является ли левый операнд больше либо равен правого
bool operator >=(const big_integer& left, const big_integer& right) {
    return !(left < right);
}

// складывает два числа
const big_integer operator +(big_integer left, const big_integer& right) {
    if (left._is_negative) {
        if (right._is_negative) return -(-left + (-right));
        else return right - (-left);
    }
    else if (right._is_negative) return left - (-right);
    int carry = 0;
    for (size_t i = 0; i < std::max(left._digits.size(), right._digits.size()) || carry != 0; ++i) {
        if (i == left._digits.size()) left._digits.push_back(0);
        left._digits[i] += carry + (i < right._digits.size() ? right._digits[i] : 0);
        carry = left._digits[i] >= big_integer::BASE;
        if (carry != 0) left._digits[i] -= big_integer::BASE;
    }

    return left;
}

// прибавляет к текущему числу новое
big_integer& big_integer::operator +=(const big_integer& value) {
    return *this = (*this + value);
}

// преобразует число к строке
big_integer::operator string() const {
    std::stringstream ss;
    ss << *this;
    return ss.str();
}

big_integer& big_integer::operator/=(int b)
{
int carry = 0;
for (int i=(int)_digits.size()-1; i>=0; --i) {
	long long cur = _digits[i] + carry * 1ll * BASE;
	_digits[i] = int (cur / b);
	carry = int (cur % b);
}
return *this;
//while (a.size() > 1 && a.back() == 0)
//	a.pop_back();
}

big_integer sqrt(const big_integer& another)
{
    string s1(sizeS/2-1,'0');
    string s2((sizeS+1)/2,'0');
    string s3='1'+s1;
    string s4='1'+s2;
    //cout<<"LEN = "<<sizeS<<endl;
    big_integer l(s3) , r(s4);
    big_integer m,res;
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
}
// вычитает два числа
const big_integer operator -(big_integer left, const big_integer& right) {
    if (right._is_negative) return left + (-right);
    else if (left._is_negative) return -(-left + right);
    else if (left < right) return -(right - left);
    int carry = 0;
    for (size_t i = 0; i < right._digits.size() || carry != 0; ++i) {
        left._digits[i] -= carry + (i < right._digits.size() ? right._digits[i] : 0);
        carry = left._digits[i] < 0;
        if (carry != 0) left._digits[i] += big_integer::BASE;
    }

    left._remove_leading_zeros();
    return left;
}

// вычитает из текущего числа новое
big_integer& big_integer::operator -=(const big_integer& value) {
    return *this = (*this - value);
}

typedef big_integer BigInt;


int main()
{

   string s1;
   cin>>s1;
   sizeS=s1.size();
   BigInt a(s1);
   cout<<sqrt(a);
    return 0;

}
