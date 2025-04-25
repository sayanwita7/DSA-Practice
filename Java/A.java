class A
{
       void m1()
       {
               System.out.println("Inside class A, executing m1()");
        }
        public static void main(String args[])
        {
                A a1=new A()
                {
                         void m1()
                         {
                                 System.out.println("Inside Anonymous class,executing overriden m1() ");
                                 //m2();
                          }
                          /*void m2(){
                                 System.out.println("In m2");}*/
                 };
                 a1.m1();
                 A a2=new A();
                 a2.m1();
          }
}
                          
