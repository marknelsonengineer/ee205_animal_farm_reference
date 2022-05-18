#!/bin/bash

# @todo header
# @see https://alvinalexander.com/technology/gnuplot-charts-graphs-examples/

gnuplot << DONE
set terminal png size 1200,900
set output 'codeOverTime.png'

set grid
set title 'Progress of Animal Farm Source Code'
#set yrange [0:1000]
#set y2range [0:10]
set y2tics 2
set ytics nomirror
set xrange [0:16]
set xlabel 'Week'
set ylabel 'Lines of Code'
set y2label 'Lines/Test'
plot 'codeOverTime.csv' u 1:2 w lp t 'Lines of Code' axis x1y1, 'codeOverTime.csv' u 1:3 w lp t 'Individual Tests' axis x1y1, 'codeOverTime.csv' u 1:5 w lp t 'Lines/Test' axis x1y2

DONE

# chmod +x codeOverTime.sh ; ./codeOverTime.sh
