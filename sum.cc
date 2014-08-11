#include <utility>
#include <unordered_map>
#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

using namespace std;

pair<int, int> 
twoSum(const vector<int>& v, int key) {
	unordered_map<int, int> idx;
	for(int i = 0; i < v.size(); ++i){idx[v[i]] = i;}

	for(int i = 0; i < v.size(); ++i) {
		int gap = key - v[i];
		if(idx.find(gap) != idx.end()){
			return make_pair(i, idx[gap]);	
		}
	}
	return make_pair(-1, -1);
}

TEST (twoSum, NormalCase) {
	int A[] = {1, 2, 3, 4};
	vector<int> v(A, A + sizeof(A)/sizeof(int));
	pair<int, int> ret = twoSum(v, 3);
	EXPECT_EQ(0, ret.first);
	EXPECT_EQ(1, ret.second);
}

vector<vector<int> > threeSum(vector<int>& v){
	vector<vector<int> > ret;
	sort(v.begin(), v.end());

	for(int i = 0; i < v.size() - 2; ++i){
		int j = i + 1;
		int k = v.size() - 1;
		while (j < k) {
			int expected = v[i] + v[j] + v[k];
			if (expected > 0) { k--; }
			else if (expected < 0) {j++; }
			else { 
				vector<int> r;
				r.push_back(v[i]);
				r.push_back(v[j]);
				r.push_back(v[k]);
				ret.push_back(r); 
				++j;
				--k;
			}
		}
	}
	sort(ret.begin(), ret.end());
	ret.erase(unique(ret.begin(), ret.end()), ret.end());
	return ret;
}

bool threeSumCheck(const vector<int>& v, const vector<vector<int> >& ret){
	for(auto i = ret.begin(); i != ret.end(); ++i) {
		int sum = accumulate(i->begin(), i->end(), 0);
		if(sum != 0) return false;
	}
	return true;
}

TEST (threeSum, NormalCase) {
	int A[] = {-1, 1, 0, 2, 4, -1};
	vector<int> v(A, A + sizeof(A)/sizeof(int));
	vector<vector<int> > result = threeSum(v);
	bool ret = threeSumCheck(v, result);
	EXPECT_EQ(true, ret);
	EXPECT_EQ(2, result.size());
}

TEST (threeSum, NegativeCase) {
	int A[] = {-1, 1, 2, 3, 4, 5};
	vector<int> v(A, A + sizeof(A)/sizeof(int));
	vector<vector<int> > result = threeSum(v);
	bool ret = threeSumCheck(v, result);
	EXPECT_EQ(0, result.size());
}

int main(int argc, char** argv){
	
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
