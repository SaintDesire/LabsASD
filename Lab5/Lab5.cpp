#include <iostream>
#include <vector>
#include <algorithm>
#define V 8
#define INF INT_MAX
using namespace std;

int G[V][V] =
{
	//	 1  2  3  4  5  6  7  8
		{0, 2, 0, 8, 2, 0, 0, 0},		//1
		{2, 0, 3, 10, 5, 0, 0, 0},		//2
		{0, 3, 0, 0, 12, 0, 0, 7},		//3
		{8, 10, 0, 0, 14, 3, 1, 0},		//4
		{2, 5, 12, 14, 0, 11, 4, 8},	//5
		{0, 0, 0, 3, 11, 0, 6, 0},		//6
		{0, 0, 0, 1, 4, 6, 0, 9},		//7
		{0, 0, 7, 0, 8, 0, 9, 0}		//8
};

void Prim() {

    int no_edge;

	int weight = 0;

    int selected[V];
	memset(selected, false, sizeof(selected));

    no_edge = 0;

    selected[0] = true;

    int x;  
    int y; 

    cout << "Ребро \t\t Вес ребра";
    cout << endl;
    while (no_edge < V - 1) {


        int min = INF;
        x = 1;
        y = 1;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) { 
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }

                    }
                }
            }
        }
        cout << x + 1 << " -> " << y + 1 << "\t\t\t " << G[x][y];
        cout << endl;
        selected[y] = true;
        no_edge++;
		weight += G[x][y];
    }
	cout << "\nВес минимального остовного дерева: " << weight << endl;
}

struct Node // Сохранить график как структуру данных
{
	int start;
	int end;
	int length;
};
bool compare(Node a, Node b)
{
	return a.length < b.length;
}
void Kruskal(vector<Node>& arr, vector<Node>& arr2, vector<bool>& visited)
{
	int M, N;
	M = visited.size();
	N = arr.size();
	arr[0].start = 0; arr[0].end = 1; arr[0].length = 2;
	arr[1].start = 0; arr[1].end = 3; arr[1].length = 8;
	arr[2].start = 0; arr[2].end = 4; arr[2].length = 2;
	arr[3].start = 1; arr[3].end = 3; arr[3].length = 10;
	arr[4].start = 1; arr[4].end = 2; arr[4].length = 3;
	arr[5].start = 1; arr[5].end = 4; arr[5].length = 5;
	arr[6].start = 2; arr[6].end = 4; arr[6].length = 12;
	arr[7].start = 2; arr[7].end = 7; arr[7].length = 7;
	arr[8].start = 3; arr[8].end = 5; arr[8].length = 3;
	arr[9].start = 3; arr[9].end = 4; arr[9].length = 14;

	arr[10].start = 3; arr[10].end = 6; arr[10].length = 1;
	arr[11].start = 4; arr[11].end = 5; arr[11].length = 11;
	arr[12].start = 4; arr[12].end = 6; arr[12].length = 4;
	arr[13].start = 4; arr[13].end = 7; arr[13].length = 8;
	arr[14].start = 5; arr[14].end = 6; arr[14].length = 6;
	arr[15].start = 6; arr[15].end = 7; arr[15].length = 9;

	sort(arr.begin(), arr.end(), compare);
	int weight = 0;
	cout << "Ребро \t\t Вес ребра" << endl;
	for (int i = 0; i < N; i++)
	{
		if (!visited[arr[i].start] || !visited[arr[i].end])
		{
			weight += arr[i].length;
			visited[arr[i].start] = true;
			visited[arr[i].end] = true;
			cout << arr[i].start + 1 << " -> " << arr[i].end + 1 << " \t\t\t " << arr[i].length << endl;
			arr2[i].start = arr[i].start;
			arr2[i].end = arr[i].end;
			arr2[i].length = arr[i].length;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (arr2[i].length == 0)
		{
			cout << arr[i].start + 1 << " -> " << arr[i].end + 1 << " \t\t\t " << arr[i].length << endl;
			weight += arr[i].length;
			break;
		}
	}

	cout << "\nВес минимального остовного дерева: " << weight << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int M = 8, N = 16;
	cout << "Алгоритм Прима" << endl;
	Prim();

	vector<Node> arr(N);
	vector<Node> arr2(N);
	vector<bool> visited(M);
	cout << "\nАлгоритм Краскала:" << endl;
	Kruskal(arr, arr2, visited);

	return 0;
}