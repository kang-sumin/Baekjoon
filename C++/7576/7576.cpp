/*
* ������ȣ : 7576 (BFS ����)
*
* https://www.acmicpc.net/problem/7576
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1001; //2<=N,M<=1000

int M, N;//M=����, N=����
int Day = 0;//���� ��, �� �ʹµ� �ɸ��� �ð�
int box[MAX_SIZE][MAX_SIZE]; //�丶�䰡 ���� ���� �迭
int DayPath[MAX_SIZE][MAX_SIZE]; //��� Ȯ���ϴ� �迭

//����(�����¿�)
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

//ť ����
queue<pair<int, int>> q;

//�ڽ��� �丶�䰡 �����ϴ� ���� Ȯ��
bool BoxInside(int ny, int nx) {
	return (0 <= nx && 0 <= ny && nx < M&& ny < N);
}

//�ϼ� path ��� �Լ�
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
		//�丶�� ������
		int y = q.front().first; //ù��°�� �� ���� �丶�� x��ǥ
		int x = q.front().second; //ù��°�� ���ư� ���� �丶�� y��ǥ
		q.pop();

		//���� �丶�� �ֺ� Ȯ��
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			//�ڽ��� ����� �����鼭 ���� ���� �丶����
			if (BoxInside(ny, nx) == 1 && box[ny][nx] == 0) {
				box[ny][nx] = box[y][x] + 1;
				q.push({ ny,nx });
				//path �������
				DayPath[ny][nx] = DayPath[y][x] + 1;
			}
		}
	}
}

int main() {
	//����,���� ũ�� �Է�
	cin >> M >> N;

	//�׷��� �Է�
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

	//BFS�� Ž��
	BFS();

	//��� ���
	printPath();

	//���� ���
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//���� ���� �丶�䰡 �������
			if (box[i][j] == 0) {
				cout << "-1";
				return 0;
			}
			//�ϼ� ���
			if (Day < box[i][j]) {
				Day = box[i][j];
			}
		}
	}
	//���� ���
	cout << Day - 1;

	return 0;
}
