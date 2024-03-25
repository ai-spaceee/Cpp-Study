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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V, E, K;
    cin >> V >> E >> K;
    mindistance.resize(V+1);
    visited.resize(V+1);
    list.resize(V+1);
    fill(mindistance.begin(), mindistance.end(), INT_MAX);
    mindistance[K] = 0;
    fill(visited.begin(), visited.end(), false);

    for(int i = 0; i < E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        list[u].push_back(make_pair(v, w));
    }

    pq.push(make_pair(0, K));

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

    for(int i = 1; i <= V; i++){
        if(mindistance[i] == INT_MAX){
            cout << "INF" <<endl;
        }
        else{
            cout << mindistance[i] << endl;
        }
    }
}
