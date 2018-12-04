#ifndef __BST__
#define __BST__

class BST;

class Node
{
private:
    double value;
    Node*  left;
    Node*  right;
public:
    Node(double v, Node* l = NULL, Node* r = NULL)
    {
        value = v;
        left = l;
        right = r;
    }
    double GetValue() const
    {
        return value;
    }
    friend class BST;
};

class BST
{
private:
    Node* root;
public:
    BST(Node* r = NULL)
    {
        root = r;
    }
    bool IsEmpty() const
    {
        return (root == NULL);
    }
    string ToString() const
    {
        if (IsEmpty()) return "()";
        string str = ToString(root);
        if (root->left == NULL && root->right == NULL) str = "(" + str + ")";
        return str;
    }

    void Clear();
    Node* Search(double query);
    void Insert(double value);
    void Inorder(void (*visit)(const Node*));
    void Preorder(void (*visit)(const Node*));
    void Postorder(void (*visit)(const Node*));

    ///////////////////////////////////////////
    // Do not change the above prototype.
    // Add member function(s) below if you need.

    // Do not change the below.
    ///////////////////////////////////////////
private:
    string ToString(Node* n) const
    {
        if (n == NULL) return "_";
        stringstream ss;
        if (n->left == NULL && n->right == NULL) ss << n->value;
        else                                     ss << "(" << ToString(n->left) << "," << n->value << "," << ToString(n->right) << ")";
        return ss.str();
    }

    ///////////////////////////////////////////
    // Do not change the above prototype.
    // Add member function(s) below if you need.

    // Do not change the below.
    ///////////////////////////////////////////
};

///////////////////////////////////////////
// Do not change the above prototype.
// Implement function body

// Implement function body
///////////////////////////////////////////

#endif //__BST__