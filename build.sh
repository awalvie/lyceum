#!/bin/bash -x

rm -rf go-blender
git clone https://github.com/awalvie/go-blender
cd go-blender && make build && cd ..
mv go-blender/go-blender ./blender

if [[ -e ./build ]];
	then rm -r ./build
fi

mkdir build
./blender build ./
