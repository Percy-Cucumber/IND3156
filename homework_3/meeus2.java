// pre-start stuff (method, packages, import decloration, etc...)
public class meeus2 {
 public static void main(String[] args) {

// variables
 int i;
 double x;

// code
 x = 1.0/3.0;
 for ( i = 0 ; i < 31 ; i++ ) {							// i++ -> increase "i" by one every time
  System.out.format(" i=%3d,  x=%+29.23e\n", i, x);		// print function
  x = (9.0*x + 1.0)*x - 1.0;
  }
 }
}



/* original code stolen from Ian Hoffman */
/* referenced https://en.wikipedia.org/wiki/Java_syntax#Program_structure */