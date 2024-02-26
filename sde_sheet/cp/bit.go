package main

import (
	"fmt"
	"log"
)

func main() {
	var n int
	_, err := fmt.Scanf("%d\n", &n)
	if err != nil {
		log.Fatal(err)
	}
	ans := 0
	for i := 0; i < n; i++ {
		var operation string
		_, err := fmt.Scanf("%s\n", &operation)
		if err != nil {
			log.Fatal(err)
		}
		if operation[0] == '+' || operation[2] == '+' {
			ans++
		} else {
			ans--
		}
	}
	fmt.Println(ans)
}


https://codeforces.com/problemset/problem/282/A