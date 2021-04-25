package main

import "fmt"

func main() {
	int64 a, b
	fmt.Scanf("%d %d", &a, &b)
	fmt.Printf("%d\n", math.abs(a- b))
}
