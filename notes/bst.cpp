#include<iostream>
#include<stack>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *CreateNode(int val)
{
    node *temp = new node();
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

node *InsertNode(node *root, int val)
{
    if(root == NULL)
    {
        return CreateNode(val);
    }
    if(val < root->data)
    {
        root->left = InsertNode(root->left, val);
    }
    if(val > root->data)
    {
        root->right = InsertNode(root->right, val);
    }
    return root;
}

node *search(node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    else if (data < root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

void Inorder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data <<" ";
    Inorder(root->right);
}

void Preorder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->data <<" ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data <<" ";
}

void NonRecursiveInOrder(node *root)
{
    stack<node*> s;
    node *curr = root;

    while(curr != NULL || !s.empty())
    {
        while(curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
            curr = s.top();
            s.pop();
            cout << curr->data <<" ";
            curr = curr->right;
    }
}

void NonRecursivePreOrder(node *root)
{
    stack <node*> s;
    node *curr = root;

    if(!root)
    {
        return;
    }

    s.push(root);
    while(!s.empty())
    {
        curr = s.top();
        s.pop();
        cout << curr->data <<" ";

        if(curr->right != NULL)
        {
            s.push(curr->right);
        }
        if(curr->left != NULL)
        {
            s.push(curr->left);
        }
    }
    return;
}

void NonRecursivePostOrder(node *root)
{
    if(!root)
    {
        return;
    }
    stack<node*> s1, s2;
    node *curr = root;

    s1.push(curr);
    while(!s1.empty())
    {
        curr = s1.top();
        s1.pop();
        s2.push(curr);

        if(curr->left != NULL)
        {
            s1.push(curr->left);
        }
        if(curr->right != NULL)
        {
            s1.push(curr->right);
        }
    }
        while(!s2.empty())
        {
            root = s2.top();
            s2.pop();
            cout << root->data <<" ";
        }
}

int height(node *root)
{
    if (!root)
    {
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    return 1 + max(lheight, rheight);
}

void printLevel(node *root, int levelNo)
{
    if (!root)
    {
        return;
    }
    if (levelNo == 0)
    {
        cout << root->data << " ";
    }
    else
    {
        printLevel(root->left, levelNo - 1);
        printLevel(root->right, levelNo - 1);
    }
}

void LevelWisePrinting(node *root)
{
    if (!root)
    {
        cout << "Tree is empty!" << endl;
        return;
    }
    int ht = height(root);
    for (int i = 0; i < ht; i++)
    {
        printLevel(root, i);
        cout << endl;  
    }
}

node *getSuccessor(node *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}


node *DeleteNode(node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data > key)
    {
        root->left = DeleteNode(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = DeleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        node *succ = getSuccessor(root);
        root->data = succ->data;
        root->right = DeleteNode(root->right, succ->data);
    }
    return root;
}


int main()
{
    node *root = NULL;
    node *result = NULL;

    int choice, num, element;
    char ch;

    do
    {
        cout << endl;
        cout <<"1.Insertion"<< endl;
        cout <<"2.Searching"<< endl;
        cout <<"3.Recursive Inorder"<< endl;
        cout <<"4.Recursive Preorder"<< endl;
        cout <<"5.Recursive Postorder"<< endl;
        cout <<"6.Non Recursive Inorder"<< endl;
        cout <<"7.Non Recursive Preorder"<< endl;
        cout <<"8.Non Recursive Postorder"<< endl;
        cout <<"9.Level Wise Printing"<< endl;
        cout <<"10.Deletion"<< endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            cout <<"Enter the number you want to insert - ";
            cin >> num;
            for(int i = 0; i < num; i++)
            root = InsertNode(root, num);
            break;

            case 2:
            cout << "Enter element to search: ";
            cin >> element;
            result = search(root, element);
            if (result != NULL)
            {
                cout << "Element Found!" << endl;
            }
            else
            {
                cout << "Element Not Found!" << endl;
            }
            break;

            case 3:
            cout <<"Inorder is - ";
            Inorder(root);
            break;

            case 4:
            cout <<"Preorder is - ";
            Preorder(root);
            break;

            case 5:
            cout <<"Postorder is - ";
            Postorder(root);
            break;

            case 6:
            cout <<"Inorder is - ";
            NonRecursiveInOrder(root);
            break;

            case 7:
            cout <<"Preorder is - ";
            NonRecursivePreOrder(root);
            break;

            case 8:
            cout <<"Postorder is - ";
            NonRecursivePostOrder(root);
            break;

            case 9:
            cout <<"Level Wise Printing : ";
            LevelWisePrinting(root);
            break;

            case 10:
            cout << "Enter element to delete: ";
            cin >> element;
            root = DeleteNode(root, element);
            cout << "Deleted" << endl;
            break;

            default:
            cout <<"Wrong choice";
            break;

            cout <<"Do you want to continue ? ";
            cin >> ch;
        }
    }
    while(ch != 'N' || ch != 'n');
}