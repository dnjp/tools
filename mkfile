
RCPATH=/usr/local/plan9/bin/rc

targets=nine \
	a+ \
	a- \
	com \
	f+ \
	f- \
	xfmt \
	mkicon \
	wtc \
	fd \
	rif
# rg

# override like: mk bindir=/my/dir install
bindir=$home/bin/rc

MKSHELL=$PLAN9/bin/rc
install:V:
	echo MKSHELL=$MKSHELL
	echo RCPATH=$RCPATH
	for(i in $targets){
		cat $i | sed 's|/bin/rc|'^$RCPATH^'|g' > $bindir/$i
		chmod +x $bindir/$i;
	}
	go install f2b/f2b.go 

