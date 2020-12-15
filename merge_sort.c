//merge_sort algo
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int* split_array(int*,int);
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
	*(arr+0)=9;
	*(arr+1)=3;
	*(arr+2)=12;
	*(arr+3)=1;
	*(arr+4)=4;
	*(arr+5)=13;
	*(arr+6)=2;
	*(arr+7)=8;
	*(arr+8)=6;
	display_sorted_arr(arr,sizeofarr);
	arr=split_array(arr,sizeofarr);
}

int* split_array(int* arr,int sizeofarr)
{
	int mid=sizeofarr/2;
	int arr_Lsize=mid,arr_Rsize=sizeofarr-mid;
	//printf("mid=%d\n",mid);
	int i,j;
	int* arr_L,*arr_R,*sorted_arr_L,*sorted_arr_R;
	if(mid!=0)
	{
		arr_L=(int*)malloc(sizeof(int)*mid);
		arr_R=(int*)malloc(sizeof(int)*(sizeofarr-mid));
		memset(arr_L,0,mid);
		memset(arr_R,0,sizeofarr-mid);
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
		//printf("returning back to call from arr[0]=%d\n",arr[0]);
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
	
	sorted_arr_L=split_array(arr_L,arr_Lsize);//1.{3,9,12,1} , {3,9},{3},{12}
	sorted_arr_R=split_array(arr_R,arr_Rsize);//1.{4,13,2,8,6},{9},{12,1},{1}
	//comp_merge(arr_L,arr_R,arr_Lsize,arr_Rsize);
	static int cnt=0;
	int *remrgd_arr;
	int sora=arr_Lsize+arr_Rsize;
	remrgd_arr=(int*)malloc(sizeof(int)*sora);
	memset(remrgd_arr,0,sora);
	//if(arr_Lsize>=2 && arr_Rsize>=2)
	//{
	//printf("================START=================\n");
	//printf("In comp_merge=%d\n",cnt);
	printf("arr_Lsize=%d\narr_Rsize=%d\n",arr_Lsize,arr_Rsize);
	for(i=0;i<arr_Lsize;i++)
	printf("sorted_arr_L[%d]=%d\nsorted_arr_R[%d]=%d\n",i,i,sorted_arr_L[i],sorted_arr_R[i]);
	printf("I AM HERE\n");
	//}
	//1.Compare Left and right array
       	i=0;j=0;int k=0;
	while(i<arr_Lsize && j<arr_Rsize)
	{
		//Compare arr_L & arr_R and put lowest element in remrgd_arr
		if(sorted_arr_L[i] < sorted_arr_R[j])
		{
			remrgd_arr[k]=sorted_arr_L[i];
			i++;
		}
		else
		{
			remrgd_arr[k]=sorted_arr_R[j];
			j++;
		}
		k++;

	}
	printf("1-->i=%d\tj=%d\n",i,j);
	display_sorted_arr(remrgd_arr,sora);
	printf("\n");
		//Whatever is left put in remrgd array only after one of the array's are finished
	while(i<arr_Lsize)
	{
		remrgd_arr[k]=arr_L[i];
		k++;
		i++;
	}
	while(j<arr_Rsize)
	{
		remrgd_arr[k]=arr_R[j];
		k++;
		j++;
	}
	printf("2-->i=%d\tj=%d\n",i,j);
	cnt++;
	/*if(arr_Lsize>=2 && arr_Rsize>=2)
	{
	printf("COMP & merge done\n");*/
	display_sorted_arr(remrgd_arr,sora);
	printf("\n");
	//printf("================END=================\n");
	printf("\n");
	//}
	free(arr_L);
	free(arr_R);
	free(sorted_arr_L);
	free(sorted_arr_R);
	return remrgd_arr;
}

int comp_merge(int* arr_L,int* arr_R,int arr_Lsize,int arr_Rsize)
{
	static int cnt=0;
	int i=0,j=0,k=0;
	int *remrgd_arr;
	remrgd_arr=(int*)malloc(sizeof(int)*(arr_Lsize+arr_Rsize));
	printf("================START=================\n");
	printf("In comp_merge=%d\n",cnt);
	printf("arr_Lsize=%d\narr_Rsize=%d\n",arr_Lsize,arr_Rsize);
	//1.Compare Left and right array
	while(i<arr_Lsize && j<arr_Rsize)
	{
		//Compare arr_L & arr_R and put lowest element in remrgd_arr
		if(*(arr_L+i)<*(arr_R+j))
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
	while(i<arr_Lsize)
	{
		*(remrgd_arr+k)=*(arr_L+i);
		k++;
		i++;
	}
	while(j<arr_Rsize)
	{
		*(remrgd_arr+k)=*(arr_R+j);
		k++;
		j++;
	}
	cnt++;
	printf("COMP & merge done\n");
	display_sorted_arr(remrgd_arr,arr_Lsize+arr_Rsize);
	printf("\n");
	printf("================END=================\n");
	printf("\n");
	free(remrgd_arr);
}

int display_sorted_arr(int* remrgd_arr,int sizeofarr)
{
	for(int l=0;l<sizeofarr;l++)
		printf("%d ",*(remrgd_arr+l));
}
