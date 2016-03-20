package Data_Structures;

import java.util.LinkedList;
import java.util.ListIterator;

//given a tree, generate a linked list for each level
public class treetoLL {
	Node root = new Node(5);
	int treeHeight;
	LinkedList<Integer> ll[];
	
	void generateLL(Node node, int height){
		if(node == null){
			return;
		}
		
		if(height > treeHeight){
			treeHeight++;
			ll[height] = new LinkedList<Integer>();
			ll[height].add(node.item);
		}
		else{
			ll[height].add(node.item);			
		}
		
		generateLL(node.left, height+1);
		generateLL(node.right, height+1);
	}
	
	
	void printHeight(int n){
		System.out.println("Printing list for height "+ n);
		ListIterator<Integer> listIterator = ll[n].listIterator();
		while(listIterator.hasNext()){
			System.out.println(listIterator.next());
		}
	}
	
	public  void main(String[] args) {	
		root.left = new Node(3);
		root.right = new Node(7);
		root.left.left = new Node(2);
		root.left.right = new Node(4);
		root.left.left.left = new Node(1);
		root.right.right = new Node(8);
		root.right.left = new Node(6);
		root.right.right = new Node(9);
		generateLL(root,1);
		
		for(int i=1; i<=treeHeight; i++){
			printHeight(i);	
		}
	}
}
