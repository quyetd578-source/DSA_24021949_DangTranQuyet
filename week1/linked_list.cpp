#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
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

void displayReverse(Node *head) {
    if (head == nullptr)
        return;

    displayReverse(head->next);
    cout << head->data << " ";
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
    head = p;
}

void insertTail(Node *&head, int x) {
    Node *p = new Node(x);

    if (head == nullptr) {
        head = p;
        return;
    }

    Node *q = head;

    while (q->next != nullptr)
        q = q->next;

    q->next = p;
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
    q->next = p;
}

void deleteHead(Node *&head) {
    if (head == nullptr) {
        cout << "Danh sach rong!\n";
        return;
    }

    Node *p = head;
    head = head->next;
    delete p;
}

void deleteTail(Node *&head) {
    if (head == nullptr) {
        cout << "Danh sach rong!\n";
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node *q = head;

    while (q->next->next != nullptr)
        q = q->next;

    delete q->next;
    q->next = nullptr;
}

void deleteAt(Node *&head, int i) {
    if (i < 0 || head == nullptr) {
        cout << "Vi tri khong hop le!\n";
        return;
    }

    if (i == 0) {
        deleteHead(head);
        return;
    }

    Node *q = head;

    for (int j = 0; j < i - 1 && q != nullptr; j++)
        q = q->next;

    if (q == nullptr || q->next == nullptr) {
        cout << "Vi tri khong hop le!\n";
        return;
    }

    Node *p = q->next;
    q->next = p->next;
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
    cout << '\n';

    clearList(head);
    return 0;
}
