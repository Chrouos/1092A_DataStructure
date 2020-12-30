#include <iostream>
#include<vector>
using namespace std;

int N, E, t = -1;
vector<vector<int>> V;
vector<int> visit, temp;

void BFS(int i) {

	cout << i << " ";
	visit[i] = 1;
	for (int x = 1; x <= N; x++) {
		if (V[i][x] == 1 && visit[x] != 1) {
			temp.push_back(x);
		}
	}

	
	while (temp.empty() == false) {
		
		i = temp.front();
		temp.erase(temp.begin());
		if (visit[i] != 1) BFS(i);
		

	}

}

int main(int argc, char* argv[]) {


	int i;
	cin >> i >> N >> E;
	V = vector<vector<int>>(N + 1, vector<int>(N + 1));
	visit = vector<int>(N + 1);

	int num1, num2;
	for (int x = 0; x < E; x++) {
		cin >> num1 >> num2;
		V[num1][num2] = 1;
		V[num2][num1] = 1;
	}

	BFS(i);

}