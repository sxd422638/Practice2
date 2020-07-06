//题目一:
//Fibonacci数列是这样定义的：
//F[0] = 0
//F[1] = 1
//for each i ≥ 2: F[i] = F[i - 1] + F[i - 2]
//因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X - 1或者X + 1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。
//输入描述 :
//输入为一个正整数N(1 ≤ N ≤ 1, 000, 000)

//输出描述 :
//	输出一个最小的步数变为Fibonacci数"
//	示例1
//	输入	15
//	输出	2

//【题目解析】:
//本题是对于Fibonacci数列的一个考察，Fibonacci数列的性质是第一项和第二项都为1，后面的项形成递归：
//F(n) = F(n - 1) + F(n - 2)。
//【解题思路】:
//本题可以通过先找到距离N最近的两个Fibonacci数，这两个数分别取自距离N的最近的左边一个数L和右边一
//个数R，然后通过min(N - L, R - N)找到最小步数。




#include <iostream>
using namespace std;
int main() {
	int N, f, l = 0, r = 0, f0 = 0, f1 = 1;
	cin >> N;
	while (1) {
		f = f0 + f1;
		f0 = f1;
		f1 = f;
		//找到比N小且距离N最近的数，求出距离
		if (f < N)
			l = N - f;
		else
		{
			//找到比N大且距离N最近的数，求出距离
			r = f - N;
			break;
		}
	}
	//取最小距离
	cout << min(l, r) << endl;
	return 0;
}





//题目二：
//对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
//
//给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。
//
//测试样例：
//"(()())", 6
//返回：true

//测试样例：
//"()a()()", 7
//返回：false

//测试样例：
//"()(()()", 7
//返回：false

//本题考查的是对栈的应用
//【解题思路】：

//可以利用栈把左括号保存，每次遇见右括号就出栈一个，
//此时如果栈空就为false, 遍历期间遇见不是括号也为false，直到遍历结束且栈为空就返回true

#include<iostream>
#include<stack>
using namespace std;

class Parenthesis 
{
public:
	bool chkParenthesis(string A, int n) 
	{
		// write code here
		if (n % 2 == 1)//先排除奇数情况
			return false;

		stack<char> s1;
		for (int i = 0; i < A.size() ;  i++)
		{
			if (A[i] == '(')
				s1.push(A[i]);
			else if (A[i] == ')')
			{
				if (s1.empty())
					return false;
				s1.pop();
			}
			else
				return false;
		}
		if (s1.empty())
			return true;
	}
};