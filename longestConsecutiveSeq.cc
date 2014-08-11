#include <vector>
#include <unordered_map>
#include <algorithm>

#include <gtest/gtest.h>

using namespace std;

int longestConsecutiveSeq(const vector<int>& v){
	typedef unordered_map<int, bool> cache_type;
	cache_type cache;
	for (auto i: v)
		cache[i] = false;
	int max_len = 1;
	for(auto i: v) {
		if (cache[i]) continue;
		int len = 1;
		cache[i] = true;
		for(int j = i + 1; cache.find(j) != cache.end(); ++j){
			cache[j] = true;
			++len;	
		}
		for(int j = i - 1; cache.find(j) != cache.end(); --j){
			cache[j] = true;
			++len;
		}
		max_len = max(len, max_len);
	}
	return max_len;
}

TEST (longestConsecutiveSeq, NormalCase) {
	int A[] = {100, 4, 200, 1, 3, 2};
	vector<int> v(A, A + sizeof(A)/sizeof(int));
	int ret = longestConsecutiveSeq(v);
	EXPECT_EQ(4, ret);
}


int main(int argc, char** argv) {

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
