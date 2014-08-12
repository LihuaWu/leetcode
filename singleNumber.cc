#include <vector>

#include <gtest/gtest.h>

using namespace std;

int singleNumber(const vector<int>& v) {
	int x = 0;
	for(int i = 0; i < v.size(); ++i) {
		x ^= v[i];
	}
	return x;
}

TEST (singleNumber, case1) {
	int A[] = {1, 2, 2, 3, 3, 4, 4};
	vector<int> v(A, A + sizeof(A)/sizeof(int));
	int ret = singleNumber(v);
	EXPECT_EQ(1, ret);
}

TEST (singleNumber, case2) {
	int A[] = {1, 1, 2, 2, 3, 3, 4, 4};
	vector<int> v(A, A + sizeof(A)/sizeof(int));
	int ret = singleNumber(v);
	EXPECT_EQ(0, ret);
}

TEST (singleNumber, case3) {
	int A[] = {1, 1, 2, 2, 3, 3, 4, 4, 1, 2};
	vector<int> v(A, A + sizeof(A)/sizeof(int));
	int ret = singleNumber(v);
	EXPECT_EQ(3, ret);
}

int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
