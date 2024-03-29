#include <iostream>
#include <vector>
#include <queue>
#include <limits.h> 

using namespace std;

typedef pair<int, int> edge;
vector<bool> visited;
//vector<int> mindistance;
vector<vector<edge> > list;
priority_queue<edge, vector<edge>, greater<edge> > pq;
// 오름차순
int dijkstra(int start, int end, int N);
// start는 시작 노드 번호, end는 도착 노드 번호, N는 정점의 개수
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    //N은 도시의 개수, M은 버스의 개수
    visited.resize(N+1);
    list.resize(N+1);
    fill(visited.begin(), visited.end(), false);
    // 벡터의 크기를 전부 N+1로 정한다(1부터 시작)
    // visited는 방문 여부, list는 엣지 정보를 담는다
    // 모든 노드는 방문 전으로 값을 초기화한다
    for(int i = 0; i < M; i++){
        int u,v,w;
        cin >> u >> v >> w;
        list[u].push_back(make_pair(v, w));
    }
    // 버스 정보를 입력받고 입력받은 정보를 list에 추가한다
    int startInt, endInt;
    cin >> startInt >> endInt;
    int result = dijkstra(startInt, endInt, N);
    // 출발 도시에서 도착도시까지의 최단 거리 구하기
    cout << result << endl;
}

int dijkstra(int start, int end, int N){
    vector<int> distance;
    distance.resize(N+1);
    fill(distance.begin(), distance.end(), INT_MAX);
    // 최단 거리 벡터의 값을 전부 max값으로 초기화한다
    distance[start] = 0;
    // 시작 노드는 start
    // 따라서 start 노드까지의 최단거리는 0으로 한다
    pq.push(make_pair(0, start));
    // 우선순위 큐 (시작 노드까지의 거리, 노드 번호)
    while(!pq.empty()){
        edge current = pq.top();
        int current_v = current.second;
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
            // 더 잛은 거리가 나올 경우 값을 갱신한다
        }
    }
    return distance[end];
}
