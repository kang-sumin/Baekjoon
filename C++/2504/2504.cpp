/*
* ������ȣ : 2504
* 
* https://www.acmicpc.net/problem/2504
*/

#include <bits/stdc++.h>
using namespace std;


//C++ STL�� ���� ����
stack<char>S;
//�Է°� ������ ��Ʈ��
string str;
//���
int result = 0;
//��꿡 ���� ����
int num = 1;

int main() {
	//�Ϸ°�
	cin >> str;
	//�Ϸ°� �м�
	for (int i = 0; i < str.length(); i++) {
		//'('�� ���
		if (str[i] == '(') {
			//'()' ��ȣ�� �� : 2
			num *= 2;
			S.push('(');
		}
		//'['�� ���
		else if (str[i] == '[') {
			//'[]' ��ȿ�� �� : 3
			num *= 3;
			S.push('[');
		}
		//')'�� ���
		else if (str[i] == ')') {
			//
			if (S.empty() || S.top() != '(') {

			}
		}
	}

	return 0;
}