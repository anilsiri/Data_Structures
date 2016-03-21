//program to search for lowest common ancestor

class Node{
int data;
node right;
node left;

Node(int item){
	data = item;
	right = null;
	left = null;
	}
}


class BinaryTree(){
	static Node root;
	
	
	Node find(int a, int b){
	Node a;
		a = lowcommonanc(root, a, b);
		return a;
	}
	
	
	Node lowcommonanc(Node root, int a, int b){
		
	
		if( a < root.data && b > root.data){
			return root;
		}
		
		else if(a > root.data) {
			search(root.right, a, b);
		}
		
		else if(b < root.data) {
			search(root.left, a, b);
		}
		
		else if( a == root.data || b == root.data){
		return root;	
		}
	
	}	



public static void main(String args[]) {
	BinaryTree bt = new BinaryTree;
	
	tree.root = new node(20);
	tree.root.right = new node(25);
	tree.root.left = new node(10);
	tree.root.right.right = new node(5);
	tree.root.right.left = new node(4);

	Node lca;
	lca = bt.find(7,8);
    	
	
}