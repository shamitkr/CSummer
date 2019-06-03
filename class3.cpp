#include <iostream>
using namespace std;
	
class node {
public:

			int val ;
			node*next ;
			node(int valnew) {	 
					val= valnew;
					next=NULL ; }
};
class LL { 
public: 
			node*head;
			LL () {
					head=NULL ; }

void insert(int valnew) { 
    
					node*n1= new node(valnew) ;
					n1 -> next = head;
					
					head= n1; }


void delet() {
			node*temp=head;
			head = head -> next;
			delete temp; }


void display() {
					node*current;
					current= head;
				while ( current != NULL ) {
				cout << current -> val << "->";
				current= current-> next; }
				}

int count() {
					node*cur=head;										//start from head
					int count= 0;
			
			       while ( cur!= NULL)	{								// loop till reaches NULL
					count ++;											// increase by 1
					cur =cur -> next; 	}								// jump to next
				 return count; 
					 }

void insertat (int val1,int pos) {
								if ( (pos >= 1) && (pos <= (count() +1 )) ) {
								//case 1 when insertion at 1 pos
								if ( pos==1 ) { 
												insert(val1);
											}
								//case 2  when insertion at middle
										else {  	node*curr;
													node*temp = new node(val1);
													int num=1;													
													while (num != (pos-1) ) {
													curr=curr -> next;
													num++ ; }
								temp -> next = curr -> next;
								curr -> next = temp; 
												} }
						else { 
								cout << "Position dont exist" << endl; }
									}
void deletat(int pos1) { 
						if ( (pos1 >= 1) && (pos1 <= count() ) ) {
						if (pos1==1) {
							delet(); }
						else { node*temp3;
								node*curr3 = head;
								int mun = 1;
							while ( mun != (pos1 -1) ) { 
									curr3 = curr3 -> next;
									mun++ ;}
								temp3 =  curr3 -> next;
								curr3 -> next = temp3 -> next;
								delete temp3; } } 
					else { cout << "not exist" <<endl; } }

node*gettail() {
				node*currr=head;
				while ( currr != NULL) {
				currr = currr -> next;
				}
				return currr; }
};	

class stack { 
	public:
			node*top;
			LL l1;
			stack() { 
					top = l1.head; }
			void push( int val5) {
					l1.insert(val5);
					top = l1.head; }
			void pop() { 
						if (top != NULL ) {
						l1.delet();
						top = l1.head; }
						else { cout << " not allowed" << endl; } }
			void display1() { 
							l1.display() ; }
			int count1() { 
						return l1.count(); } };

class queue {  public:
				node*front;
				node*end;
				LL l2;
				queue() {
						front = l2.head;
						end = NULL; }
				int count2() {
								return  l2.count(); }
				void enqueue(int value) {
									l2.insert(value);
									front = l2.head; }
				void dequeue() {
								
						if (front != NULL) {	l2.deletat(count2()); 
							}
						else { cout << "not exist"; }
						end = l2.gettail(); }
						
				void display() {
								l2.display(); } };
						

			
int main () {
			queue QQ;
			QQ.enqueue(1);
			QQ.enqueue(2);
			QQ.enqueue(3);
			QQ.dequeue();
			QQ.enqueue(4);
			QQ.display();
		
			return 0;
	}
