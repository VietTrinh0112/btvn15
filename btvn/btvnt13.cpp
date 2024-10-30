#include <iostream>

using namespace std;

struct Node {
    int ID;
    int Giasanpham;
    int Soluongsanpham;
    char Tensanpham[50];
    Node* next;

    void Saochepchuoi(const char* src) {
        int i = 0;
        while (src[i] != '\0') {
            Tensanpham[i] = src[i];
            i++;
        }
        Tensanpham[i] = '\0';
    }

    bool Sosanhchuoi(const char* str1) {
        int i = 0;
        while (str1[i] != '\0' && Tensanpham[i] != '\0') {
            if (str1[i] != Tensanpham[i]) {
                return false;
            }
            i++;
        }
        return (str1[i] == '\0' && Tensanpham[i] == '\0');
    }
};

struct Queue {
    Node* front;
    Node* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int ID, int Giasanpham, int Soluongsanpham, const char* Tensanpham) {
        Node* newNode = new Node();
        newNode->ID = ID;
        newNode->Giasanpham = Giasanpham;
        newNode->Soluongsanpham = Soluongsanpham;
        newNode->Saochepchuoi(Tensanpham);
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Hang doi rong!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Da thanh toan gio hang co ID " << temp->ID << ", gia tien " << temp->Giasanpham << endl;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    int CalTongsotien() {
        int total = 0;
        Node* temp = front;
        while (temp != nullptr) {
            total += temp->Giasanpham;
            temp = temp->next;
        }
        return total;
    }

    int CountspA(const char* Tensanpham) {
        int count = 0;
        Node* temp = front;
        while (temp != nullptr) {
            if (temp->Sosanhchuoi(Tensanpham)) {
                count += temp->Soluongsanpham;
            }
            temp = temp->next;
        }
        return count;
    }

    ~Queue() {
        while (front != nullptr) {
            dequeue();
        }
    }
};

int main() {
    Queue q;

    q.enqueue(1, 500, 3, "A");
    q.enqueue(2, 300, 2, "B");
    q.enqueue(3, 200, 1, "A");

    cout << "Tong so tien thu duoc: " << q.CalTongsotien() << endl;
    cout << "So luong san pham A da ban: " << q.CountspA("A") << endl;

    return 0;
}

