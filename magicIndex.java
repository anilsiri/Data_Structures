package Data_Structures;


//to find the magic index in a sorted array
public class magicIndex {
	static int arr[] = {-40,-20,-1,1,2,3,5,7,9,12,13};
	
	static int findIndex(int min, int max){
		int mid;
		mid = min + (max-min)/2;
	//System.out.println(mid);
		
		if(max < min){
			return -1;
		}
		
		if(arr[mid] == mid){
			return mid;			
		}
		
		else if(arr[mid] > mid){
			return findIndex(min, mid-1);
		}
		else{
			return findIndex(mid+1, max);
			}
	}
	
	
	
	public static void main(String[] args) {

			int indexIs;
			//System.out.println("arraylen-1 is " + arr.length);
			indexIs = findIndex(0, arr.length-1);
		System.out.println(indexIs);

	}

}
