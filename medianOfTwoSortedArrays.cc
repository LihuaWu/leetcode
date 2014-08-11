#include <gtest/gtest.h>
#include <algorithm>

using namespace std;

int findKthElemOfTwoSortedArray(int*A, int m, int* B, int n, int k);

double medianOfTwoSortedArray(int* A, int m, int* B, int n){
	int total = m + n;
	if(total & 0x1){
		return findKthElemOfTwoSortedArray(A, m, B, n, total/2 + 1);
	} else {
		return (findKthElemOfTwoSortedArray(A, m, B, n, total/2)
			+ findKthElemOfTwoSortedArray(A, m, B, n, total/2 + 1))/2.0;
	}
}

int findKthElemOfTwoSortedArray(int*A, int m, int* B, int n, int k){
	if (m > n) return findKthElemOfTwoSortedArray(B, n, A, m, k);
	if (m == 0) return B[k - 1];
	if (k == 1) return min(A[0], B[0]);
	
	int ia = min(k/2, m);
	int ib = k - ia;
	if (A[ia - 1] < B[ib - 1]){
		return findKthElemOfTwoSortedArray(A + ia, m - ia, B, n, k - ia);
	} else if (A[ia - 1] > B[ib - 1]){
		return findKthElemOfTwoSortedArray(A, m, B + ib, n - ib, k - ib);
	} else {
		return A[ia - 1];
	}
}

TEST (medianOfTwoSortedArray, OddElemsCase){
	int A[] = {1, 2, 3};
	int B[] = {4, 5, 6, 7};
	int lenA = sizeof(A)/sizeof(int);
	int lenB = sizeof(B)/sizeof(int);
	double ret = medianOfTwoSortedArray(A, lenA, B, lenB);
	EXPECT_DOUBLE_EQ(4.0, ret);
}

TEST (medianOfTwoSortedArray, EvenElemsCase){
	int A[] = {1, 2, 3, 5};
	int B[] = {4, 5, 6, 7};
	int lenA = sizeof(A)/sizeof(int);
	int lenB = sizeof(B)/sizeof(int);
	double ret = medianOfTwoSortedArray(A, lenA, B, lenB);
	EXPECT_DOUBLE_EQ(4.5, ret);
}

TEST (medianOfTwoSortedArray, WithOnlyTwoElem){
	int A[] = {1};
	int B[] = {4};
	int lenA = sizeof(A)/sizeof(int);
	int lenB = sizeof(B)/sizeof(int);
	double ret = medianOfTwoSortedArray(A, lenA, B, lenB);
	EXPECT_DOUBLE_EQ(2.5, ret);
}


int main(int argc, char** argv) {

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
