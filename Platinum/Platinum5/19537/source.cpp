// 504ms, 4188KB

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
constexpr int MAXWIDTH = 500;
constexpr int MAXHEIGHT = 500;
constexpr int MAXNUMGEOTYPE = 9;
const int around4y[4] = { -1, 0, 1, 0 };
const int around4x[4] = { 0, 1, 0, -1 };
struct Point {
    int y, x;
    bool operator==(const Point& rhs) {
        return y == rhs.y && x == rhs.x;
    }
    bool operator!=(const Point& rhs) {
        return !operator==(rhs);
    }
};
struct sliding5Q {
    int base = 0;
    int baseIdx = 0;
    int size = 0;
    queue<Point> q[5];
    void push(Point val, int cost) {
        if (base + 5 <= cost) {
            int sub = cost - base;
            int idx = (baseIdx + sub) % 5;
            q[idx].push(val);
            baseIdx = (idx + 1) % 5;
            base = cost - 4;
        }
        else {
            q[(baseIdx + cost - base) % 5].push(val);
        }
        ++size;
    }
    bool empty() {
        return size == 0;
    }

    pair<Point, int> top() {
        for (int k = 0; k < 5; ++k) {
            int idx = (baseIdx + k) % 5;
            if (!q[idx].empty()) {
                return { q[idx].front(), base + k };
            }
        }
        return { {-1,-1},-1 };
    }

    void pop() {
        for (int k = 0; k < 5; ++k) {
            int idx = (baseIdx + k) % 5;
            if (!q[idx].empty()) {
                q[idx].pop();
                --size;
                break;
            }
        }
    }
};
struct UnitInfo {
    char movement;
    char team;
    Point position;
};
int N, H, W, M, K;
char geometry[MAXHEIGHT][MAXWIDTH];
int deltaMove[MAXNUMGEOTYPE + 1];
int locatedUnit[MAXHEIGHT][MAXWIDTH];
bool visit[MAXHEIGHT][MAXWIDTH];
vector<UnitInfo> unitInfo;
bool anyBodyAround(char team, int y, int x) {
    for (int k = 0; k != 4; ++k) {
        int nY = y + around4y[k];
        int nX = x + around4x[k];
        if (0 <= nY && nY < H && 0 <= nX && nX < W) {
            int anyone = locatedUnit[nY][nX];
            if (anyone && unitInfo[anyone].team == team)
                return true;
        }
    }
    return false;
}
void moveAction(int unitNum, int y, int x) {
    if (locatedUnit[y][x]) return;
    auto startPoint = unitInfo[unitNum].position;
    auto& uInfo = unitInfo[unitNum];
    if (abs(y - uInfo.position.y) + abs(x - uInfo.position.x) > uInfo.movement) return;
    int sY = max(0, uInfo.position.y - uInfo.movement), eY = min(H, uInfo.position.y + uInfo.movement + 1);
    int sX = max(0, uInfo.position.x - uInfo.movement), eX = min(W, uInfo.position.x + uInfo.movement + 1);
    for (int i = sY; i < eY; ++i)
        for (int j = sX; j < eX; ++j)
            visit[i][j] = false;
    sliding5Q pq;
    pq.push(startPoint, 0);
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int dist = cur.second;
        auto pos = cur.first;
        for (int k = 0; k < 4; ++k) {
            int ny = pos.y + around4y[k];
            int nx = pos.x + around4x[k];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W || visit[ny][nx]) continue;
            int dm = deltaMove[geometry[ny][nx]];
            if (dm == -1 || dist + dm > uInfo.movement) continue;
            if (ny == y && nx == x) {
                uInfo.position = { y, x };
                locatedUnit[startPoint.y][startPoint.x] = 0;

                locatedUnit[y][x] = unitNum;
                return;
            }
            int locatedUnitNum = locatedUnit[ny][nx];
            if (locatedUnitNum && unitInfo[locatedUnitNum].team != uInfo.team) continue;
            visit[ny][nx] = true;
            if (anyBodyAround(1 - uInfo.team, ny, nx))
                continue;
            pq.push({ ny, nx }, dist + dm);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> H >> W;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int x;
            cin >> x;
            geometry[i][j] = x;
        }
    }
    for (int i = 1; i <= N; ++i)
        cin >> deltaMove[i];
    cin >> M;
    unitInfo.resize(M + 1);
    for (int i = 1; i <= M; ++i) {
        int mv, tm, y, x;
        cin >> mv >> tm >> y >> x;
        unitInfo[i] = { (char)mv, (char)tm, Point{y, x} };
        locatedUnit[y][x] = i;
    }
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int unitNum, targetY, targetX;
        cin >> unitNum >> targetY >> targetX;
        moveAction(unitNum, targetY, targetX);
    }
    for (int i = 1; i <= M; ++i) {
        cout << unitInfo[i].position.y << ' ' << unitInfo[i].position.x << '\n';
    }
}