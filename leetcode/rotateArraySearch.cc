#include <gtest/gtest.h>

int searchRotateArray(int* A, int n, int key){
	int first = 0;
	int last = n;
	int mid;
	while(first < last){
		mid = first + (last - first) / 2;
		if(A[mid] == key) return mid;
		if(A[first] < A[mid]){
			if(A[first] <= key && key < A[mid]){
				last = mid;
			}else {
				first = mid + 1;
			}
		}else if (A[first] > A[mid]){
			if(A[mid] < key && key <= A[last - 1]){
				first = mid + 1;
			}else {
				last = mid;
			}
		}else {
			++first;
		}
	}
	return -1;
}

TEST (searchRotateArray, keyInArr){
	int A[] = {4, 5, 6, 7, 1, 2, 3};
	int ret = searchRotateArray(A, sizeof(A)/sizeof(int), 7);
	EXPECT_EQ (A[ret], 7);
	EXPECT_EQ (ret, 3);
}

TEST (searchRotateArray, withDupElemInArr){
	int A[] = {4, 5, 6, 7, 7, 1, 2, 3};
	int ret = searchRotateArray(A, sizeof(A)/sizeof(int), 7);
	EXPECT_EQ (A[ret], 7);
	//not always true
	//EXPECT_EQ(3, ret);
	int B[] = {1, 3, 1, 1, 1};
	ret = searchRotateArray(B, sizeof(B)/sizeof(int), 1);
	EXPECT_EQ(B[ret], 1);
	EXPECT_EQ(2, ret);
}

TEST (searchRotateArray, KeyNotInArr){
	int A[] = {4, 4, 4, 4, 4};
	int ret = searchRotateArray(A, sizeof(A)/sizeof(int), 7);
	EXPECT_EQ (ret, -1);
}

TEST (searchRotateArray, KeyInMid){
	int A[] = {4, 5, 6, 7, 7, 8, 1, 2, 3};
	int ret = searchRotateArray(A, sizeof(A)/sizeof(int), 7);
	EXPECT_EQ (A[ret], 7);
}

int main(int argc, char** argv){
	
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
