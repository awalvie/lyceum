#!/bin/bash

dash="----------------------"

echo $dash
echo "clearing out pre-built sites"
rm -r ./site/*
echo $dash

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
