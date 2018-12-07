// Name: Julian Bartholomee                                                        
// Email: jbp402@psu.edu                                                           
// Due Date: December 10 2018                                                     
// Class: CMPSC 122 - Intermediate Programming Fall 2018                           
// Professor Sukmoon - T, Th: 1:35                                                 
                                                                                
// Description:                                                                    
// This program is an implementaton of a Binary Search Tree. It includes traversal methods, and clear(), insert(), and search()

// Acknowledgement:                                                                
// I used the Data Structures class book for guidence in this assignment.

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

    void ReInorder(void (*visit)(const Node*), Node*);
    void RePreorder(void (*visit)(const Node*), Node*);
    void RePostorder(void (*visit)(const Node*), Node*);

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

void DeleteNode(const Node* r){
	delete r;
}

void BST::Clear(){
	this->Postorder(DeleteNode);
	root = NULL;
}


Node* BST::Search(double query){
	Node *r = root;

	while (r != NULL)
        if (query == r->value){
        	//We found it!
        	return r;
        } else if (query < r->value){
        	//Travel to the left -
        	r = r->left;
        } else{
        	//Travel to the right +
        	r = r->right;
        } 
    //We did not find it :(
	return NULL;
}

void BST::Insert(double value){
	Node *r = root;
	Node *prev = NULL;


	while (r != NULL) {
		prev = r;
		if (value < r->value){
			//Travel to the left -
			r = r->left;
		}
		else{
			//Travel to the right +
			r = r->right;
		}
	}

	if (root == NULL){
		//Insert to empty tree as root
		root = new Node(value);

	} else if (value < prev->value){
		//Insert to left child
		prev->left = new Node(value);

	} else {
		//Insert to right child
		prev->right = new Node(value);
	}
}

void BST::Inorder(void (*visit)(const Node*)){
	Node *r = root;
	if (r == NULL){
		return;
	} else {
		this->ReInorder(visit, r->left);
		visit(r);
		this->ReInorder(visit, r->right);
	}
}

void BST::ReInorder(void (*visit)(const Node*), Node* r){
	if (r == NULL){
		return;
	} else {
		this->ReInorder(visit, r->left);
		visit(r);
		this->ReInorder(visit, r->right);
	}
}

void BST::Preorder(void (*visit)(const Node*)){
	Node *r = root;
	if (r == NULL){
		return;
	} else {
		visit(r);
		this->RePreorder(visit, r->left);
		this->RePreorder(visit, r->right);
	}
}

void BST::RePreorder(void (*visit)(const Node*), Node* r){
	if (r == NULL){
		return;
	} else {
		visit(r);
		this->RePreorder(visit, r->left);
		this->RePreorder(visit, r->right);
	}
}


void BST::Postorder(void (*visit)(const Node*)){
	Node *r = root;
	if (r == NULL){
		return;
	} else {
		this->RePostorder(visit, r->left);
		this->RePostorder(visit, r->right);
		visit(r);
	}
}

void BST::RePostorder(void (*visit)(const Node*), Node* r){
	if (r == NULL){
		return;
	} else {
		this->RePostorder(visit, r->left);
		this->RePostorder(visit, r->right);
		visit(r);
	}
}

// Implement function body
///////////////////////////////////////////

#endif //__BST__
