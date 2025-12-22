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
        insertIntoBST(root, data);
        // again taking input and feeding it to  the BST
        cout << "Enter Data : ";
        cin >> data;
    }
}

void levelOrderTraversal(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        if (frontNode == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // frontNode!=NULL
            cout << frontNode->data << "->";
            if (frontNode->left != NULL)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right != NULL)
            {
                q.push(frontNode->right);
            }
        }
    }
}

void inOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << "->";
    inOrderTraversal(root->right);
}

Node *minValue(Node *&root)
{
    if (root == NULL)
    {
        return NULL;
    }

    // we will go to the far left end, and when we reach there , we are gonna return it
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *maxValue(Node *&root)
{
    if (root == NULL)
    {
        return NULL;
    }

    // we will go to the far left end, and when we reach there , we are gonna return it
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

// bool searchNodes(Node*&root,int target){
//     if(root==NULL){
//         return false;
//     }

//     if(root->data == target){
//         return true;
//     }
//     searchNodes(root->left,target);
//     searchNodes(root->right,target);
// }

bool searchInBST(Node *root, int target)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == target)
    {
        return true;
    }

    // bool leftAns = false;
    // bool rightAns = false;

    if(target > root->data ){
        // since the target is greater than the root, we need to go to the right
        return searchInBST(root->right,target);
    }

    else if(target < root->data ){
        // since the target is greater than the root, we need to go to the right
        return searchInBST(root->left,target);
    }

    // return leftAns || rightAns;
}
int main()
{

    Node *rootNode = NULL;
    createBST(rootNode);
    // BST has been successfully created

    cout << "LevelOrderTraversal: " << endl;
    levelOrderTraversal(rootNode);

    cout << "InorderTraversal: ";
    inOrderTraversal(rootNode);
    cout << endl;

    Node *minNode = minValue(rootNode);
    if (minNode == NULL)
    {
        cout << "There is no Node in the Tree, Empty " << endl;
    }
    else
    {
        cout << "minimum value is : " << minNode->data << endl;
    }

    Node *maxNode = maxValue(rootNode);
    if (maxNode == NULL)
    {
        cout << "There is no Node in the Tree, Empty " << endl;
    }
    else
    {
        cout << "maximum value is : " << maxNode->data << endl;
    }

    int target;
    cout << "Enter the element you want to Search : ";
    cin >> target;
    bool ans = false;
    ans = searchInBST(rootNode, target);
    if (ans)
    {
        cout << "the Nodes was present";
    }
    else
    {
        cout << "The Nodes was not found in the list";
    }
    return 0;
}

// 50 20 70 8 19 1 69 -1