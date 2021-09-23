#include<bits/stdc++.h>
#include<set>

using namespace std;

struct Node {
    int data;
    struct Node* Left;
    struct Node* Right;
};

struct Node* node(int data) {
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->Left = NULL;
    newNode->Right = NULL;

    return newNode;
}

void get_tree(Node* root) {
    if (root == nullptr) {
        return;
    }

    get_tree(root->Left);
    cout << root->data << " ";
    get_tree(root->Right);
}

void tree(Node* root, auto &set) {
    if (root == nullptr) {
        return;
    }

    tree(root->Left, set);
    set.insert(root->data);
    tree(root->Right, set);
}

void read_tree(Node* root, auto &it) {
    if (root == nullptr) {
        return;
    }

    read_tree(root->Left, it);
    root->data = *it;
    it++;

    read_tree(root->Right, it);
}

int main()
{
    Node* root = node(1);
    root->Left = node(5);
    root->Right = node(7);
    root->Left->Left = node(4);
    root->Left->Right = node(10);
    root->Right->Left = node(11);
    root->Right->Right = node(6);

    set<int> set;
    tree(root, set);

    auto it = set.begin();
    read_tree(root, it);

    get_tree(root);
}