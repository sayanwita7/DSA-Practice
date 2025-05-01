class Outer{
	class Inner1{
        int n;
        public Inner1(int n){
            this.n=n;
        }
		void m1(){
			System.out.println ("Inside class Inner1: executing m1() || n= "+n); 
		}
	}
	static class Inner2{
        static int n;
        Inner2(int n){
            Inner2.n=n;
        }
		static void m2(){
			System.out.println ("Inside class Inner2: executing m2() || n= "+n); 
		}
	}
	
	public static void main(String args[]){
		Outer O = new Outer();
		Outer.Inner1 i1= O.new Inner1(10);
		i1.m1();
		Outer.Inner2 i2= new Inner2(20);
		i2.m2();
		Outer.Inner2.m2();
	}
}
