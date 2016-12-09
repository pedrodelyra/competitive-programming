n = gets.to_i
a = gets.split.map(&:to_i).sort
sum, ans = 0, 0
a.each_with_index do |x, i|
  ans = i + 1 if x < sum
  sum += x
end
puts ans >= 3 ? ans : 0
