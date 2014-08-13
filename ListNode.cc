#include "ListNode.h"

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

ListNode* partialReverseList(ListNode(* head) {
}
