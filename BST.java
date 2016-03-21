package Data_Structures;

public class BST {
	static Node root;
	
	static void insert(int data){
	root = insertRec(root, data);
	}
	
	static Node insertRec(Node newNode, int data){
		
		if(newNode == null){
			newNode = new Node(data);		
			return newNode;
		}
		
		if(data < newNode.item){
			newNode.left = insertRec(newNode.left, data);
		}
		else if(data > newNode.item){
			newNode.right = insertRec(newNode.right, data);
		}
		return newNode;
	}
	
	
		
	
	//to check if a given sum exists in a given BST ---- incomplete!!!
	static boolean checkSum(Node some, int key){
		Node right = some;
		Node left = some;
		
		while(true){
			while(right != null && left != null){
				if((right.item + left.item) == key)
				{
					return true;
				}
				else if((right.item + left.item) > key){	
				}				
			}			
		}
		}
	
	
	
	
	
	static void inorder(Node some){
		if(some==null){
			return;
		}
		//System.out.println(root.item);
		inorder(some.left);
		System.out.println(some.item);
		inorder(some.right);		
	}
	
	//to check if a binary tree is a binary tree is a binary search tree
	static boolean isBST(Node nodeIs){
		return isBSTutil(nodeIs, Integer.MAX_VALUE, Integer.MIN_VALUE);
	}
	
	static boolean isBSTutil(Node nodeIs, int max, int min){
		if(nodeIs == null){
			return true;
		}
		
		if(nodeIs.item < min || nodeIs.item > max){
			return false;
		}
		
		return ((isBSTutil(nodeIs.left, nodeIs.item, min)) && (isBSTutil(nodeIs.right, max, nodeIs.item)));		
	}
	
	
	//find smallest element in the binary search tree
	static boolean findSmall(Node someNode){
		if(someNode == null){
			return true;
		}
		
		boolean val;
		val = findSmall(someNode.left);
		if(val == true){
			System.out.println("Smallest item is " + someNode.item);
		}
		return false;	
	}
	
	
	//to print numbers in a given range 
	static void printInRange(Node root, int key1, int key2){
		if(root == null)
			return;
		
		if(key1 < root.item && root.item < key2){
			System.out.println(root.item);
			printInRange(root.right, key1, key2);
			printInRange(root.left, key1, key2);			
		}
		else if (key1 > root.item){
			printInRange(root.right, key1, key2);
		}
		
		else if(key2 < root.item){
			printInRange(root.left, key1, key2);
		}		
		
	}
	
	
	
	public static void main(String[] args) {
		
		//insert nodes
		insert(20);
		insert(8);
		insert(4);
		insert(11);
		insert(12);
		insert(22);
		insert(6);
		insert(16);
		insert(1);
		
				
		//do inorder traversal
		//System.out.println("inorder traversal is ");
		//inorder(root);	
		
		//boolean isBSTree;
		///isBSTree = isBST(root);
		//System.out.println(isBSTree);
		//System.out.println(root.item);
		
		//findSmall(root);
	//	System.out.println("Nodes in range are  ");
		//printInRange(root, 15, 21 );
	}

}
