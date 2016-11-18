n = gets.to_i
a = (1..n).map do |i|
  x, y = gets.split.map(&:to_i)
  y * Math::log(x)
end
puts a.index(a.max)
