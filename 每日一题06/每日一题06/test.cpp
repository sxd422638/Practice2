//题目一：
//二货小易有一个W*H的网格盒子，网格的行编号为0~H - 1，网格的列编号为0~W - 1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
//对于两个格子坐标(x1, y1), (x2, y2)的欧几里得距离为:
//((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) 的算术平方根
//小易想知道最多可以放多少块蛋糕在网格盒子里。
//输入描述 :
//每组数组包含网格长宽W, H，用空格分割.(1 ≤ W、H ≤ 1000)
//输出描述 :
//	输出一个最多可以放的蛋糕数
//	示例1
//	输入	3 2
//	输出	4
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//int main()
//{
//	int w, h, res = 0;
//	cin >> w >> h;
//	vector<vector<int>> vv;
//	vv.resize(w);
//	//for(auto& e : vv)
//	//e.resize(h,1);
//	for (size_t i = 0; i < w; ++i)
//		vv[i].resize(h, 1);
//	for (int i = 0; i<w; i++)
//	{
//		for (int j = 0; j<h; j++)
//		{
//			if (vv[i][j] == 1)
//			{
//
//				// 标记不能放蛋糕的位置
//				if ((i + 2)<w)
//					vv[i + 2][j] = 0;
//				if ((j + 2)<h)
//					vv[i][j + 2] = 0;
//				res++;
//			}
//		}
//	}
//	cout << res;
//	return 0;
//}


//题目二：
//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
//输入描述 :
//输入一个字符串, 包括数字字母符号, 可以为空
//输出描述 :
//如果是合法的数值表达则返回该数字，否则返回0
//示例1
//输入
//	+ 2147483647
//	1a33
//输出
//	2147483647
//	0
class Solution 
{
public:
	int StrToInt(string str)
	{
		if (str.empty())
			return 0;
		int symbol = 1;
		if (str[0] == '-') //处理负号
		{
			symbol = -1;
			str[0] = '0'; //这里是字符'0',不是0
		}
		else if (str[0] == '+') //处理正号
		{
			symbol = 1;
			str[0] = '0';
		}
		int sum = 0;
		for (size_t i = 0; i < str.size(); ++i)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				sum = 0;
				break;
			}
			sum = sum * 10 + str[i] - '0';
		}
		return symbol * sum;
	}
};
