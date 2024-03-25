#include <iostream>
#include <vector>
#include <queue>
#include <limits.h> 

using namespace std;

typedef pair<int, int> edge;
vector<bool> visited;
vector<vector<edge> > list;
priority_queue<edge, vector<edge>, greater<edge> > pq;
// 오름차순

vector<int> dijkstar(int start, int V);
//start는 시작 노드 번호, V는 정점의 개수
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, K;
    // V는 정점의 개수, E는 엣지 개수, K는 시작 정점의 번호이다
    cin >> V >> E >> K;
    visited.resize(V+1);
    list.resize(V+1);
    // 벡터의 크기를 전부 V+1로 정한다(1부터 시작)
    // visited는 방문 여부, list는 엣지 정보를 담는다
    fill(visited.begin(), visited.end(), false);
    // 모든 노드는 방문 전으로 값을 초기화한다
    for(int i = 0; i < E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        list[u].push_back(make_pair(v, w));
    }
    // 엣지 정보를 입력받고 입력받은 정보를 list에 추가한다

    vector<int> mindistance = dijkstar(K, V);
    // 최단거리 벡터 구하기
    for(int i = 1; i <= V; i++){
        if(mindistance[i] == INT_MAX){
            cout << "INF" <<endl;
        }
        // i번째 노드의 최단 경로가 max값일 경우에는 방문하지 않았다는 의미이므로 경로가 존재하지 않아 "INF"를 출력한다
        else{
            cout << mindistance[i] << endl;
        }
    }
}

vector<int> dijkstar(int start, int V){
    vector<int> distance;
    distance.resize(V+1);
    fill(distance.begin(), distance.end(), INT_MAX);
    // 최단 거리 벡터의 값을 전부 max값으로 초기화한다
    distance[start] = 0;
    // 시작 노드는 start
    // 따라서 start 노드까지의 최단거리는 0으로 한다
    pq.push(make_pair(0, start));
    // 우선순위 큐 (시작 노드까지의 거리, 노드 번호)

    while(!pq.empty()){
        // 우선순위 큐가 빌 때까지 반복
        edge current = pq.top();
        // 시작 노드와의 거리가 제일 가까운 노드 기준으로 시작
        int current_v = current.second;
        // 현재 노드의 번호
        pq.pop();
        if(visited[current_v]){
            continue;
        }
        // 이미 방문한 노드일 경우에는 반복에서 제외한다
        visited[current_v]=true;
        for(int i = 0; i < list[current_v].size(); i++){
            edge tmp = list[current_v][i];
            int next = tmp.first;
            int value = tmp.second;
            if(distance[current_v] + value < distance[next]){
                distance[next] = distance[current_v] + value;
                pq.push(make_pair(distance[next], next));
            }
            // 더 짧은 거리가 나올 경우 값을 갱신한다
        }
    }
    return distance;
}
