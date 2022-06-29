/*
* 문제번호 : 7576 (BFS 문제)
*
* https://www.acmicpc.net/problem/7576
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1001; //2<=N,M<=1000

int M, N;//M=가로, N=세로
int Day = 0;//일주 일, 다 익는데 걸리는 시간
int box[MAX_SIZE][MAX_SIZE]; //토마토가 담기는 상자 배열
int DayPath[MAX_SIZE][MAX_SIZE]; //경로 확인하는 배열

//방향(상하좌우)
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

//큐 생성
queue<pair<int, int>> q;

//박스에 토마토가 존재하는 영역 확인
bool BoxInside(int ny, int nx) {
	return (0 <= nx && 0 <= ny && nx < M&& ny < N);
}

//일수 path 출력 함수
void printPath() {
	cout << "\n*** PATH ***" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << DayPath[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
}


void BFS() {
	while (!q.empty()) {
		//토마토 꺼내기
		int y = q.front().first; //첫번째로 들어간 익은 토마토 x좌표
		int x = q.front().second; //첫번째로 돌아간 익은 토마토 y좌표
		q.pop();

		//익은 토마토 주변 확인
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			//박스를 벗어나지 않으면서 익지 않은 토마토라면
			if (BoxInside(ny, nx) == 1 && box[ny][nx] == 0) {
				box[ny][nx] = box[y][x] + 1;
				q.push({ ny,nx });
				//path 출력위해
				DayPath[ny][nx] = DayPath[y][x] + 1;
			}
		}
	}
}

int main() {
	//가로,세로 크기 입력
	cin >> M >> N;

	//그래프 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}

	//BFS로 탐색
	BFS();

	//경로 출력
	printPath();

	//일주 계산
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//익지 않은 토마토가 있을경우
			if (box[i][j] == 0) {
				cout << "-1";
				return 0;
			}
			//일수 계산
			if (Day < box[i][j]) {
				Day = box[i][j];
			}
		}
	}
	//일주 출력
	cout << Day - 1;

	return 0;
}
