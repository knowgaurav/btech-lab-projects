import java.awt.*;
import java.awt.event.*;
public class que6 extends Frame implements MouseListener, MouseMotionListener
{
    int x, y;
    String str="";
    public que6()
    {
        addMouseListener(this);
        addMouseMotionListener(this);

        setSize(300, 300);
        setVisible(true);
    }

    public void mousePressed(MouseEvent e)
    {
        x = e.getX();
        y = e.getY();
        str = "Mouse Pressed";
        repaint();
    }
    public void mouseReleased(MouseEvent e)
    {
        x = e.getX();
        y = e.getY();
        str = "Mouse Released";
        repaint();
    }
    public void mouseClicked(MouseEvent e)
    {
        x = e.getX();
        y = e.getY();
        str = "Mouse Clicked";
        repaint();
    }
    public void mouseEntered(MouseEvent e)
    {
        x = e.getX();
        y = e.getY();
        str = "Mouse Entered";
        repaint();
    }
    public void mouseExited(MouseEvent e)
    {
        x = e.getX();
        y = e.getY();
        str = "Mouse Exited";
        repaint();
    }

    public void mouseMoved(MouseEvent e)
    {
        x = e.getX();
        y = e.getY();
        str = "Mouse Moved";
        repaint();
    }
    public void mouseDragged(MouseEvent e)
    {
        x = e.getX();
        y = e.getY();
        str = "Mouse dragged";
        repaint();
    }
    public void paint(Graphics g)
    {
        g.setFont(new Font("Monospaced", Font.BOLD, 20));
        g.fillOval(x, y, 10, 10);
        g.drawString(x + "," + y,  x+10, y -10);
        g.drawString(str, x+10, y+20);
    }
    public static void main(String []args)
    {
        new que5();
    }
}