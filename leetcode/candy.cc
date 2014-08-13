#include <vector>
#include <numeric>

#include <gtest/gtest.h>

using namespace std;

int candy(const vector<int>& ratings) {
	const int n = ratings.size();
	vector<int> v(n, 0);

	for(int i = 1, incr = 1; i < n; i++) {
		if (ratings[i] > ratings[i - 1]) {
			v[i] = max(incr, v[i]);
			++incr;
		} else {
			incr = 1;
		}
	}

	for(int i = n - 2, incr = 1; i >= 0; --i) {
		if (ratings[i] > ratings[i + 1]) {
			v[i] = max(incr, v[i]);
			++incr;
		} else {
			incr = 1;
		}
	}
	return accumulate(v.begin(), v.end(), n);
}

TEST (candy, NormalCase) {
	int A[] = {1, 2, 2, 3, 3, 2};
	vector<int> rating(A, A + sizeof(A)/sizeof(int));
	int ret = candy(rating);
	EXPECT_EQ(9, ret);	
}


int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
