//��Ŀһ
//����һ���ַ���str������ַ���str�е�����������ִ�
//�������� :
//�������������1������������һ���ַ���str�����Ȳ�����255��
//������� :
//��һ�������str��������������ִ���
//ʾ��1
//����
//abcd12345ed125ss123456789
//
//���
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



//��Ŀ��
//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//��������һ������Ϊ9������{ 1,2,3,2,2,2,5,4,2 }��
//��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2��
//��������������0��
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		// ��Ϊ�õ���sort��ʱ�临�Ӷ�O(NlogN)����������
		if (numbers.empty()) return 0;
		sort(numbers.begin(), numbers.end()); // ����ȡ�����м��Ǹ���
		int middle = numbers[numbers.size() / 2];
		int count = 0; // ���ִ���
		for (int i = 0; i<numbers.size(); ++i)
		{
			if (numbers[i] == middle) ++count;
		}
		return (count>numbers.size() / 2) ? middle : 0;
	}
};