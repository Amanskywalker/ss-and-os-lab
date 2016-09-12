# program to check the files permissions
#!/bin/bash

#echo $1
#echo $2

f1=$1
f2=$2

if [ $# -ne 2 ]
  then echo "Usages sh 3.sh <file1> <file2>" ; exit
fi

if [ ! -e $1 ]
  then echo $1."file does NOT exist" ; exit
elif [ ! -e $2 ]
  then echo $2."file does NOT exist" ; exit
fi

a=`ls -l $f1 | cut -c1-10`
b=`ls -l $f2 | cut -c1-10`

#echo $a"\n"$b;

if [ a==b ]
  then echo "Files permission "$a
else
  echo "$f1 permissions: $a \n $f2 permissions: $b"
fi
