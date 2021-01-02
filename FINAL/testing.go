//start
package main

//import
import (
	"fmt"
)

//function
func main() {
	i := 7
	inc(&i)
	fmt.Println(i)
}

func inc(x *int) {
	*x++
}

//end
