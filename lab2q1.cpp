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
	LL() { head = NULL; } 
void insert(int val1) {
		node*n1 = new node(val1);
		n1 -> next = head;
		head = n1;  }
void display() {

 if (head!= NULL) {	node*current = head;
	while ( current != NULL) {
	cout << current -> val << "->";
	current = current -> next; } }
		else { cout << "LL empty" << endl; } }
void delet() {
	node*temp = head;
	head = head -> next;
	delete temp; }
int count () {
	node*curr = head;
	int count=0;
	while ( curr != NULL ) {
		curr = curr -> next;
		count++; }
	return count; } 
node*gettail() {
	node *cur = head;
	while ( cur != NULL) {
		cur = cur -> next;
		}
	return cur; } 
void insertat(int val1,int pos) {
	if ( (pos>=1) && (pos <= (count() +1) ) ) {
	if (pos==1) {
		insert(val1);
	 	}
	else {
		node*curr1=head;
		node*temp1=new node(val1);
		int num=1;
		while ( num != (pos-1) ) {
		curr1 = curr1 -> next;
		num++; }
		temp1 -> next = curr1 -> next;
		curr1 -> next = temp1; }
		}
	else { cout << "positon not exist" << endl; } }  
void deletat(int pos1) {
	if ( (pos1>=1) && (pos1 <= count() )) {
	 if (pos1==1) {
		delet();
	 	}
	else { node*temp2;
		node*curr2=head;
		int num=1;
		while ( num != pos1-1 ) {
		curr2 = curr2 -> next;
		num++; }
		temp2 = curr2 -> next;
		curr2 -> next = temp2 -> next;
		delete temp2; } }
	else { cout << "positon not exist" << endl; } }  
	};
class stack {
public:
	node*top;
	LL l1;
	stack() {
		top = l1.head; }
void push(int val1) {
		l1.insert(val1); 
		top= l1.head;}
void pop() {
		if ( top!= NULL) {
		l1.delet(); 
		top=l1.head; }
		else { cout << "error" << endl; } } 
int count() { 
		return l1.count(); }
void display() {
		l1.display();}
}; 
int main () {
	stack ss;
	ss.push(1);
	ss.push(2);
	ss.push(3);
	ss.pop();
	ss.pop();
	ss.pop();
	ss.pop();
	ss.push(1);
	ss.display();
	return 0; }
