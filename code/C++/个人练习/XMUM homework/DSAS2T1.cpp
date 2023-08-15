#include<bits/stdc++.h>
#include<queue>
using namespace std;

#define COUNT 10
class Node{// node prototype 
public:
	char ch;// this letter is taken from the student's first letter
	string studentName;
	int attendance;
	Node *leftChild;
	Node *rightChild;
};
class BST{
	public:
		BST(){
			root=NULL;
		}
	Node *creatNode(string,int);
	Node *insertNode(Node *&,string,int);
	Node *searchNode(Node *,string);
	void displayTree(Node *, int);
	void Inordertraversal(Node *);
	void Inordertraversal80(Node *);
	void deleteNode(string, Node *&);
	void makeDeletion(Node *&);
	void RecordAttend(Node *&,string,int);
	void DisplayAttend(Node*);
	void DisplayAttend80(Node*);

	private:
		Node *root;
};
Node * BST::creatNode(string name,int data){
	Node *newNode=new Node;
	newNode->studentName=name;
	newNode->attendance=data;
	newNode->ch=name[0];
    newNode->leftChild = newNode->rightChild = NULL;
	return newNode;
}
Node *BST::insertNode(Node *&root,string name,int data=0){
	if(root==NULL)
	{
		root=creatNode(name,data);
		return root;
	}
	if(name[0]<root->ch)
	{
		root->leftChild=insertNode(root->leftChild,name,data);
	}
	else if(name[0]>root->ch)
	{
		root->rightChild=insertNode(root->rightChild,name,data);	
	}
	
	return root;
}
Node *BST::searchNode(Node *root,string name){
	Node *CurrNode=root;
	while(CurrNode!=NULL)
	{	
		if(name==CurrNode->studentName) 
		return CurrNode;
		else if(name[0]<CurrNode->ch)
		{
			CurrNode=CurrNode->leftChild;
		}
		else if(name[0]>CurrNode->ch)
		{
			CurrNode=CurrNode->rightChild;
		}
		else
		break;
	}
	cout<<"Not Found"<<endl;
	return NULL;
}
void BST::displayTree(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    displayTree(root->rightChild, space);

    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->ch<<endl;

    // Process left child
    displayTree(root->leftChild, space);

}
void BST::Inordertraversal(Node *root){
	if(root!=NULL)
	{
		Inordertraversal(root->leftChild);
		cout<<root->studentName<<"\t\t"<<root->attendance<<"%\n";
		Inordertraversal(root->rightChild);
	}
}
void BST::Inordertraversal80(Node *root){
	if(root!=NULL)
	{
		Inordertraversal80(root->leftChild);
		if(root->attendance<80)
		{
		cout<<root->studentName<<"\t\t"<<root->attendance<<"%\n";
	 	}
		Inordertraversal80(root->rightChild);
	}
}
void BST::makeDeletion(Node *&nodePtr)
{
	Node *tempNodePtr, *tempNodePtr2;	// Temporary pointer, used in reattaching the left subtree.

    // case 1: node with no children
    if(nodePtr->leftChild==NULL && nodePtr->rightChild==NULL){
      tempNodePtr=nodePtr;
      nodePtr=NULL;
      delete tempNodePtr;
    }
    else if(nodePtr->rightChild==NULL){
         tempNodePtr=nodePtr;
        nodePtr=nodePtr->leftChild;
        delete tempNodePtr;
    }
    else if(nodePtr->leftChild==NULL){
        tempNodePtr=nodePtr;
        nodePtr=nodePtr->rightChild;
        delete tempNodePtr;
    }
    else if(nodePtr->leftChild && nodePtr->rightChild){
        tempNodePtr=nodePtr->rightChild;
        while(tempNodePtr->leftChild)
        tempNodePtr=tempNodePtr->leftChild;
        nodePtr->ch=tempNodePtr->ch;
        nodePtr->attendance=tempNodePtr->attendance;
    	nodePtr->studentName=tempNodePtr->studentName;
        deleteNode(nodePtr->studentName,nodePtr->rightChild);
    }
}
void BST::deleteNode(string name, Node *&nodePtr)
{
// find a node with value num and call makeDeletion(nodePtr);
    if(nodePtr){
        if(name[0]<nodePtr->ch)
            deleteNode(name,nodePtr->leftChild);
        else if(name[0]>nodePtr->ch)
            deleteNode(name,nodePtr->rightChild);
        else if(name==nodePtr->studentName)
            makeDeletion(nodePtr);

    }

}
void BST::RecordAttend(Node *&root,string name,int attendance){
	Node* search=searchNode(root,name); 
	if(search)
	{
		search->attendance=attendance;
	}
		
}
void BST::DisplayAttend(Node *root){
	cout<<"Name\t\tattendance"<<endl;
	Inordertraversal(root);
}
void BST::DisplayAttend80(Node *root){
	cout<<"The student who's attandance is less than 80%\n";
	cout<<"Name\t\tattendance"<<endl;
	Inordertraversal80(root);
}
int main()
{
	BST bst;
	Node *root=NULL;
	int op=0,op2=0;string name;int attend;
	while(op!=5){
		cout<<"1.	Insert a node (base on ch)\n";
		cout<<"2.	Record attendance\n";
		cout<<"3.	Delete a node\n";
		cout<<"4.	Display tree (can use the function in the tutorial)\n";
		cout<<"5.	Exit\n";
		cout<<"Please select an operation: ";
		cin>>op;
		switch(op){
			case 1:
				cout<<"Please input a name:";
				cin>>name;
				bst.insertNode(root,name);
//				system("cls");
				break;
			case 2:
				while(op2!=4)
				{
				cout<<"1.	Record attendance\n";
				cout<<"2.	Display attendance (all students)\n";
				cout<<"3.	Display attendance (students with less than 80%)\n";
				cout<<"4.	Back\n";
				cout<<"Please select an operation: ";
				cout<<"Select:";
				cin>>op2;
					switch(op2){
						case 1:
							cout<<"Specify the name to record the attendance:";
							cin>>name;
							cout<<"Out of 10 lectures, input the attendance for Adam:";
							cin>>attend;
							attend*=10;
							bst.RecordAttend(root,name,attend);
							break;
						case 2:
							bst.DisplayAttend(root);
							break;
						case 3:
							bst.DisplayAttend80(root);
							break;
						case 4:
							break;
					}
				}
				break;
			case 3:
				cout<<"Please input the name you want to delete:";
				cin>>name;
				bst.deleteNode(name,root);
				break;
			case 4:
				bst.displayTree(root,3) ;
				break;
			case 5:
				break;	
		}
		cout<<endl;
	}
	return 0;
}

