#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // default constructor
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
        // then this is the root node
        root = new Node(data);
        return root;
    }

    // agar root nahi hai to dekhenge ki ye node left me jaayega ya right
    if (data > root->data)
    {
        // then we will go into the right subtree for insertion
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        // if(newNode->data< root->data)
        // then we will go into left subtree for the insertion of this newNode
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void createBST(Node *&root)
{
    int data;
    cout << "Enter the Value for the Node : ";
    cin >> data;

    while (data != -1)
    {
        // we will call the insertintoBST function
        insertIntoBST(root, data);
        // we will take the input again
        cout << "Enter Data : ";
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
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
            cout << frontNode->data << " ";
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

void preOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << "->";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
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

void postOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << "->";
}

int minValue(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    // we are going till the end of the left subtree
    while (root->left != NULL)
    {
        root = root->left;
    }
    // now we are going to print the leftest Node
    return root->data;
}
Node* maxValue(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    // we are going till the end of the left subtree
    while (root->right != NULL)
    {
        root = root->right;
    }
    // now we are going to print the leftest Node
    return root;
}

Node* searchValue(Node *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (target > root->data)
    {
        // then we need to find it in right subtree
        return searchValue(root->right, target);
    }
    else if (target < root->data)
    {
        // then we need to find it in left subtree
        return searchValue(root->left, target);
    }
    else
    {
        // the target was found
        return root;
    }


}

Node *deleteNodefromBST(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    // 2 cases possible
    // 1-> if the key ,matches the root->data
    if (root->data == key)
    {
        // 4 cases possible
        if (root->left != NULL && root->right == NULL)
        {
            // 1-> only left child exists
            // in this case, we need to just delete this root Node and point the address of left with the root's left
            Node*temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            // 2-> only right child exists
            Node*temp = root->right;
            delete root;
            return temp;
        }
        else if (root->left != NULL && root->right != NULL)
        {
            // 3-> both child exists
            // we need to get the maximum from the left subtree or minimum from right subtree;
            Node*maxNode = maxValue(root->left);
            // then we need to exchange the data of that very node with the root Node's data
            root->data = maxNode->data;
            // then we need to find that node in this root-> left or right and delete it from there
            root->left = deleteNodefromBST(root->left,maxNode->data);
            // and finally return root
            return root;



        }
        else
        {
            // 4-> this is the left node , no child exists
            delete root;
            return nullptr;
        }
    }
    else
    {
        // 2-> if the key, doesnot match with the root->data
        if(key > root->data){
            root->right = deleteNodefromBST(root->right,key);
        }
        else{
            root->left = deleteNodefromBST(root->left,key);
        }
        return root;
    }
}

int main()
{
    Node *rootNode = NULL;
    createBST(rootNode);
    // Printing the tree
    levelOrderTraversal(rootNode);

    cout << "inOrderTraversal : ";
    inOrderTraversal(rootNode);
    cout << endl;

    cout << "preOrderTraversal : ";
    preOrderTraversal(rootNode);
    cout << endl;

    cout << "postOrderTraversal : ";
    postOrderTraversal(rootNode);

    // int min = minValue(rootNode);
    // cout << endl
    //      << "Minimum from the BST is : " << min << endl;

    // maxValue(rootNode);
    // int target;
    // cout << "Enter Target: ";
    // cin >> target;
    // bool ans = searchValue(rootNode, target);
    // if (ans)
    // {
    //     cout << "the Target Element was found" << endl;
    // }
    // else
    // {
    //     cout << "The target element was not found" << endl;
    // }
    // return 0;
    int key;
    cout << "Enter key";
    cin >> key;
    deleteNodefromBST(rootNode,key);
    levelOrderTraversal(rootNode);
}

// BST ka inorder always sorted
