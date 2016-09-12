#!/bin/bash

echo "Input stream : $*";

for x in "$@"
      do
              y=$x" "$y
      done
echo "reversed string : $y"
