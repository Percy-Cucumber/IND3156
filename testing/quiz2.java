public class quiz2 {
 public static void main(String[] args) {

 int i;
 double x;

 x = 1.0/4.0;
 for ( i = 0 ; i < 33 ; i++ ) {
  System.out.format(" i=%3d,  x=%+29.23e\n", i, x);
  x = (16.0*x + 1.0)*x - 1.0;
  }
 }
}