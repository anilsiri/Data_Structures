package Data_Structures;

public class mergesort {

static int arr[] = {8,3,14,9,1,2,-1,5,6,7,4,10,130,11,18};
	
	static void merge(int l, int mid, int r){
		
		int n1 = mid -l +1;
		int n2 = r-mid;
		
		int lTemp[] = new int[n1];
		int rTemp[] = new int[n2];
		
		for(int i =0; i < n1; ++i){
			lTemp[i] = arr[l+i];	
		}
				
		for(int j = 0; j < n2; ++j){
			rTemp[j] = arr[mid+1+j];
	}
		
		int k = 0;
		int m = 0;
		int f = l;
		while(k < n1 && m< n2 ){
			if(lTemp[k] < rTemp[m]){
				arr[f] = lTemp[k];
			
				k++;
				f++;
			}
			else{
				arr[f] = rTemp[m];
			
				f++;
				m++;			
				}
			}
		
		while(k < n1){
			arr[f] = lTemp[k];
			f++;
			k++;
		}
		while(m <n2) {
			arr[f] = rTemp[m];
			f++;
			m++;
		}
		}

	static void sort(int l, int r){
		if(l >= r){
			return;
		}
			
			int mid = l+ (r-l)/2;
			
			
			sort(l, mid);
			sort(mid+1, r);
			merge(l, mid, r);
		}

	
	
	public static void main(String[] args) {
		int l =0;
		int r = arr.length -1; 
		
		sort(l,r);
		for(int i =0; i<arr.length; i++)
		System.out.println(arr[i]);
		}
	}