/*
* ������ȣ : 10866
* 
* https://www.acmicpc.net/problem/10866
*/

#include<bits/stdc++.h>
using namespace std;

//��ť DQ ����, C++ STL�� ��ť ������
deque<int> D;

int main() {
	int N,x; //����� ���� ������ ���� N, �Է¹��� ������ x ����
	cin >> N;

	//��ɾ� �м��ؼ� �����
	for (int i = 0; i < N; i++) {
		//��ɾ� str�� �޾Ƽ� �ɷ���
		string str;
		cin >> str;

		//push_front : ���� x�� �� �տ� ����
		if (str == "push_front") {
			cin >> x;
			D.push_front(x);
		}
		//push_back : ���� x�� �� �ڿ� ����
		else if (str == "push_back") {
			cin >> x;
			D.push_back(x);
		}
		//pop_front : ���� ���� �ռ� ����, �� �� ���, ������ -1 ���
		else if (str == "pop_front") {
			if (D.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << D.front() << '\n';
				D.pop_front();
			}
		}
		//pop_back : ���� ���� �ڼ� ����, �� �� ���, ������ -1 ���
		else if (str == "pop_back") {
			if (D.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << D.back() << '\n';
				D.pop_back();
			}
		}
		//���� ��� 1, �ƴϸ� 0 ���
		else if (str == "empty") {
			cout << D.empty() << '\n';
		}
		//front : �� ���� �� �� ���, ������ -1 ���
		else if (str == "front") {
			if (D.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << D.front() << '\n';
			}
		}
		//back : �� ���� �� �� ���, ������ -1 ���
		else if (str == "back") {
			if (D.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << D.back() << '\n';
			}
		}
		//size : �� ������ ���
		else {
			cout << D.size() << '\n';
		}

	}
	return 0;
}
