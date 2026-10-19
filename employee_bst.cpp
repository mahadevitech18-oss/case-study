#include <iostream>
using namespace std;

struct Node {
    int id;
    Node *left, *right;
    Node(int x) { id = x; left = right = NULL; }
};

Node* insert(Node* root, int id) {
    if(root == NULL) return new Node(id);
    if(id < root->id) root->left = insert(root->left, id);
    else root->right = insert(root->right, id);
    return root;
}

void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->id << " ";
    inorder(root->right);
}

bool search(Node* root, int id) {
    if(root == NULL) return false;
    if(root->id == id) return true;
    if(id < root->id) return search(root->left, id);
    return search(root->right, id);
}

int main() {
    Node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7;
    cout << "Inserting: 50 30 70 20 40 60 80\n";
    for(int i=0;i<n;i++) root = insert(root, arr[i]);
    
    cout << "\nInorder (Sorted IDs): ";
    inorder(root);
    cout << "\nBST Structure:\n      50\n    /    \\\n  30      70\n /  \\    /  \\\n20  40  60  80\n";
    
    int key = 60;
    cout << "\nSearch " << key << ": " << (search(root,key)?"Found":"Not Found") << endl;
    return 0;
}
