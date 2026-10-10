#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, cnt = 0, times = 0;
int a[200][200];
int direct[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // 상하좌우
vector<vector<int>> visit;
vector<vector<int>> ices;

/*
    1 - 빙하
    0 - 물

    물의 종류 - 바깥물, 빙하로 둘러싸인 물
    상하좌우로 연결되어 있으면 바깥물
    사방이 빙하로 막혀 도달할 수 없으면 빙하로 둘러싸인 물
    빙하로 둘러싸인 물은 빙하를 녹일 수 없음
    
*/

/*
    bfs 호출
    바깥물인지 빙하로 둘러싸인 물인지 확인
    바깥물이면 인접한 곳에 빙하가 있는지 확인
    빙하가 있다면 그 위치를 벡터 배열에 저장

    이번 타임에 모두 탐색헀으면 새로운 함수 erase 호출
    빙하의 위치가 저장된 벡터 배열을 활용해 기존 배열에 빙하를 제거
    시간++, 제거된 빙하의 수 저장

    남아있는 빙하의 수 확인
    남아있는 빙하의 수가 0이 될 때까지 반복
*/

void erase() {
    cnt = 0;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {

            if(ices[i][j] == 1) {
                a[i][j] = 0;
                cnt++;
            }
        }
    }

    times++;
}

void bfs() {
    queue<pair<int, int>> q;

    visit.assign(N, vector<int>(M, 0));  
    ices.assign(N, vector<int>(M, 0)); 

    q.push({0, 0});
    visit[0][0] = 1;

    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int ny = cy + direct[i][0];
            int nx = cx + direct[i][1];

            if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

            if(visit[ny][nx] == 1) continue;

            if(a[ny][nx] == 1) {
                ices[ny][nx] = 1;
                continue;
            }

            visit[ny][nx] = 1;
            q.push({ny, nx});
        }

    }   
}

int main() {
    cin >> N >> M;
    int tot = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
            if(a[i][j] == 1) tot++;
        }
    }
    int last = 0;
    while(1) {
        bfs(); // 물의 종류 확인, 빙하 위치 저장
        erase(); // 저장된 빙하위치를 기반으로 제거
        tot -= cnt; // 남아있는 빙하의 수
        last = cnt;
        if(tot == 0) break;
    }

    cout << times << " " << last << endl;

    

    return 0;
}
