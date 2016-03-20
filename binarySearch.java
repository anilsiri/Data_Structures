package Data_Structures;

//to search a number in an array using binary search
//time complexity is O(n logn) 

public class binarySearch {

	static int array[] = {2,3,6,9,14,18,31,41};
	
	static void bSearch(int key){
		int min=0;
		int max = array.length -1;
		int mid;
		
		while(min <= max){
		
		mid = min + (max - min) / 2;		
		if(array[mid] == key){
			System.out.println(mid + 1);
			return;
		}
		else if(array[mid] > key){
			max = mid -1;
		}		
		else
			min = mid +1;			
		}
		}
		
	public static void main(String[] args) {
		
		bSearch(31);
		System.out.println("done");
		
		
		

	}

}
