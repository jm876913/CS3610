#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int INF = 10000;
 
// given adjacency matrix adj, finds shortest path from A to B
int dijk(int A, int city, vector< vector<int> > matrix) {
  int size = matrix.size();
  vector<int> dist(size);
  vector<bool> vis(size);
 
  for(int i = 0; i < size; ++i) {
    dist[i] = INF;
  }
  dist[A] = 0;
 
  for(int i = 0; i < size; ++i) {
    	int cur = -1;
    	for(int j = 0; j < size; ++j) {
     		if (vis[j]) 
      			continue;
      		if (cur == -1 || dist[j] < dist[cur]) 
        		cur = j;
    	}
 
    	vis[cur] = true;
    	for(int j = 0; j < size; ++j) {
      		int path = dist[cur] + matrix[cur][j];
      		if (path < dist[j]) {
        		dist[j] = path;
     		 }
   		}
  	}
 	cout << dist[size] << endl;
}

int main()
{
	int test;
	cin >> test;

	for(int i = 0; i < test; i++){
		int city;
		cin >> city;
		vector<string> dist(city);
		for(int t = 0; t < city; t++){
			dist[t] = "string";
		}

		for(int j = 0; j < city; j++){
			string temp;
			cin >> temp;
			dist[j] = temp;
		}
		vector< vector<int> > matrix(city);

		for(int m = 0; m < city; m++){
			matrix[m] = vector<int>(city);
			for(int d=0; d < city; d++){
				int num;
				cin >> num;
				if(num == 0)
					num = INF;

				matrix[m][d] = num;
			}
		}
		dijk(0, city - 1, matrix);
	}

	return 0;
}