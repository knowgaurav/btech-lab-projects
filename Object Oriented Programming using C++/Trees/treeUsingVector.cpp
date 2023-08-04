#include <iostream>
#include <vector>
#include <conio.h>
#include <queue>

using namespace std;

template <typename T>
class treeNode
{
public:
    T data;
    vector<treeNode<T> *> children;

    treeNode(T data = 0)
    {
        this->data = data;
    }
};

treeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data: " << endl;
    cin >> rootData;

    treeNode<int> *root = new treeNode<int>(rootData);

    int n;
    cout << "Enter number of children: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        treeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

treeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data: " << endl;
    cin >> rootData;

    treeNode<int> *root = new treeNode<int>(rootData);
    queue<treeNode<int> *> pendingNodes;

    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        treeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the number of children of " << front->data;
        int numChild;
        cin >> numChild;

        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of " << front->data;
            cin >> childData;
            treeNode<int> *child = new treeNode<int>(childData);
            pendingNodes.push(child);
        }
    }
    return root;
}

void displayNode(treeNode<int> *root1)
{
    if (root1 == NULL)
    {
        cout << "Tree is empty!" << endl;
        return;
    }
    cout << root1->data << ": " << endl;

    for (int i = 0; i < root1->children.size(); i++)
    {
        cout << root1->children[i]->data << ",";
    }
    cout << endl;

    for (int i = 0; i < root1->children.size(); i++)
    {
        displayNode(root1->children[i]);
    }
}

int main()
{
    treeNode<int> *head = takeInputLevelWise();
    displayNode(head);

    getch();
    return 0;
}