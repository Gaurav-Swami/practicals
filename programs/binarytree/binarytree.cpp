#include <iostream>
using namespace std;

// Node structure for the BST
struct Node 
{
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) 
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node into the BST
Node* insertNode(Node* root, int data) {
    if (root == nullptr) 
    {
        root = createNode(data);
    } 
    else if (data < root->data) 
    {
        root->left = insertNode(root->left, data);
    } 
    else if (data > root->data) 
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to perform in-order traversal
void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

// Function to perform pre-order traversal
void preOrderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform post-order traversal
void postOrderTraversal(Node* root) {
    if (root != nullptr) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }
}

// Function to create a BST
Node* createBST() {
    Node* root = nullptr;
    int data;
    while (true) {
        cout << "Enter elements to create the BST (enter -1 to stop): ";
        cin >> data;  // Capture input
        if (data == -1) break;  // Exit condition
        root = insertNode(root, data);  // Insert the input into the BST
    }
    return root;
}

int main() {
    Node* root = createBST();  // Create the BST
    cout << "In-order traversal: ";
    inOrderTraversal(root);  // Display in-order traversal
    cout << endl;
    cout << "Pre-order traversal: ";
    preOrderTraversal(root);  // Display pre-order traversal
    cout << endl;
    cout << "Post-order traversal: ";
    postOrderTraversal(root);  // Display post-order traversal
    cout << endl;
    return 0;
}
