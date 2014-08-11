#include <gtest/gtest.h>

int removeElem(int* arr, int n, int key) {
	if (arr == NULL || n < 0) return -1;
	int tail = 0;
	for(int i = 0; i < n; ++i) {
		if(arr[i] != key) {
			arr[tail++] = key;
		}
	}
	return tail;
}

TEST (removeElem, NormalCase) {
	int A[] = {1, 2, 3, 4, 4, 3, 3};
	int key = 3;
	int ret = removeElem(A, sizeof(A)/sizeof(int), key);
	EXPECT_EQ(4, ret);
}

int main(int argc, char** argv){
	
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

