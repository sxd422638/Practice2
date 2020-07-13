//��Ŀһ��
//	������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧϰ���������ַ��������򷽷��� 1.�����ַ������ֵ����������磺
//"car" < "carriage" < "cats" < "doggies < "koala"
//	2.�����ַ����ĳ����������磺
//	"car" < "cats" < "koala" < "doggies" < "carriage"
//	������֪���Լ�����Щ�ַ�������˳���Ƿ��������������򷽷�������Ҫæ�ų���Ҷ��������Ҫ������æ��֤��
//	�������� :
//
//�����һ��Ϊ�ַ�������n(n �� 100)
//��������n��, ÿ��һ���ַ���, �ַ������Ⱦ�С��100������Сд��ĸ���
//������� :
//�����Щ�ַ����Ǹ����ֵ������ж����Ǹ��ݳ����������"lexicographically",
//
//������ݳ������ж������ֵ����������"lengths",
//
//������ַ�ʽ���������"both"���������"none"
//
//ʾ��1
//����
//3
//a
//aa
//bbb
//
//���
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
	//�Ƚ�ASCII��
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
//��Ŀ����
//������A��������B ����С��������ָ �ܱ�A��B��������С��������ֵ�����һ���㷨��������A��B����С��������
//
//�������� :
//��������������A��B��
//
//������� :
//���A��B����С��������
//
//ʾ��1
//����
//
//5 7
//���
//
//35
//
//������˼·����
//��С������ = ����֮���������Լ��������ʹ����ת������������Լ������⣺��a��b�����Լ��
//����ת��Ϊa��b֮�������Ϊ����֮����С����֮��Ĺ�Լ�������Զ�������������������������ֱ࣬��
//����Ϊ0������ķ�ĸ��Ϊ�����
//


//�������Լ��
int max_com_div(int x, int y)
{
	//շת�����  //������������Ϊ0��ʱ������x��Ϊ���Լ��
	//���ý�С�����Խϴ����ȡ�࣬���������Խ�С�������ֱ࣬������Ϊ�� 
	int rem = 0;
	while (y != 0)
	{
		rem = x % y;
		x = y;
		y = rem;
	}
	return x;
}
//��С������
int min_com_multi()
{
	int m, n;
	cin >> m >> n;

	return m * n / max_com_div(m, n);
}
