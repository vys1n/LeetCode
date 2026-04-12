#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        ListNode* curr = head;
        int curr_max = head->val;

        while (curr && curr->next) {
            if (curr->next->val < curr_max) {
                curr->next = curr->next->next;
            } else {
                curr_max = curr->next->val;
                curr = curr->next;
            }
        }
        
        return reverse(head);
    }
};
    
/* ListNode* monotonicStack(ListNode* head) {
    vector<int> st;
    ListNode* curr = head;

    while (curr) {
        while (!st.empty() && curr->val > st.back()) { st.pop_back(); };
        st.push_back(curr->val);
        curr = curr->next;
    }

    ListNode* dummy = new ListNode();
    curr = dummy;

    for (int num : st) {
        curr->next = new ListNode(num);
        curr = curr->next;
    }

    return dummy->next;
} */
    
/* ListNode* recursion(ListNode* head) {
    if (!head) return nullptr;
    head->next = removeNodes(head->next);
    if (head->next && head->val < head->next->val) { return head->next; }
    return head;
} */
