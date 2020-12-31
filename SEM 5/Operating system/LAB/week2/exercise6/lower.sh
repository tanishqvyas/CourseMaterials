#!/bin/sh

for x in `ls`
  do
  if [ ! -f $x ]; then
    continue
    fi
  lc=`echo $x  | tr '[A-Z]' '[a-z]'`
  if [ $lc != $x ]; then
    mv -i $x $lc
  fi
  done