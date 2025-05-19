class MyThread1 implements Runnable
{
public void run()
{
for(int i=1;i<=20;i++)
{
System.out.println(Thread.currentThread().getName()+i);
try
{
Thread.sleep(1000);
}
catch(InterruptedException ie)
{
System.out.println(ie);
}
}
}
public static void main(String args[])
{
MyThread1 mt=new MyThread1();
Thread t1=new Thread(mt);
Thread t2=new Thread(mt);
Thread t3=new Thread(mt);
t1.setName("RED");
t2.setName("BLUE");
t3.setName("GREEN");
t1.start();
t2.start();
t3.start();
}
}
