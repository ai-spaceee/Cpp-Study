#include <iostream>
#include <vector>
#include <queue>
#include <limits.h> 

using namespace std;

typedef pair<int, int> edge;
vector<vector<edge> > list;

vector<int> dijkstra(int start, int N);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, X;
    cin >> N >> M >> X;

    list.resize(N+1);

    for(int i = 0; i < M; i++){
        int start,end,time;
        cin >> start >> end >> time;
        list[start].push_back(make_pair(end,time));
    }
    vector<int> mintime_from_X = dijkstra(X, N);
    int max = 0;
    for(int i = 1; i<=N; i++){
        vector<int> mintime_to_X = dijkstra(i, N);
        int total_time = mintime_from_X[i] + mintime_to_X[X];
        if(total_time > max){
            max = total_time;
        }
    }
    cout << max;
}

vector<int> dijkstra(int start, int N){
    priority_queue<edge, vector<edge>, greater<edge> > pq;
    vector<bool> visited;
    vector<int> mintime;
    mintime.resize(N+1);
    pq.push(make_pair(0, start));
    visited.resize(N+1);
    fill(mintime.begin(), mintime.end(), INT_MAX);
    mintime[start] = 0;
    fill(visited.begin(), visited.end(), false);
    while(!pq.empty()){
        edge current = pq.top();
        int current_v = current.second;
        pq.pop();
        if(visited[current_v]){
            continue;
        }
        visited[current_v]=true;
        for(int i = 0; i < list[current_v].size(); i++){
            edge tmp = list[current_v][i];
            int next = tmp.first;
            int value = tmp.second;
            if(mintime[current_v] + value < mintime[next]){
                mintime[next] = mintime[current_v] + value;
                pq.push(make_pair(mintime[next], next));
            }
        }
    }
    return mintime;
}



