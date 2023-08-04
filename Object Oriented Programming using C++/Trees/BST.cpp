#include <iostream>
#include <conio.h>
#include <queue>

using namespace std;

struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
    treeNode(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

//Print Post Order BT
void printPostOrder(struct treeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    printPostOrder(node->left);

    printPostOrder(node->right);

    cout << node->data << " ";
}

//Print In Order BT
void printInOrder(struct treeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    printInOrder(node->left);

    cout << node->data << " ";

    printInOrder(node->right);
}

//Print Pre Order BT
void printPreOrder(struct treeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    cout << node->data << " ";

    printPreOrder(node->left);

    printPreOrder(node->right);
}

//Print Level Order BT
void printLevelOrder(struct treeNode *node)
{
    if (node == NULL)
        return;

    queue<treeNode *> q;

    q.push(node);

    while (q.empty() != true)
    {
        struct treeNode *temp = q.front();
        cout << temp->data << " ";

        q.pop();

        if (temp->left != NULL)
        {
            q.push(temp->left);
        }

        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}

//Insertion Level Order BT
void insert(struct treeNode *node, int key)
{
    queue<struct treeNode *> q;
    q.push(node);

    while (!q.empty())
    {
        struct treeNode *temp = q.front();
        q.pop();

        if (temp->left == NULL)
        {
            temp->left = new treeNode(key);
            break;
        }
        else
        {
            q.push(temp->left);
        }

        if (temp->right == NULL)
        {
            temp->right = new treeNode(key);
            break;
        }
        else
        {
            q.push(temp->right);
        }
    }
}

//Delete Deepest Node Right
void deleteDeepest(struct treeNode *node, struct treeNode *endNode)
{
    queue<struct treeNode *> q;
    q.push(node);

    struct treeNode *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->right)
        {
            if (temp->right == endNode)
            {
                temp->right = NULL;
                delete (endNode);
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }

        if (temp->left)
        {
            if (temp->left == endNode)
            {
                temp->left = NULL;
                delete (endNode);
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }
    }
}

//Deletion and Updation of Tree
void deleteKey(struct treeNode *node, int key)
{
    /*if (node == NULL)
    {
        cout << "Tree is empty!";
        return;
    }*/

    queue<struct treeNode *> q;
    q.push(node);

    struct treeNode *temp;
    struct treeNode *keyNode = NULL;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->data == key)
        {
            keyNode = temp;
        }

        if (temp->left)
        {
            q.push(temp->left);
        }

        if (temp->right)
        {
            q.push(temp->right);
        }
    }

    int x = temp->data;
    deleteDeepest(node, temp);
    keyNode->data = x;
}

int main()
{
    struct treeNode *root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);
    root->left->left = new treeNode(4);
    root->left->right = new treeNode(5);

    //cout << "Preorder traversal of binary tree is: \n";
    //printPreOrder(root);

    cout << "\n\nInorder traversal of binary tree is: \n";
    printInOrder(root);

    insert(root, 10);

    cout << "\n\nInorder traversal of binary tree after Insertion is: \n";
    printInOrder(root);

    deleteKey(root, 2);

    cout << "\n\nInorder traversal of binary tree after Deletion is: \n";
    printInOrder(root);

    deleteKey(root, 3);

    cout << "\n\nInorder traversal of binary tree after Deletion is: \n";
    printInOrder(root);

    deleteKey(root, 5);

    cout << "\n\nInorder traversal of binary tree after Deletion is: \n";
    printInOrder(root);

    //cout << "\n\nPostorder traversal of binary tree is: \n";
    //printPostOrder(root);

    //cout << "\n\nLevelorder traversal of binary tree is: \n";
    //printLevelOrder(root);

    getch();
    return 0;
}
