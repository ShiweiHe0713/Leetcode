#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        // if (head == nullptr || head->next == nullptr) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // divide two lists
        ListNode* secondHead = slow->next;
        slow->next = NULL; 
        
        mergeLists(head, reverseList(secondHead));
    }
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;

        while(cur != NULL) { // make sure the last node is also reversed
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }

        return prev;
    }

    void mergeLists(ListNode* cur1, ListNode* cur2) {
        while(cur1 != NULL && cur2 != NULL) {
            ListNode* tmp1 = cur1->next;
            ListNode* tmp2 = cur2->next;
            
            cur1->next = cur2;
            if(tmp1 == NULL) {
                break;
            }
            cur2->next = tmp1;

            cur1 = tmp1;
            cur2 = tmp2;
        }
    }
};

int main() {
    Solution solution;
    int a = 3;
    int b = 5;
    ListNode* head = new ListNode(3);
    ListNode* node1 = new ListNode(4);
    head->next = node1;
    solution.reorderList(head);
    cout << "it's " << head->val << endl;
    return 0;
}