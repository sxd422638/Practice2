//��Ŀһ
//��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing.�����������Ϊ��beijing.like I
//�������� :
//ÿ�������������1������������ I like beijing.�����������Ȳ�����100
//������� :
//�����������֮����ַ���, �Կո�ָ�
//ʾ��1
//����
//
//I like beijing.
//���
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
	reverse(s.begin(), s.end());//��ʱ��ת����������
	auto start = s.begin();      //��ת���� ���ҵ��ո��λ�� Ȼ������reverse��ת���� ���û�н��� �ͼ��� �����ɾ�����ѭ��
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