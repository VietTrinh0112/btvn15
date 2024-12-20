#include <iostream>
#include <cstring>

using namespace std;

struct Node {
    char title[100];
    int page_number;
    char node_type[20];
    Node** children;
    int num_children;

    Node(const char* t, int p, const char* type) {
        strcpy(title, t);
        page_number = p;
        strcpy(node_type, type);
        children = nullptr;
        num_children = 0;
    }
};

void add_child(Node* parent, Node* child) {
    if (!parent) return;

    Node** new_children = new Node*[parent->num_children + 1];
    for (int i = 0; i < parent->num_children; i++) {
        new_children[i] = parent->children[i];
    }
    new_children[parent->num_children] = child;

    delete[] parent->children;
    parent->children = new_children;
    parent->num_children++;
}

int count_chapters(Node* node) {
    if (!node) return 0;

    int count = 0;
    if (strcmp(node->node_type, "chapter") == 0) {
        count++;
    }

    for (int i = 0; i < node->num_children; i++) {
        count += count_chapters(node->children[i]);
    }
    return count;
}

int get_total_pages(Node* node) {
    if (!node) return 0;

    int total_pages = node->page_number;
    for (int i = 0; i < node->num_children; i++) {
        total_pages += get_total_pages(node->children[i]);
    }
    return total_pages;
}

Node* find_longest_chapter(Node* node, int& max_pages) {
    if (!node) return nullptr;

    Node* longest = nullptr;

    if (strcmp(node->node_type, "chapter") == 0) {
        int total_pages = get_total_pages(node);
        if (total_pages > max_pages) {
            max_pages = total_pages;
            longest = node;
        }
    }

    for (int i = 0; i < node->num_children; i++) {
        Node* candidate = find_longest_chapter(node->children[i], max_pages);
        if (candidate) {
            longest = candidate;
        }
    }
    return longest;
}

Node* remove_node(Node* node, const char* title) {
    if (!node) return nullptr;

    if (strcmp(node->title, title) == 0) {
        for (int i = 0; i < node->num_children; i++) {
            delete node->children[i];
        }
        delete[] node->children;
        delete node;
        return nullptr;
    }

    for (int i = 0; i < node->num_children; i++) {
        node->children[i] = remove_node(node->children[i], title);
    }
    return node;
}

void print_remaining_pages(Node* node) {
    if (!node) return;

    if (strcmp(node->node_type, "chapter") == 0) {
        cout << "Chuong: " << node->title << ", Tong so trang: " << get_total_pages(node) << endl;
    }

    for (int i = 0; i < node->num_children; i++) {
        print_remaining_pages(node->children[i]);
    }
}

void free_tree(Node* node) {
    if (!node) return;

    for (int i = 0; i < node->num_children; i++) {
        free_tree(node->children[i]);
    }
    delete[] node->children;
    delete node;
}

int main() {
    Node* book = new Node("Book", 1, "book");

    Node* chapter1 = new Node("Chapter 1", 1, "chapter");
    add_child(book, chapter1);

    Node* section1 = new Node("Section 1.1", 5, "section");
    add_child(chapter1, section1);

    Node* subsection1 = new Node("Subsection 1.1.1", 10, "subsection");
    add_child(section1, subsection1);

    Node* chapter2 = new Node("Chapter 2", 20, "chapter");
    add_child(book, chapter2);

    Node* section2 = new Node("Section 2.1", 25, "section");
    add_child(chapter2, section2);

    cout << "So chuong trong sach: " << count_chapters(book) << endl;

    int max_pages = -1;
    Node* longest_chapter = find_longest_chapter(book, max_pages);
    if (longest_chapter) {
        cout << "Chuong dai nhat: " << longest_chapter->title
             << ", voi tong so trang: " << max_pages << endl;
    }

    cout << "Delete Section 1.1...\n";
    book = remove_node(book, "Section 1.1");

    cout << "So trang cac chuong con lai:\n";
    print_remaining_pages(book);

    free_tree(book);

    return 0;
}
