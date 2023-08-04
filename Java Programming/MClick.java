import java.awt.*;
import java.awt.event.*;

public class MClick extends Frame implements MouseListener {
    public static void main(String argv[]) {
        MClick s = new MClick();
    }

    MClick() {
        this.addMouseListener(this);
    }

    public void mouseClicked(MouseEvent e) {
        System.out.println(e.getWhen());
    }
}