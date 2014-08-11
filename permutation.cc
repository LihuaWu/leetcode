#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

#include <gtest/gtest.h>

using namespace std;

void nextPermutation(vector<int>& v) {
	auto pivot = next(v.rbegin());
	while(pivot != v.rend() && *pivot >= *prev(pivot)) ++pivot; 
	//not found, already in descending order,just reverse the whole sequence
	if(pivot == v.rend()) {reverse(v.begin(), v.end()); return; }

	auto change = find_if(v.rbegin(), pivot, bind1st(less<int>(), *pivot));
	iter_swap(change, pivot);
	//reverse to make sure the partial sequence remain in descending order
	reverse(v.rbegin(), pivot);
}

TEST (nextPermutation, NormalCase) {
	int A[] = {3, 2, 1, 4};
	vector<int> v(A, A+sizeof(A)/sizeof(int));
	int i = 0;
	while(i++ < 7) {
		copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
		cout<<endl;
		nextPermutation(v);
	}
	EXPECT_EQ(1, 1);
	EXPECT_EQ(1, 1);
}


int main(int argc, char** argv){
	
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
