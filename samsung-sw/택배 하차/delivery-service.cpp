#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info {
    int w;
    int h;
    int c;
    int sy;
    int sx;
};

int N, M;

vector<vector<int>> arr;
vector<info> inform;

vector<int> order;       // 입력 순서
vector<int> numOrder;    // 택배 번호 오름차순
vector<int> ans;


// 택배 하나를 한 칸 아래로 떨어뜨리기
bool drop(int num) {

    int sy = inform[num].sy;
    int sx = inform[num].sx;

    int h = inform[num].h;
    int w = inform[num].w;

    int ey = sy + h - 1;
    int ex = sx + w - 1;


    // 이미 바닥에 닿아 있음
    if(ey == N)
        return false;


    // 바로 아래 한 줄 확인
    for(int x = sx; x <= ex; x++) {

        if(arr[ey + 1][x] != 0)
            return false;
    }


    // 한 칸 아래로 이동

    // 기존 맨 위 한 줄 삭제
    for(int x = sx; x <= ex; x++) {
        arr[sy][x] = 0;
    }

    // 새로운 맨 아래 한 줄 생성
    for(int x = sx; x <= ex; x++) {
        arr[ey + 1][x] = num;
    }


    // 현재 행 갱신
    inform[num].sy++;


    return true;
}


// 최초 택배 투입
void insert() {

    // 입력된 순서대로 투입
    for(int num : order) {

        int x = inform[num].c;
        int w = inform[num].w;
        int h = inform[num].h;


        // 맨 위에서 시작
        inform[num].sy = 1;
        inform[num].sx = x;


        // 맨 위에 택배 생성
        for(int y = 1; y <= h; y++) {

            for(int c = x; c < x + w; c++) {

                arr[y][c] = num;
            }
        }


        // 더 이상 떨어질 수 없을 때까지
        while(drop(num)) {
        }
    }
}


// 제거 후 모든 택배에 중력 적용
void gravity() {

    while(true) {

        bool moved = false;


        for(int num : order) {

            // 이미 제거된 택배
            if(inform[num].sy == -1)
                continue;


            // 한 칸 떨어뜨리기
            if(drop(num))
                moved = true;
        }


        // 아무 택배도 움직이지 않았으면 종료
        if(!moved)
            break;
    }
}


// 왼쪽으로 하차
void left() {

    // 번호가 작은 택배부터 검사
    for(int num : numOrder) {

        int sy = inform[num].sy;
        int sx = inform[num].sx;


        // 이미 제거된 택배
        if(sy == -1)
            continue;


        int ey = sy + inform[num].h - 1;
        int ex = sx + inform[num].w - 1;

        bool possible = true;


        // 현재 택배의 왼쪽 공간 확인
        for(int y = sy; y <= ey; y++) {

            for(int x = 1; x < sx; x++) {

                if(arr[y][x] != 0) {

                    possible = false;
                    break;
                }
            }

            if(!possible)
                break;
        }


        // 왼쪽으로 빠질 수 없음
        if(!possible)
            continue;


        // 택배 제거
        for(int y = sy; y <= ey; y++) {

            for(int x = sx; x <= ex; x++) {

                arr[y][x] = 0;
            }
        }


        // 하차 순서 저장
        ans.push_back(num);


        // 제거 표시
        inform[num].sy = -1;
        inform[num].sx = -1;


        // 남아있는 택배 중력 적용
        gravity();


        // 한 번에 하나만 제거
        return;
    }
}


// 오른쪽으로 하차
void right() {

    // 번호가 작은 택배부터 검사
    for(int num : numOrder) {

        int sy = inform[num].sy;
        int sx = inform[num].sx;


        // 이미 제거된 택배
        if(sy == -1)
            continue;


        int ey = sy + inform[num].h - 1;
        int ex = sx + inform[num].w - 1;

        bool possible = true;


        // 현재 택배의 오른쪽 공간 확인
        for(int y = sy; y <= ey; y++) {

            for(int x = ex + 1; x <= N; x++) {

                if(arr[y][x] != 0) {

                    possible = false;
                    break;
                }
            }

            if(!possible)
                break;
        }


        // 오른쪽으로 빠질 수 없음
        if(!possible)
            continue;


        // 택배 제거
        for(int y = sy; y <= ey; y++) {

            for(int x = sx; x <= ex; x++) {

                arr[y][x] = 0;
            }
        }


        // 하차 순서 저장
        ans.push_back(num);


        // 제거 표시
        inform[num].sy = -1;
        inform[num].sx = -1;


        // 남아있는 택배 중력 적용
        gravity();


        // 한 번에 하나만 제거
        return;
    }
}


int main() {

    cin >> N >> M;


    // 1-based
    arr.assign(N + 1, vector<int>(N + 1, 0));

    // 택배 번호 최대 100
    inform.assign(101, {});


    // 입력
    for(int i = 0; i < M; i++) {

        int k, h, w, c;

        cin >> k >> h >> w >> c;


        inform[k].w = w;
        inform[k].h = h;
        inform[k].c = c;


        // 입력 순서 저장
        order.push_back(k);
    }


    // 택배 번호 오름차순
    numOrder = order;

    sort(numOrder.begin(), numOrder.end());


    // 1. 최초 택배 투입
    insert();


    // 2. LEFT
    // 3. RIGHT
    // 반복
    for(int turn = 0; turn < M; turn++) {

        // 짝수 turn -> 왼쪽
        if(turn % 2 == 0) {

            left();
        }

        // 홀수 turn -> 오른쪽
        else {

            right();
        }
    }


    // 하차 순서 출력
    for(int num : ans) {

        cout << num << '\n';
    }


    return 0;
}