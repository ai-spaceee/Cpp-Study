#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<bool> > visited;
vector<vector<char> > complex;
vector<int> apartments;

void dfs(int x, int y, int apartmentNumber){
    int curX = x;
    int curY = y;
    if(x < 0 || y < 0 || x >= complex.size() || y >= complex[0].size()) return;
    if(complex[curX][curY] == '0' || visited[curX][curY] == true) return;
    visited[curX][curY]=true;
    apartments[apartmentNumber]++;

    dfs(x + 1, y, apartmentNumber);
    dfs(x - 1, y, apartmentNumber);
    dfs(x, y + 1, apartmentNumber);
    dfs(x, y - 1, apartmentNumber);
}

int main(){
    int N;
    cin >> N;
    complex.resize(N, vector<char>(N));
    visited.resize(N, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
        visited[i][j] = false;
        }
    }

    for(int i = 0; i<N; i++){
        for(int j = 0;j<N;j++){
            cin >> complex[i][j];
        }
    }
    int a = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0;j < N; j++){
            if(complex[i][j] == '1' && !visited[i][j]){ 
                apartments.push_back(0);
                dfs(i, j, a);
                a++;
            }
        }
    }
    sort(apartments.begin(), apartments.end());
    cout << apartments.size()<<endl;
    for(int i = 0; i < apartments.size(); i++){
        cout << apartments[i] << endl;
    }
}