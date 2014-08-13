#include <cstddef>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;	
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* vector2List(const vector<int>& A); 
void list2vector(ListNode* l, vector<int>& v);
ListNode* add(ListNode* lhs, ListNode* rhs);
ListNode* partialReverseList(ListNode* head); 
