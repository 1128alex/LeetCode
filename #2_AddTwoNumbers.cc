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
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int temp = 0;
        int newVal = l1->val + l2->val;
        temp = newVal / 10;
        newVal = newVal % 10;
        ListNode *result = new ListNode(newVal);
        ListNode *tempNode = new ListNode();
        tempNode = result;
        l1 = l1->next;
        l2 = l2->next;
        while (true)
        {
            if (l1 != NULL && l2 != NULL)
            {
                newVal = l1->val + l2->val + temp;
                // cout << "l1 & l2: " << newVal <<endl;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1 != NULL && l2 == NULL)
            {
                newVal = l1->val + temp;
                // cout << "l1: " << newVal <<endl;
                l1 = l1->next;
            }
            else if (l1 == NULL && l2 != NULL)
            {
                // cout << "l2: " << newVal << endl;
                newVal = l2->val + temp;
                l2 = l2->next;
            }
            else
            {
                if (temp == 0)
                {
                    // cout << "0" <<endl;
                    break;
                }
                else
                {
                    ListNode *nextNode = new ListNode(temp);
                    tempNode->next = nextNode;
                    break;
                }
            }
            temp = newVal / 10;
            newVal = newVal % 10;
            cout << "newVal: " << newVal << endl;
            cout << "temp: " << temp << endl;
            ListNode *nextNode = new ListNode(newVal);
            tempNode->next = nextNode;
            tempNode = nextNode;
        }
        // cout << "[";
        // tempNode = result;
        // while (tempNode->next != NULL) {
        //     cout << tempNode->val << ",";
        //     tempNode = tempNode->next;
        // }
        // cout << tempNode->val << "]";
        return result;
    }
};