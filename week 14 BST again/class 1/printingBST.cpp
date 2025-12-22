#include <iostream>
using namespace std;
#include <queue>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // ctor
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data < root->data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void createBST(Node *&root)
{
    int data;
    cout << "Enter data:";
    cin >> data;

    while (data != -1)
    {
        insertIntoBST(root,data);
        // again taking input and feeding it to  the BST
        cout << "Enter Data : ";
        cin >> data;
    }
}

void levelOrderTraversal(Node*&root){
    if(root==NULL){
        return;
    }

    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node*frontNode = q.front();
        q.pop();
        
        if(frontNode==NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            // frontNode!=NULL
            cout << frontNode->data << "->";
            if(frontNode->left!=NULL){
                q.push(frontNode->left);
            }
            if(frontNode->right!=NULL){
                q.push(frontNode->right);
            }
        }
    }

}

void preOrderTraversal(Node*&root){
    if(root==NULL){
        return;
    }

    cout << root->data << "->";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    
}
void inOrderTraversal(Node*&root){
    if(root==NULL){
        return;
    }
    
    // agar root Null nahi hai to hmlog LRN lagayenge
    inOrderTraversal(root->left);
    cout << root->data << "->";
    inOrderTraversal(root->right);

}


void postOrderTraversal(Node*&root){
    if(root==NULL){
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << "->";
}

int main(){

    Node*rootNode = NULL;
    createBST(rootNode);
    // BST has been successfully created

    cout << "LevelOrderTraversal: "<< endl;
    levelOrderTraversal(rootNode);


    cout << "InorderTraversal: ";
    inOrderTraversal(rootNode);
    cout << endl;
    
    cout << "preOrderTraversal: ";
    preOrderTraversal(rootNode);
    cout << endl;


    cout << "postOrderTraversal: ";
    postOrderTraversal(rootNode);
    cout << endl;

    return 0;
}

// 50 20 70 8 19 1 69 -1