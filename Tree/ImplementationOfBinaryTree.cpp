#include <iostream>
#include <queue>

using namespace std;

class Node {
    public:
        int data;
        Node* left, * right;
        Node(int key) {
            data = key;
            left = nullptr;
            right = nullptr;
        }
};

Node* insert (Node* root, int key) {
    // If the tree is empty, create the root node
    if (root == nullptr) {
        root = new Node(key);
        return root;
    }

    // Create a queue for level order traversal
    queue<Node*> q;
    q.push(root);

    // Do level order traversal until we find an empty place
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();


        // If left child is empty, insert the new node here
        if (temp->left == nullptr) {
            temp->left = new Node(key);
            break;
        } else {
            q.push(temp->left);
        }

        // If right child is empty, insert the new node here
        if (temp->right == nullptr) {
            temp -> right = new Node(key);
            break;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

void inorder (Node* root) {
    if(root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Function to search for a value in the binary tree using DFS (Preorder)
bool searchDFS (Node* root, int value) {
    // Base case: If the tree is empty or we've reached a leaf node
    if (root == nullptr) {
        return false;
    }

    //If the node's data is equal to the value we are searching for 
    if (root->data == value) {
        return true;
    }

    // Recursively search in the left and right subtrees
    bool left_res = searchDFS(root->left, value);
    bool right_res = searchDFS(root->right, value);

    return left_res || right_res;
}

int main () {
    Node* root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(4) ; 
    root->left->left = new Node(5);
  
    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;

    int key = 6;
    root = insert(root, key);

    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;

    int value = 6;
    if (searchDFS(root, value))
        cout << value << " is found in the binary tree" << endl;
    else
        cout << value << " is not found in the binary tree" << endl;
        
    return 0;
}