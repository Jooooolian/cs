using namespace std;

class Node {
	private:
    	int data;
   		node *next;
   	public:
   		Node();
   		Node(int d, Node* n);

   	friend class LinkedList;
};

class LinkedList(){
	private:
    	node *head, *tail;

    public:
	    LinkedList(){
	      head=NULL;
	      tail=NULL;
	    }
	    LinkedList(){}
	    ~LinkedList(){}

	    void newNode(int i){
	    	node *newNode = new node;
	    	newNode->data = i;
	    	newNode->next = NULL;

	    	if (head == NULL){
	    		head = newNode;
	    		tail = newNode;
	    		newNode = NULL;
	    	} else {
	    		tail->next = newNode;
	    		tail = newNode;
	    	}
	    }

	    void addToHead(int d){

	    }

	    void removeHead(){
	    	
	    }

	    void addToTail(int d){
	    	if (isEmpty()){
	    		tail = head = new Node(d);
	    	} else {
	    		tail->next = new Node(d);
	    		tail = tail->next;
	    	}
	    }
};

