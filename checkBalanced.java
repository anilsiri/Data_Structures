package Data_Structures;

public class checkBalanced {
	
	static Node root = new Node(5); 
	
	
	static void check(Node node){
		int height;
		height = check_balanced(node);
		//System.out.println(height);
	}

	static int check_balanced(Node node){
		if(node == null){
			return 1;
		}
		System.out.println("root is " +node.item);
		
		int lh = check_balanced(node.left);
		System.out.println("lh is " +lh);
		
		int rh = check_balanced(node.right);
		System.out.println("rh is " +rh);
		
		if(Math.abs(lh - rh) > 1){
			System.out.println("Not balanced");
		}
		if(lh > rh){
			return lh+1;
		}
		
		else{
			return rh+1;
		}
		
	}
	
	public static void main(String[] args) {	
	
		root.left = new Node(3);
		root.right = new Node(7);
		root.left.left = new Node(2);
		root.left.right = new Node(4);
		root.left.left.left = new Node(1);
		root.right.right = new Node(8);
		root.right.left = new Node(6);
		root.right.right.right = new Node(9);
		check(root);
}
}
