n, x = gets.split.map(&:to_i)
min = x
n.times do
  min = [min, x += gets.to_i].min
end
puts min
