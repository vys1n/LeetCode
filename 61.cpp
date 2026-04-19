struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;

        ListNode* curr = head;
        int n = 1;
        while (curr->next) {
            curr = curr->next;
            n++;
        }

        curr->next = head;
        k %= n;
        for (int i=0 ; i<n-k; i++) { curr = curr->next; }

        head = curr->next;
        curr->next = nullptr;

        return head;
    }
};
