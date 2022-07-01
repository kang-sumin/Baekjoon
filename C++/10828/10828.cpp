/*
* 문제번호 : 10828
* 
* https://www.acmicpc.net/problem/10828
* 
* push X: 정수 X를 스택에 넣는 연산이다.
* pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
* size: 스택에 들어있는 정수의 개수를 출력한다.
* empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
* top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

#include <bits/stdc++.h>
using namespace std;

//스택 S생성, C++ STL로 스택 구현된것 사용
stack<int>S;


int main() {
	int N; //명령의 수를 저장할 변수 N
	cin >> N;

	//명령어 분석해서 출력함
	for (int i = 0; i < N; i++) {
		//명령어 str로 받아서 걸러냄
		string str;
		cin >> str;

		//push : 정수 X 스택에 넣음
		if (str == "push") {
			int x;
			cin >> x;
			S.push(x);
		}
		//pop : 가장위에 정수빼고, 그 수 출력, 스택에 아무것도 없으면 -1출력
		else if (str == "pop") {
			if (S.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << S.top() << endl;
				S.pop();
			}
		}
		//empty() 비어있으면 true, 있으면 false
		else if (str == "empty") {
			cout << S.empty() << endl;
		}
		//top : 가장위에 있는 것 출력, 스택에 아무것도 없으면 -1출력
		else if (str == "top") {
			if (S.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << S.top() << endl;
			}
		}
		//size : 스택에 들어있는 정수 개수 출력
		else {
			cout << S.size() << endl;
		}

	}
	return 0;
}


