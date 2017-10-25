#!/bin/bash
arr=$(ps -aux | awk '{ print $2 " " $7}' | grep Z | tr -d ' Z' )
echo "Sleeping for 60 seconds to ensure that the zombie process <defunct> is safe to reap"
sleep 60
for i in "${arr[@]}"
do
	preap $i
done
