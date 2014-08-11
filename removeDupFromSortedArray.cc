#include <iostream>
#include <algorithm>
#include <iterator>
#include <assert.h>
#include <gtest/gtest.h>



using namespace std;

int removeDupFromSortedArray(int* A, int len){
	if(A == NULL || len < 0) 
		return -1;

	int tail = 0;
	for(int i = 1; i < len; ++i){
		if(A[tail] != A[i]){
			++tail;
			A[tail] = A[i];
		}
	}
	return tail + 1;
}

int isEqualArray(int* A, int* B, int lenA, int lenB){
	if(lenA != lenB) return -1;
	for(int i = 0; i < lenA; ++i){
		if(A[i] != B[i])
			return -1;
	}
	return 0;
}

TEST (RemoveDupTest, WithDup) {
	int A[] = {1, 2, 3, 4, 5, 6, 7, 7};
	int len = sizeof(A)/sizeof(int);

	int expected[] = {1, 2, 3, 4, 5, 6, 7};
	int lenE = sizeof(expected)/sizeof(int);

	len = removeDupFromSortedArray(A, len);
	int ret = isEqualArray(A, expected, len, lenE);
	
	EXPECT_EQ (ret, 0);
}


TEST (RemoveDup, WithNoDup) {
	int A[] = {1, 2, 3, 4, 5, 6, 7};
	int len = sizeof(A)/sizeof(int);

	int expected[] = {1, 2, 3, 4, 5, 6, 7};
	int lenE = sizeof(expected)/sizeof(int);

	len = removeDupFromSortedArray(A, len);
	int ret = isEqualArray(A, expected, len, lenE);
	
	EXPECT_EQ (ret, 0);
}

TEST (RemoveDup, arrayLengthLessThanZero) {
	int A[] = {1, 2, 3, 4, 5, 6, 7};
	int len = sizeof(A)/sizeof(int);

	int expected[] = {1, 2, 3, 4, 5, 6, 7};
	int lenE = sizeof(expected)/sizeof(int);

	len = -1;

	len = removeDupFromSortedArray(A, len);
	int ret = isEqualArray(A, expected, len, lenE);
	
	EXPECT_EQ (ret, -1);
}

TEST (RemoveDup, arrNullPointer) {
	int A[] = {1, 2, 3, 4, 5, 6, 7};
	int len = sizeof(A)/sizeof(int);

	int expected[] = {1, 2, 3, 4, 5, 6, 7};
	int lenE = sizeof(expected)/sizeof(int);

	int *p = NULL;
	len = removeDupFromSortedArray(p, len);
	int ret = isEqualArray(p, expected, len, lenE);
	
	EXPECT_EQ (ret, -1);
}


int removeDup2FromArray(int* A, int n) {
	if (A == NULL || n < 0) return -1;
	if (n <= 2) return n;

	int tail = 2;
	//since the array is sorted, we wouldn't need to consider the following condition:
	//3, 5, 3
	//we only have conditions like this:
	//3, 3, 3
	//3, 3, 4
	//3, 4, 4
	//3, 4, 5
	for(int i = 2; i < n; ++i){
		if(A[tail - 2] != A[i]){
			A[tail++] = A[i];
		}
	}
	return tail;
}

TEST (RemoveDup2, WithDup) {
	int A[] = {1, 2, 3, 3, 3, 5};
	int len = sizeof(A)/sizeof(int);

	int expected[] = {1, 2, 3, 3, 5};
	int lenE = sizeof(expected)/sizeof(int);

	len = removeDup2FromArray(A, len);
	int ret = isEqualArray(A, expected, len, lenE);
	
	EXPECT_EQ (ret, 0);
}

TEST (RemoveDup2, With2Dup) {
	int A[] = {1, 1, 1, 2, 2, 3, 3, 3, 5};
	int len = sizeof(A)/sizeof(int);

	int expected[] = {1, 1, 2, 2, 3, 3, 5};
	int lenE = sizeof(expected)/sizeof(int);

	len = removeDup2FromArray(A, len);
	int ret = isEqualArray(A, expected, len, lenE);
	
	EXPECT_EQ (ret, 0);
}

int main(int argc, char** argv) {

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
