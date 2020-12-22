//Quick-Sort Algo
#include<stdio.h>
#include<stdlib.h>

int quick_sort(int*,int,int);
int partition(int *,int,int);
void swap(int a,int b);
int display(int*,int);

int main()
{
	//1-->Select pivot element(first,last,mid or random)
	//2-->Set all elements of array < pivot on left of pivot and all elements > pivot on right to right of pivot
	//3-->Set pivot element on pivot index
	//4-->Repeat steps 1-3 on left elements and on right elements
	//Note--> No extra array should be made. All the swaping and partitioning(proverbial) should be done on the original array
	int * arr;
	int start,end;
	arr=(int*)malloc(sizeof(int)*8);
	*(arr+0)=7;
	*(arr+1)=2;
	*(arr+2)=1;
	*(arr+3)=6;
	*(arr+4)=8;
	*(arr+5)=5;
	*(arr+6)=3;
	*(arr+7)=4;
	display(arr,end+1);
	printf("\n");
	start=0;end=7;
	quick_sort(arr,start,end);
	display(arr,end+1);
	printf("\n");
}

int quick_sort(int* arr, int start,int end)
{
	//First bring pivot element to its rightful place and then arrange :
        //a-->.arr[i]<pivot to left
	//b-->arr[i]>pivot to right
	if(start>=end)
		return 0;
	sleep(1);
	int pIndex=partition(arr,start,end);
	//Then Quick sort left elements
	quick_sort(arr,start,pIndex-1);
	//Quick Sort right elements
	quick_sort(arr,pIndex+1,end);
}

//Partition is about bringing the pivot element in the middle and arranging all elements about pivot
int partition(int * arr, int start,int end)
{
	int pivot,pIndex=start,i,tmp;
	//Taking last element as pivot element 
	pivot=arr[end];
	//For pivot=last element
	for(i=start;i<end;i++)
	{
		if(arr[i]<pivot)
		{
			tmp=arr[pIndex];
			arr[pIndex]=arr[i];
			arr[i]=tmp;
			pIndex=pIndex+1;	
		}
		display(arr,8);
		printf("\n");
	}
	//For pivot=first element
	//for(i=start+1,i<=end;i++)
	//For pivot=middle element
	//for(start-->mid-1)
	//for(mid+1-->end)
	//For pivot=random element
	//for(?)
	tmp=arr[pIndex];
	arr[pIndex]=arr[end];
	arr[end]=tmp;
	display(arr,8);
	printf("\n");
	return pIndex;
}

int display(int*arr,int size)
{
	for(int j=0;j<size;j++)
		printf("%d ",arr[j]);
}
