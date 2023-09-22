#include <iostream>

using namespace std;

// 链表节点的定义
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 计算链表的长度
int getLength(ListNode* head) {
    int length = 0;
    ListNode* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

// 找到两个链表的第一个交点
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);
    
    // 让较长链表的指针先移动到与较短链表相同长度的位置
    ListNode* currentA = headA;
    ListNode* currentB = headB;
    if (lenA > lenB) {
        for (int i = 0; i < lenA - lenB; i++) {
            currentA = currentA->next;
        }
    } else {
        for (int i = 0; i < lenB - lenA; i++) {
            currentB = currentB->next;
        }
    }
    
    // 同时遍历两个链表，找到第一个相同的节点
    while (currentA != nullptr && currentB != nullptr) {
        if (currentA == currentB) {
            return currentA;
        }
        if (currentA->val > currentB->val)
        {
            currentB = currentB->next;
        }
        else
        {
            currentA = currentA->next;
        }
        
        
    }
    
    return nullptr; // 没有交点
}

int main() {
    // 创建两个链表
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    ListNode* node6 = new ListNode(6);
    node6->next = node3; // 设置交点

    // 调用函数找到交点
    ListNode* intersectionNode = getIntersectionNode(node1, node6);

    if (intersectionNode != nullptr) {
        cout << "第一个交点的值为: " << intersectionNode->val << endl;
    } else {
        cout << "没有交点" << endl;
    }

    return 0;
}
