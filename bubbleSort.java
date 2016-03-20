package Data_Structures;

public class bubbleSort {

	static int arr[] = {5,6,7,1,4,9,2,3,13,12,19,14,11,0};
	public static void main(String[] args) {		
		for(int i=arr.length -1; i >=0; i--){
			for(int j=0; j <= i; j++){
				if((j+1) <= arr.length-1){
				if(arr[j] > arr[j+1]){
					swap(j,j+1);
					}
					
								
				}
			}
		}
		System.out.println("start");
		for(int m=0; m<arr.length; m++){
			System.out.println(arr[m]);}
}
	
	static void swap(int i, int j){
		int temp;
		temp = arr[j];
		arr[j] = arr[i];
		arr[i] = temp;		
	}

}
