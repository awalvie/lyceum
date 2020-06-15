#!/bin/bash

dash="----------------------"

echo $dash
echo "clearing out pre-built sites"

echo $dash
rm ./docs/*.html

echo "Going into source dir"
cd src
echo $dash

echo "generating the site"
make
echo $dash

echo "executing"
./main
rm ./main
echo $dash

cd ../
