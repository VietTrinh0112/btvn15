#include<iostream>
using namespace std;
struct Node
{
    float he_so; // Khởi tạo hệ số
    int bac; // Khởi tạo bậc
    Node *link;
};

struct ListDT
{
    Node *first, *last;
};

void InitDT(ListDT *l) 
{
    l->first = l->last = NULL; // Khởi tạo danh sách rỗng
}

Node *CallNode(float hs, int sm) 
{
    Node *p;
    p = new Node;
    if(p == NULL) return NULL; // Kiểm tra xem bộ nhớ đã được cấp phát thành công chưa
    p->he_so = hs;
    p->bac = sm;
    p->link = NULL;
    return p;
}

void addNode(ListDT* listDT, Node *a)
{
    if(listDT->first == NULL) // Danh sách rỗng
    {
        listDT->first = listDT->last = a;
    }
    else
    {
        listDT->last->link = a; // Gán địa chỉ nút cuối bằng p
        listDT->last = a; // Chuyển p thành nút cuối
    }
}

void attachNode(ListDT *listDT, float hs, int sm) // Thêm phần tử cho list
{
    Node *pDT = CallNode(hs, sm);
    if(pDT == NULL) return;
    addNode(listDT, pDT);
}

void taoDT(ListDT *listDT) {
    float hs;
    int sm;
    int i = 0; // Counter for elements
    cout << "Bat dau nhap da thuc (Nhap he so 0 de ket thuc): " << endl;
    do {
        i++;
        cout << "Nhap so phan tu thu " << i << endl;
        cout << "Nhap he so = ";
        cin >> hs;
        if (hs == 0) break; // Exit if coefficient is zero
        cout << "Nhap so mu = ";
        cin >> sm;
        attachNode(listDT, hs, sm);
    } while (true);  // Infinite loop, broken by 'break' when hs == 0
    cout << "Ket thuc nhap" << endl;
}

void inDT(ListDT listDT)
{
    Node *a;
    a = listDT.first;
    cout << "\nf(x) = ";
    while (a != NULL)
    {
        cout << a->he_so << " * x^" << a->bac;
        if(a->link != NULL && a->he_so != 0) cout << " + ";
        a = a->link;
    }
}

int main() {
    ListDT DT;
    InitDT(&DT);
    taoDT(&DT);
    inDT(DT);
}