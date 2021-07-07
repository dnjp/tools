package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strings"
)

func usage() {
	fmt.Printf("\nf2b converts a file to an array of bytes\n\n")
	fmt.Printf("f2b <file>\n\n")
}

func main() {
	if len(os.Args) != 2 {
		usage()
		fmt.Fprintf(os.Stderr, "error: must provide file argument\n")
		return
	}
	b, err := ioutil.ReadFile(string(os.Args[1]))
	if err != nil {
		panic(err)
	}
	barr := fmt.Sprintf("%+v\n", b)
	barr = strings.ReplaceAll(barr, " ", ", ")
	barr = strings.ReplaceAll(barr, "[", "")
	barr = strings.ReplaceAll(barr, "]", "")
	fmt.Println(barr)
}
