
RC=nine \
	a+ \
	a- \
	com \
	f+ \
	f- \
	xfmt \
	mkicon \
	wtc \
	fd \
	rif \
	rg

# override like: mk bindir=/my/dir install
bindir=$home/bin/rc
install:
	for(i in $RC){
		cp $i $bindir
		chmod +x $bindir/$i
	}
	go install f2b/f2b.go 
