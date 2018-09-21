set xlabel 'x'
set ylabel 'f(x) = x^3 - x^2'
set title 'Function Plot of f(x) = x^3 - x^2'
set grid
set style data lines
plot "gnuplot.dat" using 1:2 lw 3 linecolor rgb "blue"
quit
