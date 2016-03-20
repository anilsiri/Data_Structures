package Data_Structures;


import java.io.*;
import java.util.*;
 
// This class represents a directed graph using adjacency list
// representation
class Graph
{
    private int V;   // No. of vertices
    private static LinkedList<Integer> adj[]; //Adjacency Lists
 
    // Constructor
    Graph(int v)
    {
        V = v;
      adj = new LinkedList[v];
        for (int i=0; i<v; ++i)
            adj[i] = new LinkedList();
    }
 
    // Function to add an edge into the graph
    void addEdge(int v,int w)
    {
        adj[v].add(w);
    }
 
  static  int recArray[] = new int[20];
    static boolean visited[] = new boolean[10];
    static int m;
    
    // To check if there exists a cycle in graph
   static boolean hasCycle(int node)
    {
    	boolean temp;
    		for(int a =0; a < m; a ++){
    			if(node == recArray[a]){
    				return true;
    			}
    		}
		
    		recArray[m] = node;
    		m++;
			visited[node] = true;
						
			Iterator<Integer> i = adj[node].listIterator();
			
			while(i.hasNext()){
				int k;
				k = i.next();
				temp = hasCycle(k);
				if(temp == true){
					return true;
				}
				if(m > 0){
					m--;	
				}
				
		}	    
			return false;
    }
    
    //Depth first search
    void dfs(int node)
    {
    	if(visited[node] == true){
			return;
		}
    		
		
			visited[node] = true;
			System.out.println(node);
			
			Iterator<Integer> i = adj[node].listIterator();
			
			while(i.hasNext()){
				int k;
				k = i.next();
				dfs(k);		
		}	    	
    }
 
    Queue<Integer> q = new LinkedList<Integer>();
    
    //Breadth first search
     void bfs(int node){
    	if(visited[node] == true){
    		return;
    	}
    	
    	visited[node] = true;
    	System.out.println(node);
    	Iterator<Integer> i = adj[node].listIterator();
    	
    	
    	while(i.hasNext()){
    		int k = i.next();
    		q.add(k);	
    	}
    	
    	int m;
    	m = q.poll();
    	bfs(m);    	
           }
    
    //to check if 2 nodes in a graph are connected
     public static boolean findPath(int node, int b){
    	 
    	if(node == b){
    		return true;
    	}
 			visited[node] = true;
 			System.out.println(node);
 			
 			Iterator<Integer> i = adj[node].listIterator();
 			
 			while(i.hasNext()){
 				int k;
 				k = i.next();
 				boolean temp;
 				if(visited[k] == false){
 				temp = findPath(k, b);		
 		if(temp == true){
 			return true;
 		}
 		}
 			}	    	
    	 return false;
     }
     
     
    
    
    // Driver method to
    public static void main(String args[])
    {
        Graph g = new Graph(4);
 
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);
        g.addEdge(1, 3);
 
        boolean path;
        path =findPath(1, 2);
        System.out.println(path);
       g.bfs(2);
       g.dfs(1);
       boolean cycle;
       cycle = hasCycle(0);
       System.out.println(cycle);
    }
}