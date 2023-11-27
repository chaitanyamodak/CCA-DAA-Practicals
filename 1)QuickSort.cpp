#include<iostream>
using namespace std;
int Partition(int arr[],int lb,int ub){
	int pivot=arr[lb];
	int start=lb;
	int end=ub;
	while(start<end){
		while(arr[start]<=pivot){
			start++;
		}
		
		while(arr[end]>pivot){
			end--;
		}
		
		if(start<end){
			swap(arr[start],arr[end]);
		}
	}
	swap(arr[lb],arr[end]);
	return end;
}

void QuickSort(int arr[],int lb,int ub){
	if(lb<ub){
		int loc=Partition(arr,lb,ub);
		QuickSort(arr,lb,loc-1);
		QuickSort(arr,loc+1,ub);
	}		
}

int main(){
	int arr[]={30,10,50,40,60,100,80,70,90,20};
	QuickSort(arr,0,9);
	for(int i=0;i<10;i++)
		cout<<arr[i]<<"\t";
	return 0;
}
