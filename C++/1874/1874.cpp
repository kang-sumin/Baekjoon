/*
* ������ȣ : 1874
* 
* https://www.acmicpc.net/problem/1874
*/

#include <bits/stdc++.h>
using namespace std;

stack<int>S;


int main() {
	int N; //1�̻� N������ ������ ������� �־���, ���� ���� �ι� ������ ����
	int Max = 0;//���ÿ� ���� ������ ��
	string result = ""; //��� ���
	

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;// ������ �� �Էµ� ��
		cin >> x;
		//�Է°��� ���ÿ� �� ������ ������ ũ�� ���� ���� �־���� ��
		if (x > Max) {
			while (x > Max) {
				S.push(++Max);//������ ������ ������ üũ
				result += "+\n"; //push
			}
			S.pop();
			result += "-\n";//pop
		}
		//�Է°��� ���ÿ� �� ������ ������ ũ�� ������
		else {
			//x�� Max�� ������ Ȯ���� bool ����
			bool flag = false;
			//empty() ��������� true, �ƴϸ� false
			if (!S.empty()) {
				//�������� ���Ѽ� pop ��Ű�� ����
				if (x == S.top()) 
				{
					//x�� Max�� ������ true
					flag = true;
				}
				S.pop();
				result += "-\n";
			}
			//�Ұ����� ��� NO ���
			if(!flag) 
			{
				result="NO";
				break;
			}

		}

	}
	cout << result;

	return 0;
}