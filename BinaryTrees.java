package Data_Structures;

//some functions in binary trees - inorder traversal, post order, finding height etc
//to print ancestors of a given key
public class BinaryTrees {		
	
//to find the height of the tree
static int findHeight(Node root){
	int rh, lh;
	if(root == null){
		return 0;
	}
	rh = findHeight(root.left) + 1;
	lh = findHeight(root.right) + 1;
	
	if(rh > lh) 
		return rh;
	else return lh;	
		
	}

//inorder traversal
static void inorder(Node root){
	if(root == null){
		return;
	}
	
	inorder(root.left);
	System.out.print(root.item + " ");
	inorder(root.right);
}

//post order traversal
static void postorder(Node root){
	if(root == null){
		return;
	}
	
	postorder(root.left);
	postorder(root.right);
	System.out.print(root.item + " ");
}


public static void main(String[] args) {
	int height;
	Node root = new Node(3);
	Node first = new Node(2);
	Node second = new Node(1);
	Node third = new Node(0);
	Node fourth = new Node(5);
	Node fifth = new Node(6);
	Node six = new Node(1);
	Node seven = new Node(3);
	Node eight = new Node(2);
	Node nine = new Node(1);
	Node ten = new Node(5);
	Node eleven = new Node(6);
	root.left = first;
	root.right = second;
	first.left = third;
	first.right = fourth;
	second.left = fifth;
	second.right = six;
	third.left = seven;
	third.right = eight;
	eight.right = nine;
	fifth.left = ten;
	fifth.right = eleven;	
	postorder(root);
	//	height = findHeight(root);
	//System.out.print(height);
	
}

}
