/*
    Test Driven Development (TDD) is a way of writing production code where
    test code for testing the production code is written in advance.

    Steps:

    Step 1 - Write enough failing test code (include compile and run time failures)
    Step 2 -  Write production code to pass above failing test case
    Step 3 -  Re-factor production code and verify the same with existing test
    Step 4 -  Go to step - 1.

    Code below demonstrates TDD.
    Problem statement : Create a binary search tree (BST) using TDD.
*/

#include <iostream>
using namespace std;
using std::cout;

// Step -2 Define struct Btree and maketree() to pass tests in step -1
struct Btree
{
    int val;
    Btree * left, * right;
    // Step 3: Refactor code
    Btree (int value) : val(value), left(nullptr), right(nullptr) {}
};

Btree* maketree(int value)
{
    return new Btree (value);
    // below code commented after refactoring production code
    // Btree * bst = new Btree;
    // bst->val = value;
    // bst->left = bst->right = nullptr;
    // return bst;
}

// In response to test step 2, define InserNode
void InsertNode(Btree *bst, int value)
{
    if (value < 0)
    {
        cout << "Value less than zero!" << endl;
        return;
    }
    
    while(1)
    {
        // value goes to right
        if (value > bst->val)
        {
            if(bst->right == nullptr)
            {
                bst->right = maketree(value);
                break;
            }
            else
            {
                bst = bst->right;
                continue;
            }
        }

        // value goes to left
        else if (value < bst->val)
        {
            if(bst->left == nullptr)
            {
                bst->left = maketree(value);
                break;
            }
            else
            {
                bst = bst->left;
                continue;
            }
        }
        else
        {
            cout << "Value already exists!" << endl;
            break;
        }
    }
}

// In response to step 3, define PrintBst
void PrintBst (Btree *bst)
{
    if (bst->left != nullptr)
        PrintBst(bst->left);
    cout << "Node Value - " << bst->val << endl;
    if (bst->right != nullptr)
        PrintBst(bst->right);
}

int main()
{
    // Test step 1 (Check if BST is being created)
    Btree * bst = maketree(8);
    if (bst == nullptr)
    {
        cout << "BST creation failed!" << endl; // run time failure
    }
    else
    {
        cout << "BST creation successful" << endl;
    }
    
    // Test step : 2
    InsertNode(bst, 1);
    InsertNode(bst, 3);
    InsertNode(bst, 4);
    InsertNode(bst, 6);
    InsertNode(bst, 7);
    InsertNode(bst, 10);
    InsertNode(bst, 13);
    InsertNode(bst, 14);

    // Test step : 3
    PrintBst(bst);

    // Test step : 4 (Negatives aren't allowed)
    InsertNode(bst, -1);
    cout << " ----------- Print Again ----------- " << endl;
    PrintBst(bst);

    return 0;
}