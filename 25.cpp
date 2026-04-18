struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* grpPrev = dummy;

        while (true) {
            ListNode* kth = getKthNode(grpPrev, k);
            if (!kth) break;

            ListNode* grpNext = kth->next;
            ListNode* prev = grpNext;
            ListNode* curr = grpPrev->next;

            while (curr != grpNext) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            ListNode* tmp = grpPrev->next;
            grpPrev->next = kth;
            grpPrev = tmp;
        }
        
        return dummy->next;
    }
private:
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr && k>0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};
