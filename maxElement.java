package Data_Structures;
//replace every element with the maximum element on the right side
public class maxElement {

	static int arr[] = {16,17,4,5,2,1,8,7,4};
	static int length = arr.length -1;
	static int maximum = -1;
	
	
	public static void main(String[] args) {
		
		System.out.println(length);
		int temp;
		for(int i=length; i>=0; i--){
			temp = arr[i];
			arr[i] = maximum;			
			if(temp > maximum){
				maximum = temp;
			}			
		}
		for(int j=0; j <=length; j++){
			System.out.println(arr[j]);
		}
		
		
		}
		
	}

