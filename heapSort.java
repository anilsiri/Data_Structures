package Data_Structures;

public class heapSort {
	
	static int arr[] = {5,7,9,1,2,19};
	static int length = arr.length-1;
		
	static void maxHeapify(){
		for(int i= (length/2) ; i>=0; i--){
		max_heap(arr, i);		
		}
	}
	
 static	void max_heap(int array[], int i){
		int l = 2*i + 1;
		int r = 2*i + 2;
		int largest;
		int heapSize = array.length - 1;
		
		if(l <= heapSize && array[l] > array[i]){
			largest = l;
		}
		else 
			largest = i;
		
		if(r <= heapSize && array[r] > array[largest]){
			largest = r;
		}
		
		if(i!=largest){
			swap(i,largest);
			max_heap(array, largest);			
		}		
	}

 	static void swap(int a, int b){
		int temp;
		temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;	
	}
 	
 int heap_extract_max(int array[]){
 	int max;
 	max = array[0];
 	//array[0] = array[heapSize-1];
 	//heapSize = heapSize -1;
 	max_heap(array, 1); 	
	 return max;
 	}
	
	public static void main(String[] args) {
		maxHeapify();
		int len = arr.length;
		
		//heap_extract_max(arr);
		
		
		
		
		
		
	}
}
	


	