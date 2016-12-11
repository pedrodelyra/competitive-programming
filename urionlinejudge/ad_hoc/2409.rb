a, b = gets.split.map(&:to_i).sort
h, w = gets.split.map(&:to_i).sort
puts (a <= h and b <= w) ? "S" : "N"
