#!/bin/bash
for folder in `ls`
do
  if [ ! -d $folder ]
  then
    echo $folder" is not a folder"
    continue
  fi

  cd $folder
  build.sh
  cd ..
done
