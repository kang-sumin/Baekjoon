/*
* 문제번호 : 10866
* 
* https://www.acmicpc.net/problem/10866
*/

#include<bits/stdc++.h>
using namespace std;

//덱큐 DQ 생성, C++ STL로 덱큐 구현함
deque<int> D;

int main() {
	int N,x; //명령의 수를 저장할 변수 N, 입력받을 정수값 x 변수
	cin >> N;

	//명령어 분석해서 출력함
	for (int i = 0; i < N; i++) {
		//명령어 str로 받아서 걸러냄
		string str;
		cin >> str;

		//push_front : 정수 x를 덱 앞에 넣음
		if (str == "push_front") {
			cin >> x;
			D.push_front(x);
		}
		//push_back : 정수 x를 덱 뒤에 넣음
		else if (str == "push_back") {
			cin >> x;
			D.push_back(x);
		}
		//pop_front : 덱의 가장 앞수 빼고, 그 수 출력, 없으면 -1 출력
		else if (str == "pop_front") {
			if (D.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << D.front() << '\n';
				D.pop_front();
			}
		}
		//pop_back : 덱의 가장 뒤수 빼고, 그 수 출력, 없으면 -1 출력
		else if (str == "pop_back") {
			if (D.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << D.back() << '\n';
				D.pop_back();
			}
		}
		//덱이 비면 1, 아니면 0 출력
		else if (str == "empty") {
			cout << D.empty() << '\n';
		}
		//front : 덱 가장 앞 수 출력, 없으면 -1 출력
		else if (str == "front") {
			if (D.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << D.front() << '\n';
			}
		}
		//back : 덱 가장 뒤 수 출력, 없으면 -1 출력
		else if (str == "back") {
			if (D.empty()) {
				cout << "-1" << '\n';
			}
			else {
				cout << D.back() << '\n';
			}
		}
		//size : 덱 사이즈 출력
		else {
			cout << D.size() << '\n';
		}

	}
	return 0;
}
