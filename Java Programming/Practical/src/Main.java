//import javax.swing.*;
//import java.applet.Applet;
//import java.awt.Graphics;
//import java.awt.Color;
//public class Main extends JFrame
//{
//    int [] pentagonX = { 260, 498, 407, 113, 22 };
//    int [] pentagonY = { 10, 183, 462, 462, 183 };
//    int [] starX = { 260, 407, 22, 498, 113, 260 };
//    int [] starY = { 10, 462, 183, 183, 462, 10 };
//    public void paint( Graphics g )
//    {
//// always call the Applet paint method first
//        super.paint( g );
//// draw light grey pentagon
//        g.setColor( Color.LIGHT_GRAY );
//        g.fillPolygon( pentagonX, pentagonY, 5 );
//// give it a black border
//        g.setColor( Color.BLACK );
//        g.drawPolygon( pentagonX, pentagonY, 5 );
//// draw a red star
//        g.setColor( Color.RED );
//        g.drawPolyline( starX, starY, 6 );
//    }
//}

import java.awt.Graphics;
        import java.awt.Polygon;
        import javax.swing.JPanel;

 class PolygonsJPanel extends JPanel
{
    // draw polygons and polylines
    public void paintComponent( Graphics g )
    {
        super.paintComponent( g ); // call superclass's paintComponent

        // draw polygon with Polygon object
        int xValues[] = { 20, 40, 50, 30, 20, 15 };
        int yValues[] = { 50, 50, 60, 80, 80, 60 };
        Polygon polygon1 = new Polygon( xValues, yValues, 6 );
        g.drawPolygon( polygon1 );

        // draw polylines with two arrays
        int xValues2[] = { 70, 90, 100, 80, 70, 65, 60 };
        int yValues2[] = { 100, 100, 110, 110, 130, 110, 90 };
        g.drawPolyline( xValues2, yValues2, 7 );

        // fill polygon with two arrays
        int xValues3[] = { 120, 140, 150, 190 };
        int yValues3[] = { 40, 70, 80, 60 };
        g.fillPolygon( xValues3, yValues3, 4 );

        // draw filled polygon with Polygon object
        Polygon polygon2 = new Polygon();
        polygon2.addPoint( 165, 135 );
        polygon2.addPoint( 175, 150 );
        polygon2.addPoint( 270, 200 );
        polygon2.addPoint( 200, 220 );
        polygon2.addPoint( 130, 180 );
        g.fillPolygon( polygon2 );
    } // end method paintComponent
}

public class Main{
    public static void main(String[] args) {
        JPanel J1 = new JPanel();
        PolygonsJPanel P1 = new PolygonsJPanel();
        J1.add(P1);
    }
}