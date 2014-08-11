#include <iostream>
#include <algorithm>
#include <vector>

#include <gtest/gtest.h>

using namespace std;

int trapRainWater(const vector<int>& v) {
	int max_height = 0;
	int idx = 0;
	for(int i = 0; i < v.size(); ++i) {
		if (v[i] > max_height) {
			max_height = v[i];
			idx = i;	
		}
	}
	int ret = 0;
	for (int i = 0, peak = 0; i < idx; ++i) {
		if (A[i] > peak) peak = A[i];
		else ret += max_height - v[i];
	}
	for (int i = n - 1, peak = 0; i > idx; --i) {
		if (A[i] > peak) peak = A[i];
		else ret += max_height - v[i];
	}
	return ret;
}

int main() {
	return 0;
}
