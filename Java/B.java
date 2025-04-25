interface I1 {
	void m1();
}

interface I2 {
	void m2();
}

interface I extends I1,I2 {
	void m3();
}

/*class B implements I1,I2{
	public void m1(){
		System.out.println ("Overriden m1()");
	}
	public void m2(){
		System.out.println ("Overriden m2()");
	}
	public void m4(){
		System.out.println ("m4()");
	}
	public static void main(String args[]){
		B b1= new B();
		b1.m1();
		b1.m2();
		b1.m4();
	}
}*/

class B implements I{
	public void m1(){
		System.out.println ("Overriden m1()");
	}
	public void m2(){
		System.out.println ("Overriden m2()");
	}
	public void m3(){
		System.out.println ("Overriden m3()");
	}
	public void m4(){
		System.out.println ("m4()");
	}
	public static void main(String args[]){
		B b1= new B();
		b1.m1();
		b1.m2();
		b1.m4();
		
		I i1= new B();
		i1.m1();
		i1.m2();
	}
}
