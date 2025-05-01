import java.io.*;

class inputUser implements Serializable {
    String name;
	inputUser(String name){
		this.name=name;
	}
    void display(){
		System.out.println ("Given Input: "+ name);
	}
}

class WriteToFile{
    
	public static void main(String args[]){
		try{
            BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
            
            
			File f = new File ("Info.ser");
			FileOutputStream fos = new FileOutputStream (f);
            ObjectOutputStream oos = new ObjectOutputStream (fos);

            System.out.println ("Enter input: ");
            String st=br.readLine();
            while(st.length()!=0){
                inputUser s = new inputUser(st);
                oos.writeObject(s);
                System.out.println ("Enter input: ");
                st=br.readLine();
            }
            System.out.println("Execution Completed!");
			
			FileInputStream fis = new FileInputStream (f);
			ObjectInputStream ois = new ObjectInputStream (fis);
			inputUser str = (inputUser) ois.readObject();
			while (true){
                try {
                    str.display();
                    str = (inputUser) ois.readObject();
                } catch (EOFException e) {
                    break;
                }
            }
		}
		catch (Exception e){
		System.out.println(e);
		}
		
	}
}