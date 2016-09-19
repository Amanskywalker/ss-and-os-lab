#Shell script that accepts file names specified as arguments and creates a shell
#script that contains this file as well as the code to recreate these files.
#Thus if the script generated by your script is executed, it would recreate the
#original files(This is same as the "bundle" script described by Brain W. Kernighan
#and Rob Pike in "The Unix Programming Environment", Prentice - Hall India).

#!/bin/bash

for x in $*
  do
echo "cat>>$x<<here
this is $x new file create
here"
  done > recreate.bash