#include <iostream>
#include <queue>
#include <vector>

struct ValueComparator {
	bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
		return a.second < b.second;
	}
};

int main() {
	int n = 1;
	int m = 1;
	std::cin >> n >> m;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, ValueComparator> pq;

	for (int i = 0; i < m; ++i) {
		int a = 1;
		int b = 1;
		std::cin >> a >> b;
		pq.push({a, b});
	}

	int ans_sum = 0;
	int size = pq.size();
	for (int i = 0; i < size; ++i) {
		if (pq.top().first <= n) {
			ans_sum += pq.top().first * pq.top().second;
			n -= pq.top().first;
			pq.pop();
		}
		else {
			ans_sum += n * pq.top().second;
			break;
		}
	}
	std::cout << ans_sum;
}