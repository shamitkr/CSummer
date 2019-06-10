#include <iostream>
using namespace std;

class node {
		public:
		int val;
		node*next;
		node(int valnew) {
				val = valnew;
				next = NULL; } };

class stack {
	public:
	node*top;
		stack() { top = NULL; } 

void push(int val1) {
		node*n1 = new node(val1);
		n1 -> next = top;
		top = n1; }
void pop() {
		if(top != NULL) {node*temp=top;
		top = top -> next;
		delete temp; }
	else { cout << "Error" << endl; } }
void display() {
		node*current = top;
		while ( current!= NULL) {
			cout <<current -> val << "->";
			current = current -> next; } }
int count() { 
		int count1=0;
	node*curr=top;
	while ( curr != NULL) {
		count1 ++;
		curr = curr -> next;
		}
	
	return count1; } };
class queue {
	public:
	node*front;
	node*end;
	stack ss;
	queue() {
		front= ss.top;
		end= NULL; }
void enqueue(int val1) {
		ss.push(val1);
		front = ss.top; }
void display() {
		ss.display(); cout << endl;}

node*getend() { 
		node*curr1=front;
		int num=1;
		while (num < (ss.count()-1)) {
		curr1=curr1->next;
		num++; }
		return curr1; }
void dequeue() {
	if( front != NULL ) {
	if ( front->next == NULL) { ss.top = NULL;front = ss.top; }
	else { end = getend();
		node * temp1;
		temp1 = end -> next;
		end -> next = NULL;
		delete temp1;
		} }
	else { cout << "error" << endl; } }		

	
};
		
		 

int main() {
	queue qq;
	qq.enqueue(1);
	qq.enqueue(2);
	qq.enqueue(3);
	qq.dequeue();
	qq.display();
	qq.dequeue();
	qq.display();
	qq.dequeue();
	qq.display();
	qq.enqueue(5);
	qq.enqueue(1);
	qq.enqueue(2);
	qq.enqueue(3);
	qq.dequeue();
	qq.dequeue();
	qq.dequeue();
	qq.dequeue();
	qq.dequeue();
	qq.display();
	//cout<< qq.getend()->val << endl;
		 
		 	 
	//qq.display();
return 0;}
