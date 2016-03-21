package Data_Structures;

//program to illustrate the use of this operator
public class example {
	int x;
	int y;
	int a;
	int b;
	int c;
	
	example(){
		this(41,21);	
	}
	
	example(int x, int y){
		this(1,2,3);
		this.x = x;
		this.y = y;
	}
	
	example(int a, int b, int c){
		this.a = a;
		this.b = b;
		this.c = c;
		
	}
	
	
	
	public static void main(String args[]){
		example e = new example();
		System.out.println(e.x);
		System.out.println(e.y);
		System.out.println(e.a);
		System.out.println(e.b);
		System.out.println(e.c);
	}

}
