#include <iostream>
using namespace std;
#include <queue>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

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

    // in else case we will insert it recursively
    if (data < root->data)
    {
        // inserting in the left subtree
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        // inserting in the right subtree
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

void createBST(Node *&root)
{
    int data;
    cout << "Enter Data: ";
    cin >> data;
    while (data != -1)
    {
        insertIntoBST(root, data);
        cout << "Enter the Data: ";
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
    q.push(nullptr);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        if (frontNode == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
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
Node *findMaxfromLeftSubtree(Node *&root)
{

    if (root == NULL)
    {
        return NULL;
    }
    Node *temp = root;
    // jab tk rightest node pe nahi chale jaayenge tab tk hm while loop run krenge
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *deleteNodefromBST(Node *&root, int target)
{
    // target ko dhundo
    // fir target ko delete krdo

    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == target)
    {
        // ab delete karenge
        if (root->left == NULL && root->right == NULL)
        {
            // leaf Node
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node *childSubtree = root->left;
            delete root;
            return childSubtree;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            //
            Node *childSubtree = root->right;
            delete root;
            return childSubtree;
        }
        else
        {
            // case where both child Nodes are non NULL
            // leftSubtree ki max value leke aao
            Node *maxNode = findMaxfromLeftSubtree(root->left);
            // creating link of right node of the root to the new max
            root->data = maxNode->data;
            // delete root;
            // delete the actual max wali Node
            root->left = deleteNodefromBST(root->left, maxNode->data);
            return root;
        }
    }
    else if (root->data > target)
    {
        // go to left
        root->left = deleteNodefromBST(root->left, target);
    }
    else
    {
        // go to right
        root->right = deleteNodefromBST(root->right, target);
    }
}

int main()
{
    Node *rootNode = NULL;
    createBST(rootNode);

    cout << "Printing LevelOrder Traversal: " << endl;
    levelOrderTraversal(rootNode);
    int xyz;
    cout << "Enter target: ";
    cin >> xyz;
    deleteNodefromBST(rootNode, xyz);
    cout << "Printing LevelOrder Traversal: " << endl;
    levelOrderTraversal(rootNode);
    return 0;
}

// 50 30 20 40 51 59 70 18 20 -1