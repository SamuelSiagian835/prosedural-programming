#include <stdio.h> 
  
void swap ( int* a, int* b )
{ 
    int t = *a;
    *a = *b;
    *b = t;
} 
  
int partition ( int arr[], int low, int high )
{
	int pivot = arr[high];
	int i = low - 1; 
  
    for ( int j = low; j <= high- 1; j++ ) {
		if ( arr[j] <= pivot ) {
			i++;
			swap( &arr[i], &arr[j] );
		}
	}
	swap( &arr[i + 1], &arr[high] );
	return i + 1;
}

void quickSort ( int arr[], int low, int high )
{
	if ( low < high ) {
		int pi = partition( arr, low, high );
		
		quickSort( arr, low, pi - 1 );
		quickSort( arr, pi + 1, high );
	}
}

void PrintArray ( int *array, int end ){
	int i;
	for ( i = 0; i < end; i++ ) printf( "%d ", array[i] );
	printf( "\n" );
}
  
int main ( ){
	int arr[10] = { 5, 2, 7, 4, 1,
					0, 3, 9, 6, 8 };

	printf( "Array BEFORE sorting:\t" );
	PrintArray( arr, 10 );
	
	quickSort( arr, 0, 10) ;
	
	printf( "Array AFTER sorting:\t" );
	PrintArray( arr, 10 );
		
	return 0; 
}
