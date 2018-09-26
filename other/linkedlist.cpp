using namespace std;

struct node {
    int data;
    node *next_node;
};

class LinkedList(){
	private:
    	node *start_node, *end_node;

    public:
	    LinkedList(){
	      start_node=NULL;
	      end_node=NULL;
	    }
	    LinkedList(){}
	    ~LinkedList(){}

	    void newNode(int i){
	    	node *newNode = new node;
	    	newNode->data = i;
	    	newNode->next_node = NULL;

	    	if (start_node == NULL){
	    		start_node = newNode;
	    		end_node = newNode;
	    		newNode = NULL;
	    	} else {
	    		end_node->next = newNode;
	    		end_node = newNode;
	    	}
	    }
};

