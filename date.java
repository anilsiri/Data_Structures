package Data_Structures;

public class date {
	int dateIs;
	int month;
	int year;
	
	date(){
		dateIs = 1;
		month =2;
		year = 2000;		
	}
	
	date(int d, int m, int y){
		dateIs = d;
		month =m;
		year = y;		
	}
	
	boolean isEquals(date d){
		if(!(d instanceof date)){
			return false;
		}
	
		return (d.dateIs == dateIs) && (d.month == month) && (d.year == year);
		
	}
	
	public void main(String[] args) {
		date d1 = new date();
		date d2 = new date(1,2,1998);
		
		boolean val;
		val = d1.isEquals(d2);
		System.out.println(val);
}
}