#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;

    Node(int x) {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};

void display(Node *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << '\n';
}

Node* getTail(Node *head) {
    while (head != nullptr && head->next != nullptr)
        head = head->next;

    return head;
}

void displayReverse(Node *head) {
    Node *tail = getTail(head);

    while (tail != nullptr) {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << '\n';
}

void accessElement(Node *head, int i) {
    if (i < 0) {
        cout << "Vi tri khong hop le!\n";
        return;
    }

    int pos = 0;

    while (head != nullptr) {
        if (pos == i) {
            cout << "Phan tu tai vi tri " << i
                 << " = " << head->data << '\n';
            return;
        }

        head = head->next;
        pos++;
    }

    cout << "Vi tri khong hop le!\n";
}

void insertHead(Node *&head, int x) {
    Node *p = new Node(x);

    p->next = head;

    if (head != nullptr)
        head->prev = p;

    head = p;
}

void insertTail(Node *&head, int x) {
    Node *p = new Node(x);

    if (head == nullptr) {
        head = p;
        return;
    }

    Node *q = getTail(head);
    q->next = p;
    p->prev = q;
}

void insertAt(Node *&head, int i, int x) {
    if (i < 0) {
        cout << "Vi tri khong hop le!\n";
        return;
    }

    if (i == 0) {
        insertHead(head, x);
        return;
    }

    Node *q = head;

    for (int j = 0; j < i - 1 && q != nullptr; j++)
        q = q->next;

    if (q == nullptr) {
        cout << "Vi tri khong hop le!\n";
        return;
    }

    Node *p = new Node(x);

    p->next = q->next;
    p->prev = q;

    if (q->next != nullptr)
        q->next->prev = p;

    q->next = p;
}

void deleteHead(Node *&head) {
    if (head == nullptr) {
        cout << "Danh sach rong!\n";
        return;
    }

    Node *p = head;
    head = head->next;

    if (head != nullptr)
        head->prev = nullptr;

    delete p;
}

void deleteTail(Node *&head) {
    if (head == nullptr) {
        cout << "Danh sach rong!\n";
        return;
    }

    Node *tail = getTail(head);

    if (tail->prev != nullptr)
        tail->prev->next = nullptr;
    else
        head = nullptr;

    delete tail;
}

void deleteAt(Node *&head, int i) {
    if (i < 0 || head == nullptr) {
        cout << "Vi tri khong hop le!\n";
        return;
    }

    Node *p = head;

    for (int j = 0; j < i && p != nullptr; j++)
        p = p->next;

    if (p == nullptr) {
        cout << "Vi tri khong hop le!\n";
        return;
    }

    if (p->prev != nullptr)
        p->prev->next = p->next;
    else
        head = p->next;

    if (p->next != nullptr)
        p->next->prev = p->prev;

    delete p;
}

void clearList(Node *&head) {
    while (head != nullptr) {
        Node *p = head;
        head = head->next;
        delete p;
    }
}

int main() {
    Node *head = nullptr;

    insertTail(head, 10);
    insertTail(head, 20);
    insertTail(head, 30);

    cout << "Danh sach ban dau: ";
    display(head);

    insertHead(head, 5);
    cout << "Chen dau: ";
    display(head);

    insertTail(head, 40);
    cout << "Chen cuoi: ";
    display(head);

    insertAt(head, 2, 15);
    cout << "Chen vi tri 2: ";
    display(head);

    accessElement(head, 2);

    deleteHead(head);
    cout << "Xoa dau: ";
    display(head);

    deleteTail(head);
    cout << "Xoa cuoi: ";
    display(head);

    deleteAt(head, 1);
    cout << "Xoa vi tri 1: ";
    display(head);

    cout << "Duyet xuoi: ";
    display(head);

    cout << "Duyet nguoc: ";
    displayReverse(head);

    clearList(head);
    return 0;
}

//Độ phức tạp thuật toán
//Truy cập phần tử: O(n)
// Chèn đầu: O(1)
// Chèn cuối: O(n)
// Chèn vị trí i: O(n)
// Xóa đầu: O(1)
// Xóa cuối: O(n)
// Xóa vị trí i: O(n)
// Duyệt xuôi: O(n)
// Duyệt ngược: O(n)



