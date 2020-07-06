//��Ŀһ:
//Fibonacci��������������ģ�
//F[0] = 0
//F[1] = 1
//for each i �� 2: F[i] = F[i - 1] + F[i - 2]
//��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci��������һ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX - 1����X + 1�����ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����
//�������� :
//����Ϊһ��������N(1 �� N �� 1, 000, 000)

//������� :
//	���һ����С�Ĳ�����ΪFibonacci��"
//	ʾ��1
//	����	15
//	���	2

//����Ŀ������:
//�����Ƕ���Fibonacci���е�һ�����죬Fibonacci���е������ǵ�һ��͵ڶ��Ϊ1����������γɵݹ飺
//F(n) = F(n - 1) + F(n - 2)��
//������˼·��:
//�������ͨ�����ҵ�����N���������Fibonacci�������������ֱ�ȡ�Ծ���N����������һ����L���ұ�һ
//����R��Ȼ��ͨ��min(N - L, R - N)�ҵ���С������




#include <iostream>
using namespace std;
int main() {
	int N, f, l = 0, r = 0, f0 = 0, f1 = 1;
	cin >> N;
	while (1) {
		f = f0 + f1;
		f0 = f1;
		f1 = f;
		//�ҵ���NС�Ҿ���N����������������
		if (f < N)
			l = N - f;
		else
		{
			//�ҵ���N���Ҿ���N����������������
			r = f - N;
			break;
		}
	}
	//ȡ��С����
	cout << min(l, r) << endl;
	return 0;
}





//��Ŀ����
//����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���
//
//����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���
//
//����������
//"(()())", 6
//���أ�true

//����������
//"()a()()", 7
//���أ�false

//����������
//"()(()()", 7
//���أ�false

//���⿼����Ƕ�ջ��Ӧ��
//������˼·����

//��������ջ�������ű��棬ÿ�����������žͳ�ջһ����
//��ʱ���ջ�վ�Ϊfalse, �����ڼ�������������ҲΪfalse��ֱ������������ջΪ�վͷ���true

#include<iostream>
#include<stack>
using namespace std;

class Parenthesis 
{
public:
	bool chkParenthesis(string A, int n) 
	{
		// write code here
		if (n % 2 == 1)//���ų��������
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