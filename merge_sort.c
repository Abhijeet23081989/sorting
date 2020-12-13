//merge_sort algo
#include<stdio.h>
#include<stdlib.h>

int split_array(int*,int);
int comp_merge(int*,int*,int,int);
int display_sorted_arr(int*,int);

int main()
{
	//1-> Create Array
	//2-> Split Array in half
	//3-> Keep spliting array in half untill only single elements are left
	//4-> Sort the single elements in ascending or descending order(as per requirement)
	//5-> Remerge the sorted elements untill complete array is formed
	
	int* arr;
	int i,sizeofarr=9;
	arr=(int*)malloc(sizeof(int)*sizeofarr);
	//printf("Enter Nine Elements\n");
	//for(i=0;i<9;i++)
	//	scanf("%d",&arr[i]);
	*(arr+0)=3;
	*(arr+1)=9;
	*(arr+2)=12;
	*(arr+3)=1;
	*(arr+4)=4;
	*(arr+5)=13;
	*(arr+6)=2;
	*(arr+7)=8;
	*(arr+8)=6;
	display_sorted_arr(arr,sizeofarr);
	split_array(arr,sizeofarr);
}

int split_array(int* arr,int sizeofarr)
{
	int mid=sizeofarr/2;
	int arr_Lsize=mid,arr_Rsize=sizeofarr-mid;
	//printf("mid=%d\n",mid);
	int i,j;
	int* arr_L,*arr_R;
	if(mid!=0)
	{
		arr_L=(int*)malloc(sizeof(int)*mid);
		arr_R=(int*)malloc(sizeof(int)*(sizeofarr-mid));
	//---------------Actual Split Operation-----------------
		/*Original Idea is to use loops<Safe idea>*/
		for(i=0;i<arr_Lsize;i++)
			*(arr_L+i)=*(arr+i);
		for(j=0;j<arr_Rsize;j++)
		{
			*(arr_R+j)=*(arr+i);
			i++;
		}
		
		/*My Idea is to point arr_R to right half of array<Eligent idea>*/

		//arr_L=arr;
		//arr_R=arr+mid;
	//------------------------------------------------------
	}
	else if(mid==0)
	{
		printf("returning back to call from arr[0]=%d\n",arr[0]);
		return 0;
	}
	sleep(1);
	//printf("IN split_array %d\n",cnt);
	//cnt++;
	printf("\n");
	display_sorted_arr(arr_L,arr_Lsize);
	printf("\t");
	display_sorted_arr(arr_R,arr_Rsize);
	printf("\n");
	
	split_array(arr_L,arr_Lsize);
	split_array(arr_R,arr_Rsize);
	comp_merge(arr_L,arr_R,arr_Lsize,arr_Rsize);
	free(arr_L);
	free(arr_R);
}

int comp_merge(int* arr_L,int* arr_R,int arr_Lsize,int arr_Rsize)
{
	static int cnt=0;
	int i=0,j=0,k=0;
	int *remrgd_arr;
	remrgd_arr=(int*)malloc(sizeof(int)*(arr_Lsize+arr_Rsize));
	printf("arr_Lsize=%d\narr_Rsize=%d\n",arr_Lsize,arr_Rsize);
	//1.Compare Left and right array
	while(i<arr_Lsize && j<arr_Rsize)
	{
		//Compare arr_L & arr_R and put lowest element in remrgd_arr
		if(*(arr_L+i)<=*(arr_R+j))
		{
			*(remrgd_arr+k)=*(arr_L+i);
			i++;
		}
		else
		{
			*(remrgd_arr+k)=*(arr_R+j);
			j++;
		}
		k++;
	}
		//Whatever is left put in remrgd array only after one of the array's are finished
	while(j<arr_Rsize)
	{
		*(remrgd_arr+k)=*(arr_R+j);
		k++;
		j++;
	}
	while(i<arr_Lsize)
	{
		*(remrgd_arr+k)=*(arr_L+i);
		k++;
		i++;
	}
	cnt++;
	printf("In comp_merge=%d\n",cnt);
	display_sorted_arr(remrgd_arr,arr_Lsize+arr_Rsize);
	printf("\n");
	free(remrgd_arr);
}

int display_sorted_arr(int* remrgd_arr,int sizeofarr)
{
	for(int l=0;l<sizeofarr;l++)
		printf("%d ",*(remrgd_arr+l));
}
