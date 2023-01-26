#!/bin/sh

while :
do
	solidwmc status $(date '+%d %b (%a) %I:%M%P')
	sleep 10
done
