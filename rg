#!/bin/rc

ignore='\.git'

fn usage{
	echo `{basename $0} ' pattern'
}

if(~ $#1 0){
	usage
	exit 1
}

grep -n $1 `{ walk | grep -v $ignore }
