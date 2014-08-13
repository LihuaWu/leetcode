#include <vector>

#include <gtest/gtest.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;	
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* 
add(ListNode* lhs, ListNode* rhs) {
	ListNode dummy(0);
	ListNode* prev = &dummy;
	int carry = 0;
	for(ListNode* l = lhs, *r = rhs;
			l != NULL || r != NULL;
			l = (l == NULL) ? NULL : l->next, 
			r = (r == NULL) ? NULL : r->next,
			prev = prev->next){
		const int a = (l == NULL) ? 0 : l->val;
		const int b = (r == NULL) ? 0 : r->val;

		prev->next = new ListNode((a + b + carry) % 10);
		carry = (a + b) / 10;
	}
	if(carry > 0){
		prev->next = new ListNode(carry);
	}
	return dummy.next;
}

ListNode* vector2List(const vector<int>& A) {
	int n = A.size();
	ListNode dummy(0);
	ListNode* prev = &dummy;
	for(int i = 0; i < n; ++i, prev = prev->next) {
		prev->next = new ListNode(A[i]);
	}
	return dummy.next;
}

void list2vector(ListNode* l, vector<int>& v){
	while(l != NULL) {
		v.push_back(l->val);
		l = l->next;
	}
}

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
