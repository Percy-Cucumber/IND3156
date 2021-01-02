import java.util.Random;

public class qcirc5 {
 public static void main(String[] args) {

  int i, out, total;
  double x, y;
  double pi;
  Random r;

  total = 1048576*1024;

  r = new Random(43);

  out = 0;
  for ( i=0; i < total; i++ ) {
   x = r.nextDouble();
   y = r.nextDouble();
   if ( x*x+y*y > 1 ) {
           out = out + 1;
   }
  }
  System.out.format("%n       pi = %18.16f%n%n", 4.0*(1.0-(double)out/(double)total));
 }
}