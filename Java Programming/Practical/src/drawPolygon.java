import javax.swing.*;

public class drawPolygon extends JPanel {
    drawPolygon(){
        setSize(300, 300);
        setVisible(true);


        public void paintComponent(Graphics g) {
            g.setColor(new Color(26,80,139));
            g.fillRect(0, 0, getWidth(), getHeight());
            g.setColor(Color.WHITE);
            g.fillOval(100, 89,300,300);
            g.setColor(new Color(22,36,71));
            g.fillOval(105, 94,290,290);
            g.setColor(Color.WHITE);
            g.fillOval(237,237,15,15);


            g.setFont(g.getFont().deriveFont(Font.BOLD,18));
            g.drawString(parent.day.toUpperCase(Locale.ROOT), 290, 240);
            g.drawString(parent.date.toUpperCase(Locale.ROOT), 295, 264);

            g.setFont(g.getFont().deriveFont(Font.BOLD,32));
            for(int i=1;i<=12;i++)
                g.drawString(Integer.toString(i),240-(i/12)*11+(int)(120*Math.sin(i*Math.PI/6)),253-(int)(120*Math.cos(i*Math.PI/6)));

            double minsecdeg=(double)Math.PI/30;
            double hrdeg=(double)Math.PI/6;
            int tx,ty;
            int xpoints[]=new int[3];
            int ypoints[]=new int[3];

            //second hand
            tx=245+(int)(105*Math.sin(parent.sec*minsecdeg));
            ty=245-(int)(105*Math.cos(parent.sec*minsecdeg));
            g.drawLine(245,245,tx,ty);

            //minute hand
            tx=245+(int)(100*Math.sin(parent.min*minsecdeg));
            ty=245-(int)(100*Math.cos(parent.min*minsecdeg));
            xpoints[0]=245;
            xpoints[1]=tx+2;
            xpoints[2]=tx-2;
            ypoints[0]=245;
            ypoints[1]=ty+2;
            ypoints[2]=ty-2;
            g.fillPolygon(xpoints, ypoints,3);

            //hour hand
            tx=245+(int)(80*Math.sin(parent.hour*hrdeg+parent.min*Math.PI/360));
            ty=245-(int)(80*Math.cos(parent.hour*hrdeg+parent.min*Math.PI/360));
            xpoints[1]=tx+4;
            xpoints[2]=tx-4;
            ypoints[1]=ty-4;
            ypoints[2]=ty+4;
            g.fillPolygon(xpoints, ypoints, 3);

        }
    }

}
}
