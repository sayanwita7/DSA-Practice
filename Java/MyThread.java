class MyThread implements Runnable{
	public void run(){
		for (int i=1; i<=20; i++){
			System.out.println(Thread.currentThread().getName()+" "+ i);
		}
	}
	
	public static void main(String args[]){
		MyThread mt= new MyThread();
		Thread t1 = new Thread(mt);
		Thread t2 = new Thread(mt);
		Thread t3 = new Thread(mt);
		t1.setName("RED");
		t2.setName("BLUE");
		t3.setName("GREEN");
		t1.start();
		t2.start();
		t3.start();
	}
}
/* 
RED 1
RED 2
RED 3
RED 4
RED 5
GREEN 1
GREEN 2
GREEN 3
GREEN 4
GREEN 5
BLUE 1
RED 6
RED 7
RED 8
RED 9
RED 10
RED 11
RED 12
RED 13
GREEN 6
GREEN 7
GREEN 8
GREEN 9
GREEN 10
BLUE 2
BLUE 3
BLUE 4
BLUE 5
BLUE 6
BLUE 7
BLUE 8
BLUE 9
BLUE 10
BLUE 11
RED 14
RED 15
RED 16
RED 17
GREEN 11
BLUE 12
BLUE 13
BLUE 14
BLUE 15
BLUE 16
BLUE 17
BLUE 18
BLUE 19
RED 18
RED 19
RED 20
GREEN 12
BLUE 20
GREEN 13
GREEN 14
GREEN 15
GREEN 16
GREEN 17
GREEN 18
GREEN 19
GREEN 20

*/