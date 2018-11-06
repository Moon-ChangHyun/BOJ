#include<cstdio>
#include<array>
#include<cmath>
#include<algorithm>
using namespace std;

class vec {
private:
	int x;
	int y;
public:
	vec(int inX, int inY) : x(inX), y(inY) {}
	friend const vec operator+(const vec& lhs, const vec& rhs) {
		return vec(lhs.x + rhs.x, lhs.y + rhs.y);
	}
	friend const bool operator==(const vec& lhs, const vec& rhs) {
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}
	const int dotProduct(vec& rhs) {
		return x * rhs.x + y * rhs.y;
	}
	const double size() {
		return sqrt(double(x)*x + double(y)*y);
	}
};

int main() {
	int T, x, y;
	long long a, b, c;
	array<pair<int, int>, 4> arr;
	scanf("%d", &T);
	for (int t = 0; t != T; ++t) {
		for (int i = 0; i != 4; ++i) {
			scanf("%d%d", &x, &y);
			arr[i] = { x,y };
		}
		sort(arr.begin(), arr.end());
		vec a(arr[1].first - arr[0].first, arr[1].second - arr[0].second);
		vec b(arr[2].first - arr[0].first, arr[2].second - arr[0].second);
		vec c(arr[3].first - arr[0].first, arr[3].second - arr[0].second);
		printf("%d\n", (!a.dotProduct(b) && a + b == c && a.size() == b.size()) ? 1 : 0);
	}
}