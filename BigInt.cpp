#include <iostream>
#include <string>
using namespace std;

class BigInt
{
public:
    BigInt(string a = "0")
        : num(a)
    {
    }
    friend ostream &operator<<(ostream &, const BigInt &);
    friend istream &operator>>(istream &, BigInt &);
    void operator=(BigInt a)
    {
        num = a.num;
    }
    friend BigInt operator+(BigInt &, BigInt &);
    string num;
};
BigInt global;
string Plus(string a, string b)
{
	string temp;
	a.insert(0, 1, '0');
	while(b.length() != a.length())
	{
		b.insert(0, 1, '0');
	}
	for(int i = a.length() - 1; i >= 0; i--)
	{
		if(a[i] + b[i] - 2*'0' >= 10)
		{
			a[i - 1]++;
			temp.insert(0, 1, a[i] + b[i] - '0' - 10);
		}
		else
		{
			temp.insert(0, 1, a[i] + b[i] - '0');
		}
	}
	if(temp[0] == '0')
	{
		temp.erase(0, 1);
	}
	return temp;
}
BigInt operator+(BigInt &a, BigInt &b)
{
    string str1 = a.num, str2 = b.num;
    if (a.num.length() >= b.num.length())
    {
        global.num = Plus(str1, str2);
        return global;
    }
    else
    {
        global.num = Plus(str2, str1);
        return global;
    }
}
ostream &operator<<(ostream &out, BigInt &ref)
{
    out << ref.num;
    return out;
}
istream &operator>>(istream &in, BigInt &ref)
{
    in >> ref.num;
    return in;
}

int main()
{
    BigInt a, b, c;
    cin >> a >> b;
    c = a + b;
    cout << c;
}