#!/bin/sh

cd files/usr/lib
files="$(find . -type l | sed 's@\./@@')"

cur="$(file libEGL.so | awk '{print $NF}')"
echo "$cur" | grep -q 'r121.so$' && re="_r125.so"
echo "$cur" | grep -q 'r125.so$' && re="_r121.so"

for i in $files; do
	ln -svf "$(echo $i | sed "s/\.so/$re/")" $i
done
