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
}

int quick_sort(int* arr, int start,int end)
{
	int pIndex=0;static int cnt=0;
	//First bring pivot element to its rightful place and then arrange :
        //a-->.arr[i]<pivot to left
	//b-->arr[i]>pivot to right
	if(start>=end)
		return 0;
	cnt++;
	if(cnt==2)
	printf("In quick sort %d\nstart=%d\nend=%d\n",cnt,start,end);
	sleep(1);
	pIndex=partition(arr,start,end);
	if(cnt==2)
	printf("pIndex in quick sort=%d\n",pIndex);
	//Then Quick sort left elements
	quick_sort(arr,start,pIndex-1);
	//Quick Sort right elements
	quick_sort(arr,pIndex+1,end);
}

//Partition is about bringing the pivot element in the middle and arranging all elements about pivot
int partition(int * arr, int start,int end)
{
	int pivot,pIndex=0,i;static int cnt=0;
	//Taking last element as pivot element 
	pivot=arr[end];
	//printf("pivot=%d\n",pivot);
	cnt++;
	//if(cnt==2)
	//{
	//printf("In partion %d\n",cnt);
	//printf("start=%d\nend=%d\n",start,end);
	printf("pivot=%d\n",pivot);
	//}
	//For pivot=last element
	for(i=start;i<end;i++)
	{
		//printf("arr[pIndex]=%d\ti=%d\n",arr[pIndex],i);
		//printf("pivot=%d\n",pivot);
		if(arr[i]<pivot)
		{
			if(arr[i]<arr[pIndex])
			{
			//swap(arr[pIndex],arr[i]);
			arr[pIndex]=arr[pIndex]+arr[i];
			arr[i]=arr[pIndex]-arr[i];
			arr[pIndex]=arr[pIndex]-arr[i];
			pIndex=pIndex+1;	
			}
		}
		if(cnt==2)
		{
		display(arr,8);
		printf("\n");
		}
	}
	if(cnt==2)
	printf("pIndex=%d\n",pIndex);
	//For pivot=first element
	//for(i=start+1,i<=end;i++)
	//For pivot=middle element
	//for(start-->mid-1)
	//for(mid+1-->end)
	//For pivot=random element
	//for(?)
	//swap(arr[pIndex],pivot);
	arr[pIndex]=arr[pIndex]+pivot;
	pivot=arr[pIndex]-pivot;
	arr[pIndex]=arr[pIndex]-pivot;
	if(cnt==3)
	{
	printf("arr[pIndex]=%d\n",arr[pIndex]);
	display(arr,8);
	printf("\n");
	}
	return pIndex;
}

void swap(int a,int b)
{
	a=a+b;
	b=a-b;
	a=a-b;
}
int display(int*arr,int size)
{
	for(int j=0;j<size;j++)
		printf("%d ",arr[j]);
}
