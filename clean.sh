#!/bin/bash
for folder in `ls -d */`
do
  cd $folder
  rm *.o
  rm Makefile
  cd ..
done
