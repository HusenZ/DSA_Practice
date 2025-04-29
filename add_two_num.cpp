/*
💡 QUESTION: Add Two Numbers (Linked List Based)

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

📌 You may assume the two numbers do not contain any leading zero,
    except the number 0 itself.

-------------------------------
🔸 Example 1:
Input:  l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807

🔸 Example 2:
Input:  l1 = [0], l2 = [0]
Output: [0]

🔸 Example 3:
Input:  l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

---------------------------------
🧠 Approach (in simple terms):

1. Traverse both lists node by node.
2. At each step, add the digits + any carry.
3. Store the last digit of the sum in a new node.
4. Carry the rest to the next addition.
5. Continue until both lists and carry are done.

---------------------------------
⏱️ Time Complexity: O(max(N, M))
📦 Space Complexity: O(max(N, M)) — for the result list
---------------------------------
*/

// ✅ DEFINITION for singly-linked list:
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ✅ SOLUTION:
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy node simplifies code for returning result
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        int carry = 0;

        // Traverse both lists
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            int digit = sum % 10;

            current->next = new ListNode(digit);
            current = current->next;
        }

        return dummy->next;
    }
};
