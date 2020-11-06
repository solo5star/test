#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>

using namespace std;

int parents[1000000];

int parent(int n) {
	if (parents[n] == n) return n;

	return parents[n] = parent(parents[n]);
}

void merge(int a, int b) {
	int _a = parent(a);
	int _b = parent(b);

	if (_a != _b) {
		parents[a] = _b;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, c, a, b;
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		parents[i] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> c >> a >> b;

		if (c == 0) {
			merge(a, b);
		}
		else {
			cout << (parent(a) == parent(b) ? "YES" : "NO") << "\n";
		}
	}
}