#!/bin/bash
for folder in `ls -d */`
do
  cd $folder

  qmake-qt4

  if [ $? -eq 0 ]; then
    echo "OK: "$folder
  else
    echo "FAIL: "$folder
    ls
    exit 1
  fi

  make

  if [ $? -eq 0 ]; then
    echo "OK: "$folder
  else
    echo "FAIL: "$folder
    ls
    exit 1
  fi

  cd ..
done
