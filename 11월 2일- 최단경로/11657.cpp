#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> ti;
const int INF = 1e6 * 5;

//벨만-포드
vector<ll> bellmanFord(int n, int m, int start, vector<ti>& edges) { // n: 정점의 수 , m : 간선의수
    //오버플로우 X, 모든 간선의 가중치가 음수일 때 언더플로우 O
    //next_weight 가 계속 갱신된다면 ? 500 * 6,000 * (-10,000) => int 범위 넘어감!
    
    vector<ll> dist(n + 1, INF);

    dist[start] = 0; //시작 위치 초기화

    for (int i = 1; i <= n; i++) { // n번 루프. 

        bool flag = true; //더 이상 반복문을 실행할 필요가 없는지 확인
        for (int j = 0; j < m; j++) { // m : 간선의 개수 (모든 간선에 대해)
            //s->d로 가는 간선의 가중치가 w
            int s = get<0>(edges[j]); // s : source
            int d = get<1>(edges[j]); // d : destination
            int w = get<2>(edges[j]); // w : weight

            // Q. s가 INF 인데 갱신이 일어나면? 실제 갈 수 있는 거리가 있는것처럼 착각한다면?
            // A. 아직 시작점에서 s로 가는 경로가 발견되지 않았으므로 갱신할 수 없음
            if (dist[s] == INF) 
                continue;

            ll next_weight = w + dist[s];
            if (dist[d] > next_weight) { //더 짧은 경로로 갈 수 있다면
                if (i == n) //n번째 갱신이었다면 음의 사이클이 발생한 것
                    return { INF + 1 };
                dist[d] = next_weight;
                flag = false;
            }
        }
        if (flag) //더 이상 갱신되지 않았다면 더 탐색할 필요 없음
            break;
    }
    return dist;
}

int main() {
    int n, m, a, b, c;

    //입력
    cin >> n >> m;
    vector<ti> edges(m); //간선 정보를 저장할 벡터 (그래프 관계보다는 간선 자체의 정보가 더 중요함)
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges[i] = { a, b, c }; //방향 그래프
    }

    //연산
    vector<ll> ans = bellmanFord(n, m, 1, edges);

    //출력
    if (ans[0] == INF + 1) { //음의 사이클
        cout << -1;
        return 0;
    }
    for (int i = 2; i <= n; i++)
        cout << ((ans[i] == INF) ? -1 : ans[i]) << '\n';
}