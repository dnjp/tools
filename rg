#!/bin/rc

ignore='\.git'

fn usage{
	echo `{basename $0} ' pattern'
}

if(~ $#1 0){
	usage
	exit 1
}

grep $1 `{ du -a ./ | grep -v $ignore | awk '{print $2}'  }
