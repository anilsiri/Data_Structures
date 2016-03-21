package Data_Structures;

public class selectionSort {

static int arr[] = {3,4,9,1,2,6,8,41,60,29,5};
	public static void main(String[] args) {
		int min;
		
		for(int i =0; i< arr.length; i++){
			min = arr[i];
			int pos = i;
		for(int j=i+1; j <arr.length; j++){
				if(min > arr[j]){
					min = arr[j];
					pos = j;
				}
			}
			swap(i,pos);			
		}
		
		for(int i =0; i<arr.length; i++){
			System.out.println(arr[i]);
		}
	}
	
static void swap(int m, int n){
		int temp;
		temp = arr[m];
		arr[m] = arr[n];
		arr[n] = temp;		
	}

}
