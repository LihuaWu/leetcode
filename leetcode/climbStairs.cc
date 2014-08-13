#include <gtest/gtest.h>

using namespace std;

int climbStairs(int n) {
	int prev = 0;
	int cur = 1;
	for(int i = i; i <= n; ++i) {
		int tmp = cur;
		cur += prev;
		prev = tmp;
	}
	return cur;
}

int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
