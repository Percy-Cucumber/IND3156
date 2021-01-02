/* Change RETURN and TEXT COLOUR Command(s) */
/* Define: xmin, xmax, ymin, ymax, and nPoints after ./a.out */

//import & define
import java.util.Random;

public class montecarlo {
 public static void main(String[] args) {

  double xmin, xmax, ymin, ymax, answer;
  int total;
  Random r = new Random(System.currentTimeMillis());
  func f = new func();

  xmin=0.; xmax=0.; ymin=0.; ymax=0.; total=0;

  banner.output(f);
  if ( args.length == 5 ) {
        xmin = Double.parseDouble(args[0]);
        xmax = Double.parseDouble(args[1]);
        ymin = Double.parseDouble(args[2]);
        ymax = Double.parseDouble(args[3]);
        total = Integer.parseInt(args[4]);
  } else {
         System.exit(1);
  }
  answer = monte.area(f,xmin,xmax,ymin,ymax,total,r);
  System.out.format("\n         %+18.12f\n\n",f.display(answer));
 }
}



/* ---- RETURN ---- */

class func {
 static double f(double x) {
//  return Math.exp(-x*x);
  return Math.sqrt(1.0 - x*x);
//  return x*x*x;
 }

 static String label() {
//  return " exp(-x*x) ";
  return "sqrt(1-x^2)";
//  return "    x^3    ";
 }

 static double display(double x) {
//  return x*x;
  return 4.0*x;
//  return x;
 }
}



//code
class monte {
        static double area(func g, double xMin, double xMax, double yMin, double yMax, int nPoints, Random r) {
         int i, counter, inside, outside;
         double x, y;

         counter = 0;
         inside = 0;
         outside = 0;
         for ( i=0; i<nPoints; i++ ) {
          x = xMin + (xMax-xMin)*r.nextDouble();
          y = yMin + (yMax-yMin)*r.nextDouble();
          if ( 0.0 < y && y <= g.f(x) ) {
                counter++;
                inside++;
          } else if ( g.f(x) <= y && y < 0.0 ) {
                counter--;
                inside++;
          } else {
                outside++;
          }
         }
         if ( inside + outside != nPoints ) {
          System.out.println("darts don't add up");
         }
         return (double)counter/(double)nPoints*(xMax-xMin)*(yMax-yMin);
        }
}

//print & banner
class banner {
 static void output(func c) {
  int RESET =   0;
  int BRIGHT =  1;
  int DIM =     2;
  int UNDERLINE=3;
  int BLINK =   4;
  int REVERSE = 7;
  int HIDDEN =  8;
  int BLACK =   0;
  int RED =     1;
  int GREEN =   2;
  int YELLOW =  3;
  int BLUE =    4;
  int MAGENTA = 5;
  int CYAN =    6;
  int WHITE =   7;

  textColor(BRIGHT,RED,BLACK);
  System.out.println("");
  System.out.println(" ###############################################");
   System.out.format(" #            ");
  textColor(BRIGHT,MAGENTA,BLACK);
                         System.out.format("numerical integrator");
  textColor(BRIGHT,RED,BLACK);
                                              System.out.format("             #\n");
   System.out.format(" #                ");
   textColor(BRIGHT,GREEN,BLACK);
                              System.out.format("%s",c.label());
   textColor(RESET,WHITE,BLACK);
   textColor(BRIGHT,RED,BLACK);
                                         System.out.format("                  #\n");
   System.out.format(" # ");
   textColor(DIM,RED,BLACK);
      System.out.format("usage: java mci xMin xMax yMin yMax nPoints");
   textColor(RESET,WHITE,BLACK);
   textColor(BRIGHT,RED,BLACK);
                                                               System.out.format(" #\n");
  System.out.println(" ###############################################");
  System.out.println("");



/* ---- TEXT COLOUR ---- */

//  textColor(RESET,RESET,RESET);
  textColor(RESET,WHITE,BLACK);
 }



 //print & end
 static void textColor(int attr, int fg, int bg) {
  System.out.format("%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
 }
}



/* original code template stolen from Ian Hoffman */
/* help recieved from Natalie & Julian */