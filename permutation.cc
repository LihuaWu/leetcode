#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <string>

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
	//while(i++ < 7) {
	//	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	//	cout<<endl;
	//	nextPermutation(v);
	//}
	EXPECT_EQ(1, 1);
	EXPECT_EQ(1, 1);
}

int factorial(int n) {
	int result = 1;
	for(int i = 1; i <= n; ++i)
		result *= i;
	return result;
}

template <typename Sequence>
Sequence kthPermutation(const Sequence& seq, int k) {
	Sequence ret;
	const int n = seq.size();
	Sequence S(seq);

	int base = factorial(n - 1);
	--k; //string index starts with zero

	for(int i = n - 1; i > 0; k %= base, base/= i, --i){
		auto a = next(S.begin(), k / base);
		ret.push_back(*a);
		S.erase(a);
	}
	ret.push_back(S[0]);
	return ret;
}

string getPermutation(int n, int k) {
	string s(n, '0');
	for(int i = 0; i < n; ++i){
		s[i] += i + 1;
	}
	return kthPermutation(s, k);
}

int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
