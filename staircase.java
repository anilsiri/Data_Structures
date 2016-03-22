package Data_Structures;

public class staircase {

	static void printstaircase(int n){
		
		for(int i=1; i <=n; i++){
			for(int k=1; k<=(n-i); k++){
				System.out.print(" ");
		}
		
			for(int m=(n-i+1); m<=n; m++){
				System.out.print("#");
			}
			System.out.println(" ");
		}
		
	}

	public static void main(String[] args) {
		int n;
		n = 6;
		printstaircase(n);

	}

}
