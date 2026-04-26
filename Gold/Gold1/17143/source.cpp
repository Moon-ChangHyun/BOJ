// 88ms, 2968KB

#include<iostream>
#include<vector>
using namespace std;

int R, C, M, pos = -1;
vector<vector<int>> map; //map[행][열] = 상어id, 빈칸은 -1

struct shark {
	static int counter;
	int id;
	int yPos;
	int xPos;
	int spd;
	int dir;
	int sz;
	bool catched = false;

	void step() {
		switch (dir) {
		case 0: //U
		{
			int ny = yPos - spd;
			if (ny <= 0) {
				dir = 1;
				ny = -ny;
				if (ny >= R - 1) {
					dir = 0;
					ny = 2 * (R - 1) - ny;
				}
			}
			yPos = ny;
			break;
		}
		case 1: //D
		{
			int ny = yPos + spd;
			if (ny >= R - 1) {
				dir = 0;
				ny = 2 * (R - 1) - ny;
				if (ny <= 0) {
					dir = 1;
					ny = -ny;
				}
			}
			yPos = ny;
			break;
		}
		case 2: //R
		{
			int nx = xPos + spd;
			if (nx >= C - 1) {
				dir = 3;
				nx = 2 * (C - 1) - nx;
				if (nx <= 0) {
					dir = 2;
					nx = -nx;
				}
			}
			xPos = nx;
			break;
		}
		case 3: //L
		{
			int nx = xPos - spd;
			if (nx <= 0) {
				dir = 2;
				nx = -nx;
				if (nx >= C - 1) {
					dir = 3;
					nx = 2 * (C - 1) - nx;
				}
			}
			xPos = nx;
			break;
		}
		}
	}
};

int shark::counter = -1;
vector<shark> sharks;

istream& operator>> (istream& is, shark& sk) {
	sk.id = ++shark::counter;
	is >> sk.yPos >> sk.xPos >> sk.spd >> sk.dir >> sk.sz;
	map[--sk.yPos][--sk.xPos] = sk.id;
	if (--sk.dir < 2) {
		int unit = 2 * (R - 1);
		sk.spd %= unit;
	}
	else {
		int unit = 2 * (C - 1);
		sk.spd %= unit;
	}
	return is;
}

int simulation() {
	int ans = 0;
	++pos;
	for (int i = 0; i < R; ++i) {
		auto& sharkID = map[i][pos];
		if (sharkID != -1) {
			ans += sharks[sharkID].sz;
			sharks[sharkID].catched = true;
			sharkID = -1;
			break;
		}
	}
	
	vector<vector<int>> lstMap(R * C); // lstMap[1차원인덱스] = shark번호 리스트
	for (auto& sk : sharks) {
		map[sk.yPos][sk.xPos] = -1;
		if (sk.catched)
			continue;
		sk.step();
		int idx = sk.yPos * C + sk.xPos;
		lstMap[idx].push_back(sk.id);
	}

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			int idx = i * C + j;
			auto& lst = lstMap[idx];
			if (lst.empty())
				continue;
			if (lst.size() > 1) {
				int largest = 0;
				for (int k = 1; k < lst.size(); ++k) {
					if (sharks[lst[k]].sz > sharks[lst[largest]].sz)
						largest = k;
				}
				for (int k = 0; k < lst.size(); ++k) {
					if (k == largest)
						continue;
					sharks[lst[k]].catched = true;
				}
				auto& sk = sharks[lst[largest]];
				map[sk.yPos][sk.xPos] = sk.id;
			}
			else {
				auto& sk = sharks[lst[0]];
				map[sk.yPos][sk.xPos] = sk.id;
			}
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> R >> C >> M;
	sharks.resize(M);
	map.resize(R, vector<int>(C, -1));

	for (auto& sk : sharks)
		cin >> sk;
	
	int ans = 0;
	for (int i = 0; i < C; ++i)
		ans += simulation();
	cout << ans;
}