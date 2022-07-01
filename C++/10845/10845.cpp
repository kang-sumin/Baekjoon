/*
* 문제번호 : 10845
* 
* https://www.acmicpc.net/problem/10845
*/

#include <bits/stdc++.h>
using namespace std;

//queue 생성, C++ STL 로 큐 생성
queue <int> Q;

int main() {

	int N; //명령의 수를 저장할 변수 N
	cin >> N;

	//명령어 분석해서 출력함
	for (int i = 0; i < N; i++) {
		//명령어 str로 받아서 걸러냄
		string str;
		cin >> str;

		//push : 정수x를 큐에 넣음
		if (str == "push") {
			int x;
			cin >> x;
			Q.push(x);
		}
		//pop : 가장 앞 정수를 빼고, 그 수 출력, 아무것도 없으면 -1 출력
		else if (str == "pop") {
			if (Q.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << Q.front() << endl;
				Q.pop();
			}
		}
		//큐가 비었으면 1, 아니면 0 출력
		else if (str == "empty") {
			cout << Q.empty() << endl;
		}
		//가장 앞 정수 출력하고, 아무것도 없으면 -1 출력
		else if (str == "front") {
			if (Q.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << Q.front() << endl;
			}
		}
		//가장 뒤 정수 출력하고, 아무것도 없으면 -1 출력
		else if (str == "back") {
			if (Q.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << Q.back() << endl;
			}
		}
		//큐에 들어가 있는 정수 개수 출력
		else {
			cout << Q.size() << endl;
		}
	}
	return 0;
}
