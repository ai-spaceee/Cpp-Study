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
    // 마을 수 N개, 파티 장소 X번째 마을, 단방향 도로 M개
    list.resize(N+1);
    // 벡터의 크기를 N+1로 정한다(1부터 시작)
    for(int i = 0; i < M; i++){
        int start,end,time;
        cin >> start >> end >> time;
        list[start].push_back(make_pair(end,time));
    }
    // 도로 정보를 입력받고 입력받은 정보를 list에 추가한다

    vector<int> mintime_from_X = dijkstra(X, N);
    // X번째 마을에서 각 마을로 가는 최소 시간 벡터 구하기
    int max = 0;
    for(int i = 1; i<=N; i++){
        vector<int> mintime_to_X = dijkstra(i, N);
        // 각 마을에서 X번째 마을로 가는 최소 시간 벡터 구하기
        int total_time = mintime_from_X[i] + mintime_to_X[X];
        // i번째 마을과 X번째 마을을 왕복하는 전체 최소 시간 구하기
        if(total_time > max){
            max = total_time;
        }
        // 최소 시간이 제일 큰 값을 찾는다
    }
    cout << max;
}

vector<int> dijkstra(int start, int N){
    priority_queue<edge, vector<edge>, greater<edge> > pq;
    // 우선순위 큐
    vector<int> mintime;
    vector<bool> visited;
    mintime.resize(N+1);
    pq.push(make_pair(0, start));
    visited.resize(N+1);
    fill(mintime.begin(), mintime.end(), INT_MAX);
    mintime[start] = 0;
    // 시작 노드는 start
    // 따라서 start 노드까지의 최단거리는 0으로 한다
    fill(visited.begin(), visited.end(), false);
    // 벡터 초기화
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
            if(mintime[current_v] + value < mintime[next]){
                mintime[next] = mintime[current_v] + value;
                pq.push(make_pair(mintime[next], next));
            }
            // 더 짧은 시간이 나올 경우 값을 갱신한다
        }
    }
    return mintime;
}



