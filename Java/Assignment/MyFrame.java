import java.awt.*;
import java.awt.event.*;
class MyFrame extends Frame
implements ActionListener, ItemListener
{
	Label l1,l2;
	TextField t1,t2;
	TextArea ta;
	Button b1;
	List l;
	Choice ch;
	Checkbox c1, c2, c3, c4, c5;
	CheckboxGroup cbg;
	Panel p1,p2,p3;
	boolean flag;
	String st;
	MyFrame(String st){
		super(st);
		l1=new Label ("Enter Username:");
		l2=new Label ("Enter Password:");
		t1=new TextField (10);
		t2=new TextField (20);
		t2.setEchoChar('x');
		ta=new TextArea(20,20);
		b1= new Button("Submit");
		l= new List(3, true);
		l.add("Kolkata");
		l.add("Bangalore");
		l.add("New Delhi");
		l.add("Mumbai");
		l.add("Chennai");
		l.add("Huderabad");
		ch=new Choice();
		ch.add("BCA");
		ch.add("BBA");
		ch.add("MCA");
		ch.add("MBA");
		ch.add("B.Tech");
		ch.add("M.Tech");
		c1=new Checkbox("Music");
		c2=new Checkbox("Movie");
		c3=new Checkbox("Sports");
		cbg = new CheckboxGroup();
		c4=new Checkbox("Male", cbg, true);
		c5=new Checkbox("Female", cbg, false);
		p1=new Panel();
		p2=new Panel();
		p3=new Panel();
		p1.setBackground(new Color(252, 228, 236));
		p2.setBackground(new Color(243, 229, 245));
		p3.setBackground(new Color(251, 233, 231));
		p1.setLayout(new FlowLayout());
		p2.setLayout(new FlowLayout());
		p3.setLayout(new FlowLayout());
		p1.add(l1);
		p1.add(t1);
		p1.add(l2);
		p1.add(t2);
		p1.add(ta);
		p2.add(c1);
		p2.add(c2);
		p2.add(c3);
		p2.add(c4);
		p2.add(c5);
		p3.add(l);
		p3.add(ch);
		p3.add(b1);
		add(p1, BorderLayout.NORTH);
		add(p2, BorderLayout.CENTER);
		add(p3, BorderLayout.SOUTH);
		
		setSize(700,500);
		setVisible(true);
		b1.addActionListener(this);
		l.addItemListener(this);
		ch.addItemListener(this);
		addWindowListener (new WindowAdapter(){
			public void windowClosing(WindowEvent ae){
				System.exit(0);
			}
		});	
	}
	public void actionPerformed (ActionEvent ae){
		if (ae.getSource() == b1){
			if (flag==true){
				p1.setBackground(new Color(252, 178, 202));
				p2.setBackground(new Color(231, 131, 245));
				p3.setBackground(new Color(251, 188, 181));
				flag=false;
				}
			else{
				p1.setBackground(new Color(252, 77, 135));
				p2.setBackground(Color.WHITE);
				p3.setBackground(new Color(167, 151, 149));
				flag=true;
			}
		}
	}
	
	public void itemStateChanged(ItemEvent ie){
		if (ie.getSource() == ch){
			st= (String) ch.getItem(ch.getSelectedIndex());
			ta.setText(st);
		}
		else{
			st= (String) l.getItem(ch.getSelectedIndex());
			ta.append(st);
		}
	}
	public static void main (String args[]){
		MyFrame mf= new MyFrame("LOGIN FORM");
	}
}
