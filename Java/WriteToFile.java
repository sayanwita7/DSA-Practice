import java.io.*;
class Student implements Serializable {
	int roll;
	String name;
	double marks;
	Student(){
		roll=0;
		name = null;
		marks=0.0;
		
	}
	Student(int roll, String name, double marks){
		this.roll=roll;
		this.name=name;
		this.marks=marks;
	}
	
	void display(){
		System.out.println ("Roll: "+roll);
		System.out.println ("Name: "+name);
		System.out.println ("Marks: "+marks);
	}
}

class WriteToFile{
	public static void main(String args[]){
		Student s[]= new Student[3];
		s[0] = new Student(1, "ABC", 99.9);
		s[1] = new Student(2, "PQR", 89.9);
		s[2] = new Student(3, "XYZ", 79.9);
		try{
			File f = new File ("Student.ser");
			FileOutputStream fos = new FileOutputStream (f);
			ObjectOutputStream oos = new ObjectOutputStream (fos);
			oos.writeObject(s);
			FileInputStream fis = new FileInputStream (f);
			ObjectInputStream ois = new ObjectInputStream (fis);
			Student[] st = (Student[]) ois.readObject();
			for (Student s1:st) 
			s1.display();
		}
		catch (Exception e){
		System.out.println(e);
		}
		
	}
}

/*
Roll: 1
Name: ABC
Marks: 99.9
Roll: 2
Name: PQR
Marks: 89.9
Roll: 3
Name: XYZ
Marks: 79.9
*/
