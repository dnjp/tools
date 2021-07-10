
# override like: mk bindir=/my/dir install
bindir=$home/bin/rc
install:
	cp ./nine $bindir
	cp ./a+ $bindir
	cp ./a- $bindir
	cp ./com $bindir
	cp ./f+ $bindir
	cp ./f- $bindir
	cp ./xfmt $bindir
	cp ./mkicon $bindir
	cp ./wtc $bindir
	cp ./fd $bindir
	go install f2b/f2b.go 


