n = gets.to_i
m = 0;
n.times do
  x, y, z = gets.split.map(&:to_i)
  m += 1 if x + y + z >= 2
end
puts m
