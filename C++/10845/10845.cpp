/*
* ������ȣ : 10845
* 
* https://www.acmicpc.net/problem/10845
*/

#include <bits/stdc++.h>
using namespace std;

queue <int> Q;

int main() {

	int N; //����� ���� ������ ���� N
	cin >> N;

	//��ɾ� �м��ؼ� �����
	for (int i = 0; i < N; i++) {
		//��ɾ� str�� �޾Ƽ� �ɷ���
		string str;
		cin >> str;

		//push : ����x�� ť�� ����
		if (str == "push") {
			int x;
			cin >> x;
			Q.push(x);
		}
		//pop : ���� �� ������ ����, �� �� ���, �ƹ��͵� ������ -1 ���
		else if (str == "pop") {
			if (Q.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << Q.front() << endl;
				Q.pop();
			}
		}
		//ť�� ������� 1, �ƴϸ� 0 ���
		else if (str == "empty") {
			cout << Q.empty() << endl;
		}
		//���� �� ���� ����ϰ�, �ƹ��͵� ������ -1 ���
		else if (str == "front") {
			if (Q.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << Q.front() << endl;
			}
		}
		//���� �� ���� ����ϰ�, �ƹ��͵� ������ -1 ���
		else if (str == "back") {
			if (Q.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << Q.back() << endl;
			}
		}
		//ť�� �� �ִ� ���� ���� ���
		else {
			cout << Q.size() << endl;
		}
	}
	return 0;
}