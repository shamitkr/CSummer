#include <iostream>
using namespace std;

class node{
		public:
		int val;
		node*parent;
		node*left;
		node*right;
		node(int valnew) {
			val = valnew;
			left=NULL;
			right=NULL;
			parent=NULL; }
	};

class bst{
public:
	node*root;
	bst() { 
		root=NULL; }
void inserthelper(node*curr,int val1) {
	node*temp=new node(val1);	
	if (root==NULL) {
			root=temp; }
	else if (curr->val>val1) {
			if (curr->left==NULL){
						curr->left=temp;
						temp->parent=curr; }
			else { 
				inserthelper(curr->left,val1); } 
				}
	else {
		if(curr->right==NULL) {
					curr->right=temp;
					temp->parent=curr; }
		else {
			inserthelper(curr->right,val1); } 
	     }
					}
void insert(int val1) {
	inserthelper(root,val1) ; 
			}
void displayhelper(node*curr) {
		if (curr==NULL) {
			return ; }
		else {
			displayhelper(curr->left);
			cout << curr->val <<"->";
			displayhelper(curr->right); 
		     }
			     }
void display() {
		displayhelper(root); 
		}
		
node*searchhelper(node*curr,int val1){
	if (curr==NULL) {
			cout << "not found"<<endl; 
			return curr;}
	else if (curr->val==val1) {
		cout << "found" <<endl; 
		    return curr;      }
	else if (curr->val>val1) {
			return searchhelper(curr->left,val1); 
				}
	else if (curr->val<val1) {
			return searchhelper(curr->right,val1); 
				}
	else {
		cout << "not found" <<endl; 
	  }
		return curr;		}
void search(int val1) {	
	searchhelper(root,val1); 
			}

node*findminhelper(node*curr) {
		if (curr==NULL) {
		return curr; }
		else { 
			while(curr->left!=NULL) {
			curr=curr->left; }
			return curr; 
		      }
				}
node*findmin() {
	node*p= findminhelper(root); 
	cout << "minimum is " << p->val; 
	return p; 
		} 
node*findmaxhelper(node*curr) {
		if (curr==NULL) {
		return curr; }
		else { 
			while(curr->right!=NULL) {
			curr=curr->right; }
			return curr; 
		      }
				}
node*findmax() {
	node*p= findmaxhelper(root); 
	cout << "maximum is " << p->val; 
	return p; 
		} 
};

int main() {
	bst b1;
	for(int i=0;i<=10;i++){
	b1.insert(i); }
	b1.display();
	cout<<endl;
	b1.search(9);
	//cout<<b1.search(4)->val;
	
	return 0; }
