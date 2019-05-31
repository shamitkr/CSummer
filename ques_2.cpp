#include <iostream>
using namespace std;
	
class node {
	public:
	int val;
	node*next;
	node(int valnew) {
		val = valnew;
		next = NULL; } };

class LL {
	public:
	node*head;
	LL () {
			head = NULL ; }

void insert (int val1) {
		node*n1=new node(val1);
		n1-> next = head;
		head = n1;
		}

void display() {
		node*current = head;
		while (current != NULL) {
		cout << current -> val << "->" ;		
		current =current -> next; } 
		}



int count() {
			int count = 0;
			node*cur=head;
			while ( cur != NULL )
			{ count ++ ;
			cur = cur -> next;
			}	
			return count; }


void insertat( int val2, int pos) {
			if ( (pos >= 1) && (pos <= (count() + 1)) ) { 
			if (pos ==1) { insert(val2); }
			else { node*curr1=head;
				   node*temp1 = new node(val2); 
				 int num2=0;
				while ( num2 != (pos-1) ) {
				curr1 = curr1 -> next;
				num2++ ;}
				temp1-> next = curr1 -> next;
				curr1 -> next = temp1; } }
		else { cout << "positon not exist" << endl; } } 

};
int main () {
		LL l1;
		for (int i=0; i<10; i++) {
		l1.insert (i); }
		l1.insertat(11,10);

		l1.display();
		return 0; } 


	
					
			
		
