#include<stdio.h>
#include<stdlib.h>

int BinarySearch(int arr[], int n, int key)
{
	int low, high;
	low = 0;
	high = n-1;
	
	while(low<=high)
	{
		int mid =low + (high-low)/2;
		if(arr[mid] == key)
			return mid;
		else if(key > arr[mid])
			low  = mid+1;
		else
			high = mid-1;
	}
	return -1;
}

int FirstOccurance(int arr[], int n, int key)
{
	int low, high;
	low = 0;
	high = n-1;
	int result = -1;
	while(low<=high)
	{
		int mid =low + (high-low)/2;
		if(arr[mid] == key)
		{
			result = mid;
			high = mid-1;
		}
		else if(key > arr[mid])
			low  = mid+1;
		else
			high = mid-1;
	}
	return result;
}

int LastOccurance(int arr[], int n, int key)
{
	int low, high;
	low = 0;
	high = n-1;
	int result = -1;
	while(low<=high)
	{
		int mid =low + (high-low)/2;
		if(arr[mid] == key)
		{
			result = mid;
			low = mid+1;
		}
		else if(key > arr[mid])
			low  = mid+1;
		else
			high = mid-1;
	}
	return result;
}

void TotalOccurance(int arr[], int n, int key)
{
	int first = FirstOccurance(arr,n,key);
	int last  = LastOccurance(arr,n,key);
	
	if(first != -1)
		printf("Total Occurances are %d\n", last-first+1);
	else
		printf("Element Not Found\n"); 	
}

int BinarySearchRec(int arr[], int low, int high, int key)
{
	if(low<=high)
	{
		int mid =low + (high-low)/2;
		if(arr[mid] == key)
			return mid;
		else if(key > arr[mid])
			return BinarySearchRec(arr, mid+1, high, key);
		else
			return BinarySearchRec(arr, low, mid-1, key); 
	}
	return -1;
}

int main()
{
	int sorted_array[20] = {1,2,3,3,5,6,6,6,6,6,6,6,8,8,8,8,9,10,10,10};
	printf("Enter the Number to be found\n");
	int key, result;
	scanf("%d", &key);
	//result = BinarySearch(sorted_array, 20, key);
	//result = BinarySearchRec(sorted_array, 0,19,key);
	//result = FirstOccurance(sorted_array,20,key);	
	//result = LastOccurance(sorted_array,20,key);
	TotalOccurance(sorted_array,20,key);
	if(result != -1)
	{
		printf("Element exists at %d\n", result);
	}
	else
		printf("Element not found\n");
return 0;
}
