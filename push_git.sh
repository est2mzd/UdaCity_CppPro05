#!/bin/bash
if [ $# = 0 ]; then
   comments="update modifying files"
else
   comments="$1"
fi

#git add .
git add -u
git commit -m "$comments"
git push -u origin master

