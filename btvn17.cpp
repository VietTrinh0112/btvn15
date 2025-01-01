#include <iostream>
#define MAX 100

using namespace std;

class GraphMatrix {
private:
    int vertices;
    int Matran[MAX][MAX];

public:
    GraphMatrix(int v) {
        vertices = v;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                Matran[i][j] = 0;
            }
        }
    }

    void addMatran(int start, int end) {
        Matran[start][end] = 1;
    }

    void Matranbieudien() {
        cout << "Ma tran lan can:\n";
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << Matran[i][j] << " ";
            }
            cout << endl;
        }
    }
};

struct Node {
    int vertex;
    Node* next;
};

class GraphList {
private:
    int vertices;
    Node* adjList[MAX];

public:
    GraphList(int v) {
        vertices = v;
        for (int i = 0; i < vertices; i++) {
            adjList[i] = nullptr;
        }
    }

    Node* createNode(int vertex) {
        Node* newNode = new Node;
        newNode->vertex = vertex;
        newNode->next = nullptr;
        return newNode;
    }

    void addList(int start, int end) {
        Node* newNode = createNode(end);
        newNode->next = adjList[start];
        adjList[start] = newNode;
    }

    void Danhsachbieudien() {
        cout << "Danh sach lan can:\n";
        for (int i = 0; i < vertices; i++) {
            cout << i << ": ";
            Node* temp = adjList[i];
            while (temp != nullptr) {
                cout << temp->vertex << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    int vertices = 7;

    GraphMatrix graphMatrix(vertices);

    graphMatrix.addMatran(0, 1);
    graphMatrix.addMatran(0, 2);
    graphMatrix.addMatran(0, 3);
    graphMatrix.addMatran(1, 4);
    graphMatrix.addMatran(2, 4);
    graphMatrix.addMatran(3, 5);
    graphMatrix.addMatran(4, 6);
    graphMatrix.addMatran(5, 6);

    graphMatrix.Matranbieudien();

    GraphList graphList(vertices);

    graphList.addList(0, 1);
    graphList.addList(0, 2);
    graphList.addList(0, 3);
    graphList.addList(1, 4);
    graphList.addList(2, 4);
    graphList.addList(3, 5);
    graphList.addList(4, 6);
    graphList.addList(5, 6);

    graphList.Danhsachbieudien();

    return 0;
}
