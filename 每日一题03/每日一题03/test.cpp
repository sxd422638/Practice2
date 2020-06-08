//题目一
//读入一个字符串str，输出字符串str中的连续最长的数字串
//输入描述 :
//个测试输入包含1个测试用例，一个字符串str，长度不超过255。
//输出描述 :
//在一行内输出str中里连续最长的数字串。
//示例1
//输入
//abcd12345ed125ss123456789
//
//输出
//123456789
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str, cur, res;
	cin >> str;
	for (size_t i = 0; i <= str.size(); ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			cur += str[i];
		}
		else
		{
			if (res.size() < cur.size())
			{
				res = cur;
			}
			else
			{
				cur.clear();
			}
		}


	}


	cout << res << endl;
	return 0;
}



//题目二
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{ 1,2,3,2,2,2,5,4,2 }。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
//如果不存在则输出0。
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		// 因为用到了sort，时间复杂度O(NlogN)，并非最优
		if (numbers.empty()) return 0;
		sort(numbers.begin(), numbers.end()); // 排序，取数组中间那个数
		int middle = numbers[numbers.size() / 2];
		int count = 0; // 出现次数
		for (int i = 0; i<numbers.size(); ++i)
		{
			if (numbers[i] == middle) ++count;
		}
		return (count>numbers.size() / 2) ? middle : 0;
	}
};