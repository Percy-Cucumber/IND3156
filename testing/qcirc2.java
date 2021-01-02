import java.util.Random;

public class qcirc2 {
 public static void main(String[] args) {

  int i, out, total;
  double x, y;
  double pi;
  Random r;

  total = 1048576*1024;

  r = new Random(42);

  out = 0;
  for ( i=0; i < total; i++ ) {
   x = r.nextDouble();
   y = r.nextDouble();
   if (Math.pow(x,2)+Math.pow(y,2) > 1 ) {
           out = out + 1;
   }
  }
  System.out.format("%n       pi = %18.16f%n%n", 4.0*(1.0-(double)out/(double)total));
 }
}