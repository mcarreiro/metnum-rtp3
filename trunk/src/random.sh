#!/bin/sh

  for i in $(seq 2000 100 2500); do
	python image_random.py $i $i ../images/random_$i
	echo $i
	echo "vecinos"
	python image_time.py random_$i vecino >> vecinos_random
	echo "bilineal"
	python image_time.py random_$i bilineal >> bilineal_random
	echo "spline"
	python image_time.py random_$i spline >> spline_random
	echo "quality"
	python image_time.py random_$i quality >> quality_random	
  done
