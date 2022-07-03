/*
* 문제번호 : 1874
* 
* https://www.acmicpc.net/problem/1874
*/

#include <bits/stdc++.h>
using namespace std;

stack<int>S;


int main() {
	int N; //1이상 N이하의 정수가 순서대로 주어짐, 같은 정수 두번 나오지 않음
	int Max = 0;//스택에 들어가는 마지막 값
	string result = ""; //결과 출력
	

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;// 수열에 들어갈 입력된 값
		cin >> x;
		//입력값이 스택에 들어간 마지막 값보다 크면 정수 값을 넣어줘야 함
		if (x > Max) {
			while (x > Max) {
				S.push(++Max);//정수가 어디까지 들어갔는지 체크
				result += "+\n"; //push
			}
			S.pop();
			result += "-\n";//pop
		}
		//입력값이 스택에 들어간 마지막 값보다 크지 않으면
		else {
			//x와 Max가 같은지 확인할 bool 변수
			bool flag = false;
			//empty() 비어있으면 true, 아니면 false
			if (!S.empty()) {
				//오름차순 지켜서 pop 시키기 위해
				if (x == S.top()) 
				{
					//x와 Max가 같으면 true
					flag = true;
				}
				S.pop();
				result += "-\n";
			}
			//불가능한 경우 NO 출력
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