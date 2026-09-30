#include <iostream>
using namespace std;

const int MAX = 100;

struct List {
    int data[MAX];
    int n = 0;
};

void display(const List &L) {
    for (int i = 0; i < L.n; i++)
        cout << L.data[i] << " ";
    cout << '\n';
}

void displayReverse(const List &L) {
    for (int i = L.n - 1; i >= 0; i--)
        cout << L.data[i] << " ";
    cout << '\n';
}

void accessElement(const List &L, int i) {
    if (i < 0 || i >= L.n)
        cout << "Vi tri khong hop le!\n";
    else
        cout << "Phan tu tai vi tri " << i
             << " = " << L.data[i] << '\n';
}

void insertHead(List &L, int x) {
    if (L.n == MAX) {
        cout << "Danh sach day!\n";
        return;
    }

    for (int i = L.n; i > 0; i--)
        L.data[i] = L.data[i - 1];

    L.data[0] = x;
    L.n++;
}

void insertTail(List &L, int x) {
    if (L.n == MAX) {
        cout << "Danh sach day!\n";
        return;
    }

    L.data[L.n++] = x;
}

void insertAt(List &L, int i, int x) {
    if (i < 0 || i > L.n || L.n == MAX) {
        cout << "Vi tri khong hop le!\n";
        return;
    }

    for (int j = L.n; j > i; j--)
        L.data[j] = L.data[j - 1];

    L.data[i] = x;
    L.n++;
}

void deleteHead(List &L) {
    if (L.n == 0) {
        cout << "Danh sach rong!\n";
        return;
    }

    for (int i = 0; i < L.n - 1; i++)
        L.data[i] = L.data[i + 1];

    L.n--;
}

void deleteTail(List &L) {
    if (L.n == 0) {
        cout << "Danh sach rong!\n";
        return;
    }

    L.n--;
}

void deleteAt(List &L, int i) {
    if (i < 0 || i >= L.n) {
        cout << "Vi tri khong hop le!\n";
        return;
    }

    for (int j = i; j < L.n - 1; j++)
        L.data[j] = L.data[j + 1];

    L.n--;
}

int main() {
    List L;

    insertTail(L, 10);
    insertTail(L, 20);
    insertTail(L, 30);

    cout << "Danh sach ban dau: ";
    display(L);

    insertHead(L, 5);
    cout << "Chen dau: ";
    display(L);

    insertTail(L, 40);
    cout << "Chen cuoi: ";
    display(L);

    insertAt(L, 2, 15);
    cout << "Chen vi tri 2: ";
    display(L);

    accessElement(L, 2);

    deleteHead(L);
    cout << "Xoa dau: ";
    display(L);

    deleteTail(L);
    cout << "Xoa cuoi: ";
    display(L);

    deleteAt(L, 1);
    cout << "Xoa vi tri 1: ";
    display(L);

    cout << "Duyet xuoi: ";
    display(L);

    cout << "Duyet nguoc: ";
    displayReverse(L);

    return 0;
}
//Độ phức tạp thuật toán
//Truy cập phần tử: O(1)
// Chèn đầu: O(n)
// Chèn cuối: O(1)
// Chèn vị trí i: O(n)
// Xóa đầu: O(n)
// Xóa cuối: O(1)
// Xóa vị trí i: O(n)
// Duyệt xuôi: O(n)
// Duyệt ngược: O(n)
