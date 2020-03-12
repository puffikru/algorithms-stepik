#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool CanBuild(const vector<int>& milestones, int new_cafe_count, int max_dist) {
	int build = 0;
	int last = 0;
	for (size_t i = 0; i < milestones.size() && build <= new_cafe_count; i++) {
		while (milestones[i] - last > max_dist && build <= new_cafe_count) {
			build++;
			last += max_dist;
		}
		last = milestones[i];
	}
	return build <= new_cafe_count;
}

int main() {
	int road_length, new_cafe_count;
	cin >> road_length >> new_cafe_count;
	int milestone_count;
	cin >> milestone_count;
	vector<int> milestones(milestone_count);
	for (int& x : milestones) {
		cin >> x;
	}
	milestones.push_back(road_length);
	sort(begin(milestones), end(milestones));

	int l = 1;
	int r = road_length;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (CanBuild(milestones, new_cafe_count, m)) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	cout << r + 1;
}
