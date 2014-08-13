#include <vector>

#include <gtest/gtest.h>

#include "ListNode.h"

using namespace std;

TEST (ListAdd, Case1) {
	int A[] = {1, 2, 3, 4, 5, 6, 7};
	int B[] = {1, 2};
	int C[] = {2, 4, 3, 4, 5, 6, 7};


	vector<int> l(A, A + sizeof(A)/sizeof(int));
	vector<int> r(B, B + sizeof(B)/sizeof(int));
	vector<int> expected(C, C + sizeof(C)/sizeof(int));

	ListNode* a = vector2List(l);
	ListNode* b = vector2List(r);

	ListNode* result = add(a, b);

	vector<int> ret;
	list2vector(result, ret);
	EXPECT_EQ(expected, ret);
}

TEST (ListAdd, Case2) {
	int A[] = {1, 2, 3, 4, 5, 6, 7};
	int B[] = {9, 9, 9, 9, 9, 9, 9};
	int C[] = {0, 2, 3, 4, 5, 6, 7, 1};


	vector<int> l(A, A + sizeof(A)/sizeof(int));
	vector<int> r(B, B + sizeof(B)/sizeof(int));
	vector<int> expected(C, C + sizeof(C)/sizeof(int));

	ListNode* a = vector2List(l);
	ListNode* b = vector2List(r);

	ListNode* result = add(a, b);

	vector<int> ret;
	list2vector(result, ret);
	EXPECT_EQ(expected, ret);
}

int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
