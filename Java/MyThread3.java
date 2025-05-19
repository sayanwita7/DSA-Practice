class MyThread3 implements Runnable
{
public void run()
{
for(int i=1;i<=20;i++)
{
System.out.println(Thread.currentThread().getName()+i);
}
}
public static void main(String args[])
{
MyThread3 mt=new MyThread3();
Thread t1=new Thread(mt);
Thread t2=new Thread(mt);
Thread t3=new Thread(mt);
t1.setName("RED");
t2.setName("BLUE");
t3.setName("GREEN");
t1.start();
try
{
t1.join();
}
catch(InterruptedException ie)
{
System.out.println(ie);
}
t2.start();
try
{
t2.join();
}
catch(InterruptedException ie)
{
System.out.println(ie);
}
t3.start();
}
}
