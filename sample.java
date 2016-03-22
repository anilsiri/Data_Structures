package Data_Structures;


//to compress a string. -- not effecient code. fixed it with hacks :(
public class sample {

	static String compress(String str){
		int i=0;
		int j=1;
		int m=0;
		char aChar;
		char bChar='a';
		int count=1;
		StringBuilder finalS = new StringBuilder();
		int length = str.length() - 1;
System.out.println("length is " + length);
		
		while(i <= length){
			aChar = str.charAt(i);
			//System.out.println("j is " + j);
			if(j<=length){
			bChar = str.charAt(j);
			}
			//System.out.println(bChar);
			
			while(aChar == bChar && j<=length){
				count++;
				j++;
				if(j <=length){
				bChar = str.charAt(j);
				}
			}
			
		 System.out.println(aChar);
          finalS.insert(m, aChar);
          m++;
          
          if(count!=1){
          finalS.insert(m, count);
          count =1;
          m++;
          }
			i = j;
			j++;
			System.out.println("i is " + i);
			System.out.println("j is " + j);
			System.out.println("length is " + length);
		}	
		
		String news = new String();
		news =  finalS.toString();
		return news;
	}
	
	
	
	public static void main(String[] args) {
		String stringis = new String();
		stringis = "aabbcccdddmeeh";
		String is = new String();
		is = compress(stringis);
		System.out.println(is);
}

}
