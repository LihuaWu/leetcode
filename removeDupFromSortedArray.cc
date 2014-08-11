#include <iostream>
#include <algorithm>
#include <iterator>
#include <assert.h>

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

void testRemoveDupFromSortedArray(int* A, int len){
	copy(A, A+len, ostream_iterator<int>(cout, " "));
	cout<<endl;

	len = removeDupFromSortedArray(A, len);

	copy(A, A+len, ostream_iterator<int>(cout, " "));
	cout<<endl;
}

int main() {
	int A[] = {1,2,3,4,5,6,7,7};
	int len = sizeof(A)/sizeof(int);
	testRemoveDupFromSortedArray(A, len);

	int B[] = {1,2,3,4,5,6,7};
	len = sizeof(B)/sizeof(int);
	testRemoveDupFromSortedArray(B, len);

	int C[] = {1,1,1,1,1,1};
	len = sizeof(C)/sizeof(int);
	testRemoveDupFromSortedArray(C, len);

	int D[] = {};
	len = sizeof(D)/sizeof(int);
	testRemoveDupFromSortedArray(D, len);

	int E[] = {};
	len = -1;
	int result = removeDupFromSortedArray(E, len);
	cout<<result<<endl;

	return 0;
}
