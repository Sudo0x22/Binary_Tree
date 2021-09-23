#include<iostream>
#include<set>

using namespace std;

struct Node {
  int data;
  Node *left, *right;
};

Node* newNode(int key) {
  Node* node = new Node;
  node->data = key;
  node->left = node->right = nullptr;

  return node;
}

void in_order(Node* root) {
  if (root == nullptr) {
    return;
  }

  in_order(root->left);
  cout << root->data << " ";
  in_order(root->right);
}

void keys(Node* root, auto &set) {
  if (root == nullptr) {
    return;
  }

  keys(root->left, set);
  set.insert(root->data);
  keys(root->right, set);
}

void convert(Node* root, auto &it) {
  if (root == nullptr) {
    return;
  }

  convert(root->left, it);
  root->data = *it;
  it++;

  convert(root->right, it);
}

int main()
{
  Node* root = newNode(1);
  root->left = newNode(5);
  root->right = newNode(10);
  root->left->left = newNode(9);
  root->left->right = newNode(3);
  root->right->left = newNode(6);
  root->right->right = newNode(8);

  set<int> set;
  keys(root, set);

  auto it = set.begin();
  convert(root, it);

  in_order(root);

  return 0;
}
