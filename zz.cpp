#include <iostream>
using namespace std;

class node {
	public:
	node*left;
	node*right;
	node*parent;
	int val;
	node(int valnew) {
		val = valnew;
		left=NULL;
		right=NULL;
		parent=NULL; 
			}
	  };

class bst {
	public:
	node*root;
	bst() {
		root=NULL;
		}
void inserthelper(node*curr, int val1) {
	node*temp=new node(val1);
	if (root==NULL) {
			root=temp; 
			}
	else if(curr->val>val1) {
			if (curr->left==NULL) {
						curr->left=temp;
						temp->parent=curr;
						}
			else {
				inserthelper(curr->left,val1);
             	             }
				}
	else {
		if (curr->right==NULL) {
						curr->right=temp;
						temp->parent=curr;
						}
			else {
				inserthelper(curr->right,val1);
             	             }
		}
					}
void insert(int val1) {
	inserthelper(root,val1); 
			}
void displayhelper(node*curr) {
	if (curr==NULL) {
		return; }
	else {
		displayhelper(curr->left);
		cout << curr->val << "->";
		displayhelper(curr->right);	
	     }
				}
void display() {
	displayhelper(root);
		}
node*searchhelper(node*curr,int val1) {
	if (curr==NULL) {
		cout << "not found" <<endl;
		return curr;
			}
	else if (curr->val==val1) {
				    //cout << "found" << endl;
					return curr;
				  }
	else if (curr->val>val1) {
				 return searchhelper(curr->left,val1);
				}
	else {
		return searchhelper(curr->right,val1);
	    }
					}
void search(int val1) {
		searchhelper(root,val1);
			}
node*findmaxhelper(node*curr) {	
	if (curr==NULL) {
			return curr; }
	else {
		while (curr->right!=NULL) {
					curr= curr->right;
					}
		return curr; 
	     }
				}
node*findmax(){
	node*p=findmaxhelper(root);
	cout<<endl;
	cout << "maximum is "<< p->val; 
	return p; 
		}
void replaceinparent(node*n1,node*n2) {
	//if (n1==root) {
			//root = n2; }
	//else {
	if (n1->parent->left==n1) {
		n1->parent->left=n2;
		}
	else {
		n1->parent->right=n2;
		}
	 n2->parent=n1->parent;
	n1->parent=NULL;
				//}
	}		
void delethelper(node*current,int val1,node*curr1) {
		if (current==NULL) {
			return ; }
	node*curr=searchhelper(curr1,val1);
	if (curr==NULL) {
		cout << "element doesnt exist" << endl;
			}
	else {
		 if (curr->left!=NULL && curr->right!=NULL) {
								node*ops=findmaxhelper(curr->left);
								curr->val=ops->val;
								//delethelper(root,ops->val,ops);
								 									    
								}
		else if (curr->left!=NULL || curr->right!=NULL ) {
								 	if (curr==root) {		
											 if (curr->left!=NULL) {
														root=curr->left;
														root->parent=NULL;
														delete curr; 
														}
											else {
												root = curr->right;
												root->parent=NULL;
												delete curr;
											      }
									                     }
									else {
										if (curr->left!=NULL) {
										if(curr->parent->left==curr){
										curr->parent->left=curr->left;
										curr->left->parent=curr->parent;
															
										delete curr; }
										else {
					  					curr->parent->right=curr->left;
										curr->left->parent=curr->parent;
										delete curr; }				
												      }
										else {
											
										if(curr->parent->left==curr){
										curr->parent->left=curr->right;
										curr->right->parent=curr->parent;
												              			
										delete curr; }
										else {
					  					curr->parent->right=curr->right;
										curr->right->parent=curr->parent;
										delete curr; }	
										     }
									      } 
								    }
	        else {
			if (curr==root) {
					root=NULL;
					}
			else {
				if (curr->parent->left==curr) {
					curr->parent->left=NULL;
								}
					else {
					curr->parent->right=NULL;
						}
	 				
					curr->parent=NULL;
			      }
		     }
		} }
			

void delet(int val1) {
	delethelper(root,val1,root); 
			}
};
int main() {
	bst b1;
	b1.insert(7);
	b1.insert(3);
	b1.insert(6);
	b1.insert(8);
	b1.insert(5);
	b1.insert(4);
	b1.insert(1);
	b1.insert(10);
	b1.insert(9);
	b1.display();
	cout<<endl;
	b1.search(1);
	//b1.findmax();
	b1.delet(8);
	b1.display();
	return 0; 
	  }
		
