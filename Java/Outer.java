class Outer{
	class Inner1{
		void m1(){
			System.out.println ("Inside class Inner1: executing m1()"); 
		}
	}
	static class Inner2{
		static void m2(){
			System.out.println ("Inside class Inner2: executing m2()"); 
		}
	}
	
	public static void main(String args[]){
		Outer O = new Outer();
		Outer.Inner1 i1= O.new Inner1();
		i1.m1();
		Outer.Inner2 i2= new Inner2();
		i2.m2();
		Outer.Inner2.m2();
	}
}
