import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

public class firstGUI implements WindowListener, ActionListener {

    Frame f1;
    Label l1, l2, l3;
    TextField t1, t2, t3;
    Button b1, b2, b3, b4, b5, b6, b7, b8, b9, b10;

    public firstGUI() {
        f1 = new Frame("Simple Calculator JAVA GUI");

        l1=new Label("First Num");
        l1.setBounds(50,100,100,20);
        l2=new Label("Second Num");
        l2.setBounds(50,140,100,20);
        l3=new Label("Result");
        l3.setBounds(50,180,100,20);

        t1=new TextField();
        t1.setBounds(200,100,100,20);
        t2=new TextField();
        t2.setBounds(200,140,100,20);
        t3=new TextField();
        t3.setBounds(200,180,100,20);

        b1=new Button("+");
        b1.setBounds(50,250,50,20);
        b2=new Button("-");
        b2.setBounds(110,250,50,20);
        b3=new Button("*");
        b3.setBounds(170,250,50,20);
        b4=new Button("/");
        b4.setBounds(230,250,50,20);
        b5=new Button("Clear");
        b5.setBounds(290,250,50,20);
        b6=new Button("x^2");
        b6.setBounds(50,300,50,20);
        b7=new Button("x^1/2");
        b7.setBounds(110,300,50,20);
        b8=new Button("e^x");
        b8.setBounds(170,300,50,20);
        b9=new Button("log(x)");
        b9.setBounds(230,300,50,20);
        b10=new Button("ln(x)");
        b10.setBounds(290,300,50,20);

        f1.add(l1);
        f1.add(l2);
        f1.add(l3);

        f1.add(t1);
        f1.add(t2);
        f1.add(t3);

        f1.add(b1);
        f1.add(b2);
        f1.add(b3);
        f1.add(b4);
        f1.add(b5);
        f1.add(b6);
        f1.add(b7);
        f1.add(b8);
        f1.add(b9);
        f1.add(b10);

        f1.setSize(500, 500);
        f1.setLayout(null);
        f1.setVisible(true);

        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        b5.addActionListener(this);
        b6.addActionListener(this);
        b7.addActionListener(this);
        b8.addActionListener(this);
        b9.addActionListener(this);
        b10.addActionListener(this);

        f1.addWindowListener(this);

    }

    public static void main(String[] args) {
        firstGUI g1 = new firstGUI();
    }

    @Override
    public void windowOpened(WindowEvent e) {

    }

    @Override
    public void windowClosing(WindowEvent e) {
        f1.dispose();
    }

    @Override
    public void windowClosed(WindowEvent e) {

    }

    @Override
    public void windowIconified(WindowEvent e) {

    }

    @Override
    public void windowDeiconified(WindowEvent e) {

    }

    @Override
    public void windowActivated(WindowEvent e) {

    }

    @Override
    public void windowDeactivated(WindowEvent e) {

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        int n1=Integer.parseInt(t1.getText());
        int n2=Integer.parseInt(t2.getText());

        if(e.getSource()==b1)
        {
            t3.setText(String.valueOf(n1+n2));
        }

        if(e.getSource()==b2)
        {
            t3.setText(String.valueOf(n1-n2));
        }

        if(e.getSource()==b3)
        {
            t3.setText(String.valueOf(n1*n2));
        }

        if(e.getSource()==b4)
        {
            t3.setText(String.valueOf(n1/n2));
        }

        if(e.getSource()==b5)
        {
            t1.setText("0");
            t2.setText("0");
            t3.setText("0");
        }

        if(e.getSource()==b6)
        {
            t3.setText(String.valueOf(n1*n1));
        }

        if(e.getSource()==b7)
        {
            t3.setText(String.valueOf(Math.sqrt(n1)));
        }

        if(e.getSource()==b8)
        {
            t3.setText(String.valueOf(Math.exp(n1)));
        }

        if(e.getSource()==b9)
        {
            t3.setText(String.valueOf(Math.log10(n1)));
        }

        if(e.getSource()==b10)
        {
            t3.setText(String.valueOf(Math.log(n1)));
        }
    }
}
