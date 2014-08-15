#include <iostream>

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

ListNode* partialReverseList(ListNode* head, int m, int n) {
	ListNode dummy(0);
	dummy.next = head;
	ListNode* prev = &dummy;
	for (int i = 0; i < m - 1; ++i){
		prev = prev->next;
	}
	ListNode* const start = prev;
	prev = start->next;
	ListNode* cur = prev->next;
	for(int i = m; i < n; ++i) {
		prev->next = cur->next;
		cur->next = start->next;
		start->next = cur;
		cur = prev->next;
	}
	return dummy.next;
}

ListNode* listPartition(ListNode* head, int val) {
	ListNode dummy(0);
	ListNode dummy2(0);

	ListNode* lhs = &dummy;
	ListNode* rhs = &dummy2;

	for(ListNode* cur = head; cur; cur = cur->next) {
		if(cur->val < val) {
			lhs->next = cur;
			lhs = cur;
		}else {
			rhs->next = cur;
			rhs = cur;
		}
	}
	lhs->next = dummy2.next;
	rhs->next = NULL;
	return dummy.next;
}

ListNode* listRemoveDuplicates(ListNode* head){
	if(head == NULL) return head;
	for(ListNode* prev = head, *cur = prev->next;
			cur; cur = cur->next) {
		if(prev->val == cur->val) {
			prev->next = cur->next;
			delete cur;
		}else {
			prev = cur;
		}
	}
	return head;
}


ListNode* listRemoveDuplicates2(ListNode* head){
	if (head == NULL) return head;
	ListNode dummy(head->val + 1);
	dummy.next = head;

	ListNode* prev = &dummy, *cur = head;
	while(cur != NULL) {
		bool dup = false;
		while(cur->next != NULL && cur->val == cur->next->val) {
			dup = true;
			ListNode* to_delete = cur;
			cur = cur->next;
			delete to_delete;
		}
		if(dup) {
			ListNode* to_delete = cur;
			cur = cur->next;
			delete to_delete;
		} else {
			prev->next = cur;
			prev = cur;
			cur = cur->next;
		}
	}
	prev->next = cur;
	return dummy.next;
}

int listLen(ListNode* head) {
	int ret = 0;
	for(ListNode* cur = head; cur; cur=cur->next) {
		++ret;
	}
	return ret;
}

ListNode* listRotate(ListNode* head, int k){
	if(head == NULL) return head;
	int n = listLen(head);
	k %= n;
	if(k == 0) return head;

	ListNode* newHead = head;
	ListNode* prev = head;
	for(int i = 0; i < n - k; ++i) {
		prev = newHead;
		newHead = newHead->next;
	}
	prev->next = NULL;
	ListNode* cur = newHead;
	while(cur->next) {
		cur = cur->next;
	}
	cur->next = head;
	return newHead;
}

ListNode* removeNthNodeFromEnd(ListNode* head, int k) {
	ListNode dummy(0);
	dummy.next = head;
	ListNode *p = &dummy, *q = &dummy;

	for(int i = 0; i < k; ++i) { q = q->next; }
	for(; q->next; q= q->next, p = p->next);

	ListNode* tmp = p->next;
	p->next = tmp->next;
	delete tmp;
	return dummy.next;
}

ListNode* nodeSwap(ListNode* head) {
	if (head == NULL || head->next == NULL) return head;
	ListNode dummy(0);
	dummy.next = head;

	for(ListNode *prev = &dummy, *cur = prev->next, *next = cur->next;
			next;
			prev = cur, cur = cur->next, next = cur ? cur->next : NULL) {
		prev->next = next;
		cur->next = next->next;
		next->next = cur;
	}
	return dummy.next;
}

ListNode* reverseNodesInKGroup(ListNode* head, int k) {
	if(head == NULL || head->next == NULL || k < 2) {
		return head;
	}

	ListNode* next_group = head;
	for(int i = 0; i < k; ++i) {
		if(next_group) {
			next_group = next_group->next;
		}
		else {
			return head;	
		}
	}

	ListNode* new_next_group = reverseNodesInKGroup(next_group, k);

	ListNode* prev = NULL, *cur = head;

	while (cur != next_group) {
		ListNode* next = cur->next;
		cur->next = prev ? prev: new_next_group;
		prev = cur;
		cur = next;
	}
	return prev;

}

ListNode* reverseNodesInKGroup2(ListNode* head, int k) {
	ListNode dummy(0);
	dummy.next = head;
	for(ListNode* prev = &dummy, *end = head;
			end;
			end = prev->next){
		for(int i = 0; i < k - 1 && end; ++i) {
			end = end->next;
		}
		if(end == NULL) {
			break;
		}else {
			prev = reverse(prev, prev->next, end);
		}
	}
	return dummy.next;
}

ListNode* reverse(ListNode* prev, ListNode* begin, ListNode* end) {
	ListNode* end_next = end->next;
	for(ListNode* p = begin, *cur = p->next, *next = cur->next;
			cur != end_next;
			p = cur, cur = next, next = next ? next->next : NULL) {
		cur->next = p;
	}
	begin->next = end_next;
	prev->next = end;
	return begin;
}


ListNode* copyRandomList(ListNode* head) {
	if(head == NULL) return head;
	for(ListNode* cur = head; cur; ) {
		ListNode* next = cur->next;
		cur->next = new ListNode(cur->val);
		cur->next->next = next;
		cur = cur->next->next;
	}

	for(ListNode* cur = head; cur; cur = cur->next->next) {
		if(cur->random != NULL) {
			cur->next->random = cur->random->next;
		}
	}

	ListNode dummy(0);
	for(ListNode *new_cur = &dummy, *cur = head; cur; ) {
		new_cur->next = cur->next;
		new_cur = new_cur->next;
		cur = cur->next->next;
	}
	return dummy.next;
}


