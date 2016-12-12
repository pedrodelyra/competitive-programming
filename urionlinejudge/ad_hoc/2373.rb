n, t = gets.to_i, 0
n.times do
  x, y = gets.split.map(&:to_i)
  t += y if x > y
end
puts t
