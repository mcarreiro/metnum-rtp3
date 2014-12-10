#!/bin/sh

  for i in $(seq 100 100 2500); do
	python image_plain.py $i $i 0 0 0 ../images/plain_$i
	echo $i
	echo "vecinos"
	python image_time.py plain_$i vecino >> vecinos_plain
	echo "bilineal"
	python image_time.py plain_$i bilineal >> bilineal_plain
	echo "spline"
	python image_time.py plain_$i spline >> spline_plain
	echo "quality"
	python image_time.py plain_$i quality >> quality_plain	
  done
