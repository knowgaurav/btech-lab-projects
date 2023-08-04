import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class DrawShapesExample extends JFrame {
    public Color c;

    public static void main(String[] args) {
        new DrawShapesExample();
    }

    public DrawShapesExample() {
        EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                try {
                    UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
                } catch (ClassNotFoundException | InstantiationException | IllegalAccessException | UnsupportedLookAndFeelException ex) {
                    ex.printStackTrace();
                }

                JFrame frame = new JFrame("Java Practical");
                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                frame.add(new ControlPane());
                frame.pack();
                frame.setLocationRelativeTo(null);
                frame.setVisible(true);
            }
        });
    }

    public class ControlPane extends JPanel {

        private JRadioButton color;
        private JRadioButton circle;
        private JRadioButton square;
        private JRadioButton line;
        private JRadioButton exit;

        private DrawPane drawPane;

        public ControlPane() {
            setLayout(new GridBagLayout());

            ButtonGroup bg = new ButtonGroup();
            color = new JRadioButton("Color");
            circle = new JRadioButton("Circle");
            square = new JRadioButton("Square");
            line = new JRadioButton("Line");
            exit = new JRadioButton("EXIT");

            bg.add(color);
            bg.add(circle);
            bg.add(square);
            bg.add(line);
            bg.add(exit);

            GridBagConstraints gbc = new GridBagConstraints();
            gbc.gridwidth = GridBagConstraints.REMAINDER;
            gbc.weightx = 1;

            JPanel shape = new JPanel();
            final JFrame frame = new JFrame("Color Chooser");
            shape.add(color);
            shape.add(circle);
            shape.add(square);
            shape.add(line);
            shape.add(exit);
            add(shape, gbc);

            JButton draw = new JButton("Submit");
            draw.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    if(color.isSelected()){
                        c=JColorChooser.showDialog(shape,"Choose",Color.CYAN);
                    }
                    else if (circle.isSelected()) {
                        drawPane.setDrawableShape(DrawableShape.CIRCLE);
                    } else if (square.isSelected()) {
                        drawPane.setDrawableShape(DrawableShape.SQUARE);
                    }
                    else if (line.isSelected()) {
                        drawPane.setDrawableShape(DrawableShape.LINE);
                    }
                    else if (exit.isSelected()) {
                        System.exit(1);
                    }
                }
            });

            gbc.gridwidth = GridBagConstraints.REMAINDER;
            add(draw, gbc);

            drawPane = new DrawPane();

            gbc.weightx = 1;
            gbc.weighty = 1;
            gbc.fill = gbc.BOTH;
            add(drawPane, gbc);
        }

    }

    public enum DrawableShape {
        CIRCLE,
        SQUARE,
        LINE,
        EXIT
    }

    public class DrawPane extends JPanel {

        private DrawableShape drawableShape;

        public DrawPane() {
        }

        public void setDrawableShape(DrawableShape drawableShape) {
            this.drawableShape = drawableShape;
            repaint();
        }

        public DrawableShape getDrawableShape() {
            return drawableShape;
        }

        @Override
        public Dimension getPreferredSize() {
            return new Dimension(200, 200);
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            Graphics2D g2d = (Graphics2D) g.create();
            DrawableShape shape = getDrawableShape();
            if (shape != null) {
                int width = getWidth() - 20;
                int height = getHeight() - 20;
                int size = Math.min(width, height);

                int x = (getWidth() - size) / 2;
                int y = (getHeight() - size) / 2;
                if (shape == DrawableShape.CIRCLE) {
                    g2d.setColor(c);
                    g2d.fillOval(x, y, size, size);
                } else if (shape == DrawableShape.SQUARE) {
                    g2d.setColor(c);
                    g2d.fillRect(x, y, size, size);
                }
                else if (shape == DrawableShape.LINE) {
                    g2d.setColor(c);
                    g2d.setStroke(new BasicStroke(4f));
                    g2d.drawLine(30, 50, 250, 50);
                }
                else if (shape == DrawableShape.EXIT) {
                    System.exit(1);
                }
            }
            g2d.dispose();
        }

    }
}