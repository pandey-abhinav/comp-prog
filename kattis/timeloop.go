package main

import "fmt"

func main() {
	n := 0
	fmt.Scanf("%d", &n)
	for i := 1; i <= n; i++ {
		fmt.Printf("%d Abracadabra\n", i)
	}
}
