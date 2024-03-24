#include <iostream>
#include <vector>
#include <queue>
#include <limits.h> 

using namespace std;

typedef pair<int, int> edge;
vector<bool> visited;
vector<int> mindistance;
vector<vector<edge> > list;
priority_queue<edge, vector<edge>, greater<edge> > pq;
int dijkstra(int start, int end);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    mindistance.resize(N+1);
    visited.resize(N+1);
    list.resize(N+1);
    fill(mindistance.begin(), mindistance.end(), INT_MAX);
    fill(visited.begin(), visited.end(), false);

    for(int i = 0; i < M; i++){
        int u,v,w;
        cin >> u >> v >> w;
        list[u].push_back(make_pair(v, w));
    }
    int startInt, endInt;
    cin >> startInt >> endInt;
    int result = dijkstra(startInt, endInt);
    cout << result << endl;
}

int dijkstra(int start, int end){
    mindistance[start] = 0;
    pq.push(make_pair(0, start));
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
            if(mindistance[current_v] + value < mindistance[next]){
                mindistance[next] = mindistance[current_v] + value;
                pq.push(make_pair(mindistance[next], next));
            }
        }
    }
    return mindistance[end];
}
