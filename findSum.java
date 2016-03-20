package Data_Structures;

public class findSum {
	
	
	public static void main(String[] args) {
	//int[] arrayIs = new int[10];
	int arrayIs[] = {-7, 1, 5, 2, -4, 3, 0};
	
	int leftSum = 0;
	int rightSum = 0;
	
	for(int i=0; i< arrayIs.length ; i++){
		leftSum = leftSum + arrayIs[i];
	}
	
	for(int i =0; i< arrayIs.length; i++){
		if(rightSum == leftSum){
			System.out.println("position is " + i);
		}
		
		rightSum = rightSum + arrayIs[i];
		leftSum = leftSum - arrayIs[i];		
	}

	}
}
