#!/bin/bash
for folder in `ls`
do
  if [ ! -d $folder ]
  then
    echo $folder" is not a folder"
    continue
  fi

  cd $folder
  status=`./build.sh`
  echo "STATUS"
  echo $status
  echo "~STATUS"
  if [ -n "$status" ]
  then
    echo "Error in folder "$folder
    exit 1
  fi
  cd ..
done
