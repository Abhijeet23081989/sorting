//merge_sort algo
#include<stdio.h>
#include<stdlib.h>

int* merge_sort(int*);
int** split_array(int*);
int* comp_merge(int**);

int main()
{
	//1-> Create Array
	//2-> Split Array in half
	//3-> Keep spliting array in half untill only single elements are left
	//4-> Sort the single elements in ascending or descending order(as per requirement)
	//5-> Remerge the sorted elements untill complete array is formed
	
	int *arr;
	int i;
	arr=(int*)malloc(sizeof(int)*9);
	printf("Enter Nine Elements\n");
	for(i=0;i<9;i++)
		scanf("%d",arr+i);
	merge_sort(arr);
}

int* merge_sort(int* arr)
{
	int count=sizeof(arr)/4;
	int **arr_of_arr=NULL;
	//1-> Split Array
	arr_of_arr=split_array(arr);
	//2-> Compare & merge
	return comp_merge(arr_of_arr);
}

int** split_array(int* arr)
{
	int count=sizeof(arr)/4;
	int mid=count/2;
	int* arr_L,*arr_R;
	if(mid!=0)
	{
		arr_L=(int*)malloc(sizeof(int)*mid);
		arr_R=(int*)malloc(sizeof(int)*(count-mid));
	}
	else
		return NULL;
	//---------------Actual Split Operation-----------------
		/*Original Idea is to use loops<Safe idea>*/
		for(int i=0;i<mid;i++)
			*(arr_L+i)=*(arr+i);
		for(int j=mid;j<count;j++)
			*(arr_R+j)=*(arr+j);
		
		/*My Idea is to point arr_R to right half of array<Eligent idea>*/

		//arr_L=arr;
		//arr_R=arr+mid;
	//------------------------------------------------------
	split_array(arr_L);
	split_array(arr_R);
}

int* comp_merge(int** arr_of_arr)
{
}
