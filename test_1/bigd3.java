import java.math.BigDecimal;

public class bigd3 {
 public static void main(String[] args) {

 int i;
 BigDecimal x, nine, one, three;

 nine = new BigDecimal("9.00000");
 one = new BigDecimal("1.00000");
 three = new BigDecimal("3.00000");
 x = one.divide(three);

 for ( i = 0 ; i < 33 ; i++ ) {
  System.out.format(" i=%3d,  x=%+29.23e\n", i, x.floatValue());
  x = (((x.multiply(nine)).add(one)).multiply(x)).subtract(one);  // line 16
  }
 }
}