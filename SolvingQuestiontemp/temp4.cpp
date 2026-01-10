#include <iostream>
#include <queue>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    //  ctor
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *createTree()
{
    int data;
    cout << "Enter the Data for the root: ";
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }

    Node *root = new Node(data);
    cout << "for the left of Node:  " << root->data << ", Enter Data: ";
    root->left = createTree();
    cout << "for the right of Node:  " << root->data << ", Enter Data: ";
    root->right = createTree();

    return root;
}

void levelOrderTraversal(Node*root){
    if(root==NULL){
        return;
    }

    queue<Node*>q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        Node*frontNode = q.front();
        q.pop();

        if(frontNode==NULL){
            cout << endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            cout << frontNode->data << " ";
            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
    }
}


void printLeftBoundary(Node*root){
    // MO -> leaf node ko print nahi krenge, saare left values printKrenge
    // also agar left kisi node ka exist nahi krta hai to hi uska right print krenge 
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }
    
    cout << root->data << " ";
    
    // after printing the rooNode,we will see if left exists or not
    // if exists then we wil go recursively that side or if not then we go to right
    if(root->left){
        printLeftBoundary(root->left);
    }
    else{
        printLeftBoundary(root->right);
    }
}
void printLeafNodes(Node*root){
    if(root==NULL){
        return;
    }
    if(!root->left && !root->right){
        cout << root->data << " ";
    }
    // we are going till the end of any root and then print if it is a leaf Node
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}


void printRight(Node*root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }
    cout << root->data << " ";
    if(root->right){
        printRight(root->right);
    }
    else{
        return;
    }

}
int main()
{
    Node*rootNode = createTree();
    levelOrderTraversal(rootNode);

    // Printing the left Boundary
    cout << "Boundary Traversal of the TREE: ";
    printLeftBoundary(rootNode);
    // after this we are going to print all the leaf nodes of this tree
    printLeafNodes(rootNode);
    printRight(rootNode->right);
    cout << endl;
    return 0;
}