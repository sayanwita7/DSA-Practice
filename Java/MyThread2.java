class MyThread2 implements Runnable
{
public void run()
{
for(int i=1;i<=20;i++)
{
System.out.println(Thread.currentThread().getName()+i);
Thread.yield();
}
}
public static void main(String args[])
{
MyThread2 mt=new MyThread2();
Thread t1=new Thread(mt);
Thread t2=new Thread(mt);
Thread t3=new Thread(mt);
t1.setName("RED");
t2.setName("BLUE");
t3.setName("GREEN");
t1.setPriority(8);
t2.setPriority(3);
t3.setPriority(8);
t1.start();
t2.start();
t3.start();
}
}
