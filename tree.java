package Data_Structures;

//given a sorted array, generate a bst with minimum height
public class tree {
	static Node root;
	
	//sorted array
	static int arr[] = {1,2,3,4,5,6,7,8,9};
	
	static Node arrToBST(int array[], int min, int max){
		
		if(min > max){
			return null;
		}
		
		int mid = min + (max - min)/2;
		Node newNode = new Node(arr[mid]);
		
		newNode.right = arrToBST(array, mid+1, max);
		newNode.left = arrToBST(array, min, mid-1);
    	return newNode;
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
	
	public static void main(String[] args) {
		root=arrToBST(arr, 0, arr.length-1);
		//System.out.println(root.item);
		inorder(root);
	
	}
}
