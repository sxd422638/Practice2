//题目一
//将一句话的单词进行倒置，标点不倒置。比如 I like beijing.经过函数后变为：beijing.like I
//输入描述 :
//每个测试输入包含1个测试用例： I like beijing.输入用例长度不超过100
//输出描述 :
//依次输出倒置之后的字符串, 以空格分割
//示例1
//输入
//
//I like beijing.
//输出
//
//beijing.like I
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	reverse(s.begin(), s.end());//此时翻转了整个句子
	auto start = s.begin();      //翻转单词 先找到空格的位置 然后再用reverse翻转单词 如果没有结束 就继续 结束可就跳出循环
	while (start != s.end())
	{
		auto end = start;
		while (end != s.end() && *end != ' ')
			end++;
		reverse(start, end);
		if (end != s.end())
			start = end + 1;
		else
			break;
	}
	cout << s << endl;
	return 0;
}