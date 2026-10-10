#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, Q;

int direct[4][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

struct info {
    int sy, sx, ey, ex;
    int size, num;
};

vector<info> informs;
vector<vector<int>> map;
vector<vector<int>> newmap;
vector<vector<int>> visited;

// 미생물별 실제 좌표
vector<vector<pair<int, int>>> cells;


// 새로운 미생물 투입
void fill(int sy, int sx, int ey, int ex, int num) {

    for(int y = sy; y < ey; y++) {
        for(int x = sx; x < ex; x++) {
            map[y][x] = num;
        }
    }
}


// 같은 미생물의 연결된 영역 탐색
void bfs(int y, int x, int num) {

    queue<pair<int, int>> q;

    q.push({y, x});
    visited[y][x] = 1;

    while(!q.empty()) {

        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {

            int ny = cy + direct[i][0];
            int nx = cx + direct[i][1];

            if(ny < 0 || nx < 0 || ny >= N || nx >= N)
                continue;

            if(visited[ny][nx])
                continue;

            if(map[ny][nx] != num)
                continue;

            visited[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
}


// 분리된 미생물 제거
void check() {

    visited.assign(N, vector<int>(N, 0));

    vector<int> cnt(Q + 1, 0);

    // 미생물별 연결된 덩어리 개수 확인
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++) {

            int num = map[y][x];

            if(num == 0) continue;
            if(visited[y][x]) continue;

            cnt[num]++;
            bfs(y, x, num);
        }
    }

    // 2개 이상으로 분리되면 전체 제거
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++) {

            int num = map[y][x];

            if(num != 0 && cnt[num] >= 2) {
                map[y][x] = 0;
            }
        }
    }
}


// 현재 미생물 크기 및 좌표 계산
void updateInfo() {

    cells.assign(Q + 1, vector<pair<int, int>>());

    for(int i = 0; i < Q; i++) {
        informs[i].size = 0;
    }

    for(int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++) {

            int num = map[y][x];

            if(num == 0) continue;

            informs[num - 1].size++;
            cells[num].push_back({y, x});
        }
    }
}


// 크기 내림차순, 번호 오름차순
bool cmp(const info& a, const info& b) {

    if(a.size == b.size) {
        return a.num < b.num;
    }

    return a.size > b.size;
}


// 특정 위치에 배치 가능한지 검사
bool canMove(int startY, int startX, int num,
             int minY, int minX) {

    for(auto [y, x] : cells[num]) {

        int ny = startY + (y - minY);
        int nx = startX + (x - minX);

        if(ny < 0 || nx < 0 || ny >= N || nx >= N)
            return false;

        if(newmap[ny][nx] != 0)
            return false;
    }

    return true;
}


// 7. 새로운 배양 용기로 이동
void move() {

    newmap.assign(N, vector<int>(N, 0));

    // 정렬용 복사본
    vector<info> order = informs;

    sort(order.begin(), order.end(), cmp);

    for(auto micro : order) {

        int num = micro.num;

        if(micro.size == 0)
            continue;

        int minY = N;
        int minX = N;

        // 미생물의 최소 좌표
        for(auto [y, x] : cells[num]) {
            minY = min(minY, y);
            minX = min(minX, x);
        }

        bool placed = false;

        // x좌표 우선, 이후 y좌표
        for(int x = 0; x < N && !placed; x++) {
            for(int y = 0; y < N && !placed; y++) {

                if(!canMove(y, x, num, minY, minX))
                    continue;

                // 실제 배치
                for(auto [cy, cx] : cells[num]) {

                    int ny = y + (cy - minY);
                    int nx = x + (cx - minX);

                    newmap[ny][nx] = num;
                }

                placed = true;
            }
        }
    }

    // 새로운 배양 용기를 현재 용기로 교체
    map = newmap;
}


// 8. 실험 결과 계산
long long calculateScore() {

    vector<int> sizes(Q + 1, 0);
    vector<vector<int>> adjacent(
        Q + 1, vector<int>(Q + 1, 0)
    );

    // 현재 미생물별 크기
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++) {

            int num = map[y][x];

            if(num != 0)
                sizes[num]++;
        }
    }

    // 서로 인접한 미생물 확인
    for(int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++) {

            int a = map[y][x];

            if(a == 0) continue;

            for(int d = 0; d < 4; d++) {

                int ny = y + direct[d][0];
                int nx = x + direct[d][1];

                if(ny < 0 || nx < 0 || ny >= N || nx >= N)
                    continue;

                int b = map[ny][nx];

                if(b == 0 || a == b)
                    continue;

                int small = min(a, b);
                int large = max(a, b);

                adjacent[small][large] = 1;
            }
        }
    }

    long long ans = 0;

    // 인접한 미생물 쌍은 한 번만 계산
    for(int a = 1; a <= Q; a++) {
        for(int b = a + 1; b <= Q; b++) {

            if(adjacent[a][b]) {
                ans += 1LL * sizes[a] * sizes[b];
            }
        }
    }

    return ans;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;

    map.assign(N, vector<int>(N, 0));
    newmap.assign(N, vector<int>(N, 0));
    visited.assign(N, vector<int>(N, 0));

    informs.assign(Q, {});
    cells.resize(Q + 1);

    // 실험을 순서대로 진행
    for(int i = 0; i < Q; i++) {

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        informs[i] = {y1, x1, y2, x2, 0, i + 1};

        fill(y1, x1, y2, x2, i + 1);

        // 2. 분리된 미생물 제거
        check();

        // 3. 크기 및 실제 좌표 계산
        updateInfo();

        // 4. 새로운 배양 용기로 이동
        move();

        // 5. 실험 결과 출력
        cout << calculateScore() << '\n';
    }

    return 0;
}