#!/bin/bash

# @todo header
# @see https://alvinalexander.com/technology/gnuplot-charts-graphs-examples/

gnuplot << DONE
set terminal png size 1200,900
set output 'codeOverTime.png'

set grid
set title 'Code Over Time'
set yrange [50:160]
set xlabel 'time (military)'
set label 'finished walk' at 15, 140
unset label
set label 'finished walk' at 15, 105
plot 'codeOverTime.csv' u 1:2 w lp t 'systolic', 'codeOverTime.csv' u 1:3 w lp t 'diastolic', 'codeOverTime.csv' u 1:4 w lp t 'heartrate'

DONE
