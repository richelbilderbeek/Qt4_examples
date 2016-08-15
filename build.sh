#!/bin/bash
for folder in `ls`
do
  if [ ! -d $folder ]
  then
    echo $folder" is not a folder"
    continue
  fi

  cd $folder
  qmake-qt4
  make
  if [ $? -eq 0 ]; then
    echo OK
  else
    echo FAIL
    exit 1
  fi
  cd ..
done
