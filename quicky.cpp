#include <iostream>
using namespace std;

int partition (int arr[],int l,int h) {
int pivot = arr[l];
int i = l+1;
for ( int j=l+1;j<=h;j++) {
	if (arr[j] < pivot ) {
	swap(arr[i],arr[j]);
	i++; } }

	swap(arr[l],arr[i-1]);
	return (i-1); }
void quicksort(int arr[],int l,int h) {
	if (l<h) {
		int p=partition(arr,l,h);

	quicksort(arr,l,p-1);
	quicksort(arr,p+1,h); } }
int main() {
int arr[5]= {5,2,4,9,8};
int l,h;
l=0;
h=4;
quicksort(arr,l,h);
for (int i=0;i<5;i++) {
	cout<< arr[i]; }
return 0; }
