import java.awt.*;
import java.awt.event.*;
class MouseProg extends Frame{
	int x,y;
	String st="Hello";
	MouseProg(){
		setSize(600,600);
		setVisible(true);
		addWindowListener (new WindowAdapter(){
			public void windowClosing(WindowEvent we){
				System.exit(0);
			}
		});
		addMouseListener (new MouseAdapter(){
			public void mouseClicked(MouseEvent me){
				x=me.getX();
				y=me.getY();
				repaint();
			}
		});
	}
	
	public void paint(Graphics g){
		g.drawString(st,x,y);
	}
	public static void main (String args[]){
		MouseProg m= new MouseProg();
	}
}
