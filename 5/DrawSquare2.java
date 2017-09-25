import java.awt.*;
import javax.swing.*;
import java.io.*;
import java.util.Scanner;

class DrawSquare2 extends JPanel {
  private int size = 150;
  private  Square[] squares;
  private int[] cornerx;
  private int[] cornery;
  private int[] sqrlength;
  private int input =0;
  
  public static void main(String[]args){
    JFrame fileFrame = new JFrame();
    fileFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    fileFrame.getContentPane().add(new DrawSquare2());
    fileFrame.setSize( 1000, 1000);
    fileFrame.setVisible(true);
  }
  public DrawSquare2(){
    Scanner scan = new Scanner(System.in);  
    
    int i=0;
    int [] red = new int[1000];
    int[] blue = new int [1000];
    int[] green = new int[1000];
    double[] scale= new double[1000];
    while(scan.hasNext()){
      scale[i] = scan.nextDouble();
      red[i] = scan.nextInt();
      green[i] = scan.nextInt();
      blue[i] = scan.nextInt();
      i++;
    }
    int total = numberSquares(i);
    cornerx = new int[total];
    cornery = new int[total];
    sqrlength = new int[total];
    squares = new Square[total];
    
    int totalSize= 0;
    int size1 = (int) scale[0]*size;
    totalSize += size1;
    for(int x =1; x< i+1; x++){
      totalSize += (int) (size1*scale[x]);
    }
    
    while(1000*.85 > totalSize){
      size++;
      totalSize = 0;
      size1 = (int) (size*scale[0]);
      totalSize = size1;
      for(int x =1; x< i+1; x++){
        totalSize += (int) (scale[x]*size1);
      }
    }
    while(1000*.85 < totalSize ){
      size--;
      
      totalSize= 0;
      size1 = (int) (scale[0]*size);
      totalSize = size1;
      for(int x =1; x< i+1; x++){
        totalSize+= (int) (scale[x]*size1);
      }
    }
    
    for(int x=0; x< i; x++){
      input++;
      if(x ==0){
        square1( scale[x], red[x], green[x], blue[x]);
      } else{
        square2(scale[x], red[x], green[x],blue[x]);
      }
    }
  }
  
  public int numberSquares(int i){
    int result =1;
    int j =1;
    for(int x = 1; x<i; x++){
      j= j*4;
      result += j;
    }
    return result;    
  }
  
  public  void square1(double scale, int red, int green, int blue){
    int ssize =(int) (size*scale);
    int middle = 500;
    int x =(int) (middle- ssize/2);
    cornerx[0] = x;
    cornery[0] =x;
    sqrlength[0] = ssize;
    Color color = new Color(red, green, blue);
    squares[0] = new Square(color, x, x, ssize);
  }
  
  public  void square2(double scale, int red, int green, int blue){
    int ssize = (int) (sqrlength[0]*scale);
    Color color = new Color(red, green, blue);
    
    int i = numberSquares(input-2);
    if(input ==2)
      i = 0;   
    int lastsquare = numberSquares(input);
    int yequal = numberSquares(input-1)-1;
    
    for(int y = yequal; y+4< lastsquare; y+=4){
      int halflength = ssize/2;
      cornerx[1+y] = cornerx[i] - halflength;
      cornerx[2+y] = cornerx[1+y] + sqrlength[i];
      cornerx[3+y] = cornerx[1+y];
      cornerx[4+y] = cornerx[2+y];
      
      cornery[y+1] = cornery[i] - halflength;
      cornery[y+2] = cornery[y+1];
      cornery[y+3] = cornery[y+1] + sqrlength[i];
      cornery[y+4] = cornery[y+3];
      
      for(int x =1; x < 5; x++){
        squares[x+y] = new Square(color, cornerx[x+y], cornery[x+y], ssize);   
        sqrlength[x+y] = ssize;
      }
      i++;
    }
  }
  
  public void paintComponent(Graphics g) {
    super.paintComponent(g);
    for(int i=0; i<squares.length; i++){
      squares[i].draw(g);
    }
  }
  
  public class Square {
    private Color color;
    private int x;
    private int y;
    private int length;
    
    public Square(Color color, int x, int y, int length){
      this.x = x;
      this.y = y;
      this.color = color;
      this.length= length;    
    }
    
    public void draw(Graphics g){
      g.setColor(color);
      g.fillRect(x, y, length, length);
    }
  }
}
