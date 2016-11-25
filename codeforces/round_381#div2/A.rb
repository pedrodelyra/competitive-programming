n, a, b, c = gets.split.map(&:to_i)
puts case n % 4
when 1
  [3 * a, a + b, c].min
when 2
  [2 * a, b, 2 * c].min
when 3
  [a, b + c, 3 * c].min
else
  0
end
