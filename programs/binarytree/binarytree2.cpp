#include <iostream>
#include <conio.h>
using namespace std;

class Node
{

public:
  int data;
  Node *left;
  Node *right;
  Node(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

class BST
{

public:
  Node *root;
  BST()
  {
    root = NULL;
  }

  Node *insertNode(Node *root, int data)
  {
    if (root == nullptr)
    {
      return new Node(data);
    }
    if (data < root->data)
    {
      root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
      root->right = insertNode(root->right, data);
    }
    return root;
  }

  void createBST()
  {
    while (1)
    {
      int data;
      cout << "Enter a value for the node or (-1) to exit : ";
      cin >> data;
      if (data == -1)
      {
        break;
      }

      root = insertNode(root, data);
    }
  }

  void inOrder(Node *node)
  {
    if (node != nullptr)
    {
      inOrder(node->left);
      cout << node->data << " ";
      inOrder(node->right);
    }
  }
};

int main()
{
  BST b;
  while (1)
  {
    int choice;
    cout << "\n___________________________________________________________________\n";
    cout << "0. Exit\n";
    cout << "1. Create Binary Search Tree\n";
    cout << "2. Display Tree\n";
    cout << "Enter your choice : ";
    cin >> choice;
    switch (choice)
    {
    case 0:
      return 0;
    case 1:
      b.createBST();
      break;
    case 2:
      cout << "\n";
      cout << "Binary Tree : ";
      b.inOrder(b.root);
      break;
    default:
      cout << "Invalid choice, Please try agains";
      break;
    }
  }
  getch();
  return 0;
}