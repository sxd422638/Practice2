//��Ŀһ:
//����һ�������ľ��������̣������һ����Ч�㷨�жϵ�ǰ����Ƿ��ʤ��
//
//����һ����ά����board������ǰ���̣�����Ԫ��Ϊ1�Ĵ����ǵ�ǰ��ҵ����ӣ�Ϊ0��ʾû�����ӣ�Ϊ - 1�����ǶԷ���ҵ����ӡ�
//
//����������
//[[1, 0, 1], [1, -1, -1], [1, -1, 0]]
//���أ�true
//����Ŀ��������
//�����壬��һ����3 * 3�����Ͻ��е�������Ϸ��������ͬ�ʹ����ʤ��
//������˼·����
//�����������������ʾ��ǰ��һ�ʤ��1����ǰ������� 1. ��ȫΪ1�� ���еĺ�Ϊ3 2. ��ȫΪ1�� �еĺ�Ϊ
//3 3. ���Խ�ȫΪ1�� �ԽǺ�Ϊ3 4. ���Խ�ȫΪ1�� �ԽǺ�Ϊ3 5. �����չΪN*N�Ļ����жϺ��Ƿ����N����
//����������κ����

#include<iostream>
#include<vector>
using namespace std;
class Board {
public:
	bool checkWon(vector<vector<int>> board)
	{ 
		int row = board.size();
		//���ÿһ�еĺ����Ƿ����row
		int i, j, sum;
		for (i = 0; i<row; i++)
		{
			sum = 0;
			for (j = 0; j<row; j++)
			{
				sum += board[i][j];
			}
			if (sum == row)
				return true;
		}
		//������Խ��ߵĺ����Ƿ����row
		sum = 0;
		for (i = 0; i<row; i++)
		{
			sum += board[i][i];
		}
		if (sum == row)
			return true;
		//��鸱�Խ��ߵĺ����Ƿ����row
		sum = 0;
		for (i = 0; i<row; i++)
		{
			sum += board[i][row - i - 1];
		}
		if (sum == row)
			return true;
		return false;
	}
};


