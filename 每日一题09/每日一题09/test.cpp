//题目一：
//	考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 1.根据字符串的字典序排序。例如：
//"car" < "carriage" < "cats" < "doggies < "koala"
//	2.根据字符串的长度排序。例如：
//	"car" < "cats" < "koala" < "doggies" < "carriage"
//	考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。
//	输入描述 :
//
//输入第一行为字符串个数n(n ≤ 100)
//接下来的n行, 每行一个字符串, 字符串长度均小于100，均由小写字母组成
//输出描述 :
//如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically",
//
//如果根据长度排列而不是字典序排列输出"lengths",
//
//如果两种方式都符合输出"both"，否则输出"none"
//
//示例1
//输入
//3
//a
//aa
//bbb
//
//输出
//
//both



#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{	
	int n; 
	cin >> n;
	vector <string> v;
	v.resize(n);
	for (auto&str : v)
		cin >> str;
	bool lenSym = true, lexSym = true;
	for (size_t i = 1; i < v.size(); i++)
	{
		if (v[i - 1].size() > v[i].size())
		{
			lenSym = false;
			break;

		}
	}
	//比较ASCII码
	for (size_t i = 1; i < v.size(); ++i)
	{
		if (v[i - 1] >= v[i])
		{
			lexSym = false;
			break;
		}
	}
	if (lenSym&& lexSym)
		cout << "both" << endl;
	else if (!lenSym && lexSym)
		cout << "lexicographically" << endl;
	else if (lenSym && !lexSym)
		cout << "lengths" << endl;
	else if (!lenSym && !lexSym)
		cout << "none" << endl;
	return 0;
}

//
//题目二：
//正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。
//
//输入描述 :
//输入两个正整数A和B。
//
//输出描述 :
//输出A和B的最小公倍数。
//
//示例1
//输入
//
//5 7
//输出
//
//35
//
//【解题思路】：
//最小公倍数 = 两数之积除以最大公约数，这里使用碾转相除法进行最大公约数的求解：即a与b的最大公约数
//可以转化为a、b之间的余数为两者之间最小的数之间的公约数。所以对于输入的两个数进行连续求余，直到
//余数为0，求余的分母即为结果。
//


//先求最大公约数
int max_com_div(int x, int y)
{
	//辗转相除法  //余数，当余数为0的时候，最后的x即为最大公约数
	//先用较小的数对较大的数取余，再用余数对较小的数求余，直到余数为零 
	int rem = 0;
	while (y != 0)
	{
		rem = x % y;
		x = y;
		y = rem;
	}
	return x;
}
//最小公倍数
int min_com_multi()
{
	int m, n;
	cin >> m >> n;

	return m * n / max_com_div(m, n);
}
