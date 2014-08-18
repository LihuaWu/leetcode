#include <cstddef>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;	
	ListNode* random;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* vector2List(const vector<int>& A); 
void list2vector(ListNode* l, vector<int>& v);
ListNode* add(ListNode* lhs, ListNode* rhs);
ListNode* partialReverseList(ListNode* head, int , int); 
ListNode* listPartition(ListNode*, int);
ListNode* listRemoveDuplicates(ListNode* head);
ListNode* listRemoveDuplicates2(ListNode* head);
ListNode* listRotate(ListNode* head, int k);
ListNode* removeNthNodeFromEnd(ListNode* head, int k);
ListNode* nodeSwap(ListNode* head);
ListNode* reverseNodesInKGroup(ListNode* head, int k);
ListNode* reverse(ListNode* prev, ListNode* begin, ListNode* end); 
ListNode* reverseNodesInKGroup2(ListNode* head, int k); 
ListNode* copyRandomList(ListNode* head);
bool hasCycle(ListNode* head); 
ListNode* cycleBegin(ListNode* head);
ListNode* listReorder(ListNode* head);
ListNode* reverseList(ListNode* head);
