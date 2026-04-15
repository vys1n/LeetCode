struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* recursiveSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* left = head;
        ListNode* right = getMid(head);
        ListNode* temp = right->next;

        right->next = nullptr;
        right = temp;

        left = recursiveSortList(left);
        right = recursiveSortList(right);

        return merge(left, right);
    }
    
    ListNode* iterativeSortList(ListNode* head) {
        if (!head || !head->next) return head;

        int len = 0;
        ListNode* curr = head;
        while (curr) {
            len++;
            curr = curr->next;
        }

        ListNode* dummy = new ListNode(0, head);
        int step = 1;
        while (step < len) {
            ListNode* prev = dummy;
            curr = dummy->next;
            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, step);
                curr = split(right, step);

                ListNode* merged = merge(left, right);
                prev->next = merged;

                while (prev->next) {
                    prev = prev->next;
                }
            }

            step *= 2;
        }

        return dummy->next;
    }

private:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        tail->next = list1 ? list1 : list2;
        return dummy->next;
    }

    ListNode* split(ListNode* head, int step) {
        if (!head) return nullptr;

        for (int i=0; i<step-1 && head->next; i++) {
            head = head->next;
        }

        ListNode* nextPart = head->next;
        head->next = nullptr;

        return nextPart;
    }

    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
