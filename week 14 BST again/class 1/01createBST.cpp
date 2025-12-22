#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // constructor
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

    // leking agar root null nahi hai to left me attach kro
    if (data < root->data)
    {
        // recursive call for left subtree
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        // data > root->data , insert into leftSubtree
        root->right = insertIntoBST(root->right, data);
    }
    // jab left aur right create ho jayega to return ho jayenge
    cout << root->data;
    return root;
}

void levelOrderTraversal(Node *&root)
{
    queue<Node*>q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        //we will pick up to front node
        Node* frontNode = q.front();
        // then will pop it
        q.pop();
        if(frontNode==NULL){
            // we will print the endline character
            cout << endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            // frontNode is not NUll
            // print the frontNode and the push the left and right elements
            cout << frontNode->data << " ";
            if(frontNode->left!=NULL){
                q.push(frontNode->left);
            }
            if(frontNode->right!=NULL){
                q.push(frontNode->right);
            }
        }
    }
}

void createBST(Node *&root)
{
    int data;
    cout << "Enter data:";
    cin >> data;

    while (data != -1)
    {
        insertIntoBST(root, data);
        cout << "Enter Data: ";
        cin >> data;
    }
}

int main()
{
    Node *rootNode = NULL;
    createBST(rootNode);

    cout << "Level Order Traversal : ";
    levelOrderTraversal(rootNode);
    return 0;
}