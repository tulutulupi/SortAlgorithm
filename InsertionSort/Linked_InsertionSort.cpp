#include <iostream>

//使用链表存储数组，然后对链表进行插入排序，对每个元素进行重新插入，将原来的结点
//取出，然后重新在sorted的链中寻找插入位置，移动元素的时间为O(1)，但是比较的时间还是O(n)
//并且对n个结点进行操作，最终的时间复杂度为O(n^2)

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

void insertSorted(Node*& head, int value) {
    Node* newNode = new Node(value);
    //当sort链为空或者新的结点小于头的值时的操作
    if (!head || value < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }
    //如果新的结点大于头，则寻找对应要插入的位置
    Node* current = head;
    while (current->next && current->next->data < value) {
        current = current->next;
    }
    //将新节点插入
    newNode->next = current->next;
    current->next = newNode;
}

void insertionSort(Node*& head) {
    //设置另一个链，来将原来链表中的结点重新插入到这个链里
    Node* sorted = nullptr;
    Node* current = head;

    while (current) {
        Node* next = current->next;
        //插入函数，在这里自动将新插入的链插入到合适位置。
        insertSorted(sorted, current->data);
        current = next;
    }

    head = sorted;
}

void displayList(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // 添加节点到链表
    Node* head = new Node(-1);  // 头节点
    Node* node1 = new Node(1);
    Node* node2 = new Node(5);
    Node* node3 = new Node(3);
    Node* node4 = new Node(2);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    
    std::cout << "原始链表: ";
    displayList(head);

    insertionSort(head);

    std::cout << "排序后链表: ";
    displayList(head);

    return 0;
}
