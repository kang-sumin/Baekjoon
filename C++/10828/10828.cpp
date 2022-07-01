/*
* ������ȣ : 10828
* 
* https://www.acmicpc.net/problem/10828
* 
* push X: ���� X�� ���ÿ� �ִ� �����̴�.
* pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
* size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
* empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
* top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
*/

#include <bits/stdc++.h>
using namespace std;

//���� S����, C++ STL�� ���� �����Ȱ� ���
stack<int>S;


int main() {
	int N; //����� ���� ������ ���� N
	cin >> N;

	//��ɾ� �м��ؼ� �����
	for (int i = 0; i < N; i++) {
		//��ɾ� str�� �޾Ƽ� �ɷ���
		string str;
		cin >> str;

		//push : ���� X ���ÿ� ����
		if (str == "push") {
			int x;
			cin >> x;
			S.push(x);
		}
		//pop : �������� ��������, �� �� ���, ���ÿ� �ƹ��͵� ������ -1���
		else if (str == "pop") {
			if (S.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << S.top() << endl;
				S.pop();
			}
		}
		//empty() ��������� true, ������ false
		else if (str == "empty") {
			cout << S.empty() << endl;
		}
		//top : �������� �ִ� �� ���, ���ÿ� �ƹ��͵� ������ -1���
		else if (str == "top") {
			if (S.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << S.top() << endl;
			}
		}
		//size : ���ÿ� ����ִ� ���� ���� ���
		else {
			cout << S.size() << endl;
		}

	}
	return 0;
}


