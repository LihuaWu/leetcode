#include <algorithm>

#include <gtest/gtest.h>

using namespace std;

void addK(vector<int>& v, int k) {
	int carry = k;
	int size = v.size();
	for(int i = size - 1; i >= 0; --i) {
		v[i] += carry;
		carry = v[i] / 10;
		v[i] %= 10;
	}
	if(carry > 0){
		v.insert(v.begin(), carry);
	}
}

vector<int> plusOne(vector<int>& v) {
	addK(v, 1);
	return v;
}

bool check(const vector<int>& v, int expected[]) {
	for(int i = 0; i < v.size(); ++i) {
		if(v[i] != expected[i]) return false;
	}
	return true;
}

TEST (plusOne, NormalCase) {
	int A[] = {1, 2, 3, 4};
	vector<int> v(A, A + sizeof(A)/sizeof(int));
	plusOne(v);
	int expected[] = {1, 2, 3, 5};
	bool ret = check(v, expected);
	EXPECT_EQ(true, ret);
}

TEST (plusOne, boundary) {
	int a[] = {9, 9, 9};
	vector<int> v(a, a + sizeof(a)/sizeof(int));
	plusOne(v);
	int expected[] = {1, 0, 0, 0};
	bool ret = check(v, expected);
	EXPECT_EQ(true, ret);
}

TEST (plusOne, inNormal) {
	int a[] = {0, 9, 9, 9};
	vector<int> v(a, a + sizeof(a)/sizeof(int));
	plusOne(v);
	int expected[] = {1, 0, 0, 0};
	bool ret = check(v, expected);
	EXPECT_EQ(true, ret);
}

TEST (plusOne, inNormal2) {
	int a[] = {0, 0, 9, 9, 9};
	vector<int> v(a, a + sizeof(a)/sizeof(int));
	plusOne(v);
	int expected[] = {0, 1, 0, 0, 0};
	bool ret = check(v, expected);
	EXPECT_EQ(true, ret);
}

int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
