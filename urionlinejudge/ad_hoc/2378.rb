n, m = gets.split.map(&:to_i)
sum, overflow = 0, false
n.times do
  x, y = gets.split.map(&:to_i)
  sum += y
  sum -= x
  overflow = true if sum > m
end
puts overflow ? 'S' : 'N'
