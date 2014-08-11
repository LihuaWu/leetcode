#include <iostream>
#include <algorithm>
#include <vector>

#include <gtest/gtest.h>

using namespace std;

int trapRainWater(const vector<int>& v) {
	int idx = 0;
	int size = v.size();
	for(int i = 0; i < size; ++i) {
		if (v[i] > v[idx]) {
			idx = i;	
		}
	}
	int ret = 0;
	for (int i = 0, peak = 0; i < idx; ++i) {
		if (v[i] > peak) peak = v[i];
		else ret += peak - v[i];
	}
	for (int i = size - 1, peak = 0; i > idx; --i) {
		if (v[i] > peak) peak = v[i];
		else ret += peak - v[i];
	}
	return ret;
}

TEST (trapRainWater, peakCase) {
	int A[] = {0, 2, 0};
	vector<int> v(A, A + sizeof(A)/sizeof(int));
	int ret = trapRainWater(v);
	EXPECT_EQ(0, ret);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
