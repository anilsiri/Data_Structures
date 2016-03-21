package Data_Structures;


//program to create a max heap. 
//program takes in an input that is an array
public class maxHeap {
	static int arr[] = {2,1,4,9,8,6,3,7,10,31};
	
	static void max_heap(){	
		int heapSize;
		heapSize = arr.length-1;
		for(int i=(heapSize/2) ; i >= 0; i--){
			//System.out.println("i is " + i);
			heap(i);
		}
		
	}
	
	
	//algorithm is - for each of the non leaf nodes, we find if its children are satisfying the max heap property
	//and if they are, then we continue. else we set it right and call max heap on the child that we just changed - recursive call
	static void heap(int i)
	{
		int l = 2*i;
		int r = 2*i + 1;
		int largest;
		
		if((l<=arr.length-1) && (arr[i] < arr[l])){
			largest = l;
		}
		else
			largest = i;
		if((r<=arr.length-1) && (arr[largest] < arr[r])){
			largest = r;
		}
		
		if(largest!= i){
			swap(i,largest);
			heap(largest);
		}	
	}
	
	static void swap(int i, int j){
		int temp;
		temp = arr[j];
		arr[j] = arr[i];
		arr[i] = temp;
	}
	
	
	public static void main(String[] args) {
			max_heap();
			for(int i=0; i<arr.length; i++){
			System.out.println(arr[i]);
			}		

	}

}
