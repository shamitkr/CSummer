#include <iostream>
using namespace std;

class node { public:
	int val;
	node*next;
	node(int valnew) {
		val = valnew;
		next= NULL; } };
class queue {	public:
		node*front;
		node*end; 
		queue() {
		front = NULL;
		end = NULL; }

void enqueue(int val1) {
		node*n1 = new node(val1);
		n1 -> next = front;
		front = n1; }
void display() {
	node*current=front;
	while (current != NULL) {
			cout<<current -> val<<" ";
			current = current -> next;
			}} 
int count() {
		int count=0;
		node*curr=front;
		while (curr != NULL ) {
			count++;
			curr = curr -> next;
			}
		
		return count; }
node*getend() { node*temp2=front;
		int num=1;
		while ( num < (count() -1) ){
		num++;
		temp2 = temp2 -> next;}
		return temp2; }
		
		
void dequeue(){	
	if ( front != NULL) {
	if (front-> next ==NULL) {
			front=NULL; }
	else {
		end = getend();
			node*curr1;
			curr1 = end -> next;
			end->next = NULL;
			delete curr1;
		 } }
	else { cout << "error" << endl; }}
		
		  
		   
};
int main () {
		queue qq;
		qq.enqueue(1);
		qq.enqueue(2);
		qq.enqueue(3);
		qq.dequeue();
		qq.dequeue();
		qq.dequeue();
		qq.dequeue();		
		qq.display();
return 0; }
