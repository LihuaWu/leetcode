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

ListNode* array2List(int* A, int n) {
	vector<int> r(A, A + n);
	return vector2List(r);
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

TEST (listReverse, Case1) {
	int A[] = {1, 2, 3, 4, 5, 6};	
	int B[] = {1, 5, 4, 3, 2, 6};

	ListNode* a = array2List(A, sizeof(A)/sizeof(int));
	vector<int> expected(B, B + sizeof(B)/sizeof(int));

	ListNode* result = partialReverseList(a, 2, 5);
	vector<int> ret;
	list2vector(result, ret);
	EXPECT_EQ(expected, ret);
}

TEST (listPartition, Case1) {
	int A[] = {2, 3, 6, 3, 2, 1, 4};
	int B[] = {2, 2, 1, 3, 6, 3, 4};

	ListNode* a = array2List(A, sizeof(A)/sizeof(int));
	vector<int> expected(B, B + sizeof(B)/sizeof(int));

	ListNode* result = listPartition(a, 3);
	vector<int> ret;
	list2vector(result, ret);
	EXPECT_EQ(expected, ret);
}

TEST (listRemoveDuplicates, Case1) {
	int A[] = {1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 6, 7};
	int B[] = {1, 2, 3, 4, 5, 6, 7};

	ListNode* a = array2List(A, sizeof(A)/sizeof(int));
	vector<int> expected(B, B + sizeof(B)/sizeof(int));

	ListNode* result = listRemoveDuplicates(a);
	vector<int> ret;
	list2vector(result, ret);
	EXPECT_EQ(expected, ret);
}

TEST (listRemoveDuplicates2, Case1) {
	int A[] = {1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 6, 7};
	int B[] = {1, 7};

	ListNode* a = array2List(A, sizeof(A)/sizeof(int));
	vector<int> expected(B, B + sizeof(B)/sizeof(int));

	ListNode* result = listRemoveDuplicates2(a);
	vector<int> ret;
	list2vector(result, ret);
	EXPECT_EQ(expected, ret);
}

TEST (listRotate, Case1) {
	int A[] = {1, 2, 3, 4, 5};
	int B[] = {3, 4, 5, 1, 2};

	ListNode* a = array2List(A, sizeof(A)/sizeof(int));
	vector<int> expected(B, B + sizeof(B)/sizeof(int));
	
	ListNode* result = listRotate(a, 3);
	vector<int> ret;
	list2vector(result, ret);
	EXPECT_EQ(expected, ret);
}

TEST (listRotate, Case2) {
	int A[] = {1};
	int B[] = {1};

	ListNode* a = array2List(A, sizeof(A)/sizeof(int));
	vector<int> expected(B, B + sizeof(B)/sizeof(int));

	ListNode* result = listRotate(a, 1);
	vector<int> ret;
	list2vector(result, ret);
	EXPECT_EQ(expected, ret);
}

TEST (listRotate, Case3) {
	int A[] = {};
	int B[] = {};

	ListNode* a = array2List(A, sizeof(A)/sizeof(int));
	vector<int> expected(B, B + sizeof(B)/sizeof(int));

	ListNode* result = listRotate(a, 0);
	vector<int> ret;
	list2vector(result, ret);
	EXPECT_EQ(expected, ret);
}

TEST (removeNthNodeFromEnd, Case1) {
	int A[] = {1, 2, 3, 4, 5};
	int B[] = {1, 2, 3, 5};

	ListNode* a = array2List(A, sizeof(A)/sizeof(int));
	vector<int> expected(B, B + sizeof(B)/sizeof(int));

	ListNode* result = removeNthNodeFromEnd(a, 2);

	vector<int> ret;
	list2vector(result, ret);
	EXPECT_EQ(expected, ret);
}

TEST (removeNthNodeFromEnd, Case2) {
	int A[] = {1, 2, 3, 4, 5};
	int B[] = {1, 2, 3, 5};

	ListNode* a = array2List(A, sizeof(A)/sizeof(int));
	vector<int> expected(B, B + sizeof(B)/sizeof(int));

	ListNode* result = removeNthNodeFromEnd(a, 2);

	vector<int> ret;
	list2vector(result, ret);
	EXPECT_EQ(expected, ret);
}

TEST (nodeSwap, Case1) {
	int A[] = {1, 2, 3, 4, 5};
	int B[] = {2, 1, 4, 3, 5};

	ListNode* a = array2List(A, sizeof(A)/sizeof(int));
	vector<int> expected(B, B + sizeof(B)/sizeof(int));

	ListNode* result = nodeSwap(a);

	vector<int> ret;
	list2vector(result, ret);
	EXPECT_EQ(expected, ret);
}

TEST (reverseNodesInKGroup, Case1) {
	int A[] = {1, 2, 3, 4, 5};
	int B[] = {2, 1, 4, 3, 5};

	ListNode* a = array2List(A, sizeof(A)/sizeof(int));
	vector<int> expected(B, B + sizeof(B)/sizeof(int));

	ListNode* result = reverseNodesInKGroup2(a, 2);

	vector<int> ret;
	list2vector(result, ret);
	EXPECT_EQ(expected, ret);
	
}

TEST (reverseNodesInKGroup, Case2) {
	int A[] = {1, 2, 3, 4, 5};
	int B[] = {3, 2, 1, 4, 5};

	ListNode* a = array2List(A, sizeof(A)/sizeof(int));
	vector<int> expected(B, B + sizeof(B)/sizeof(int));

	ListNode* result = reverseNodesInKGroup2(a, 3);

	vector<int> ret;
	list2vector(result, ret);
	EXPECT_EQ(expected, ret);
	
}

int main(int argc, char** argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
