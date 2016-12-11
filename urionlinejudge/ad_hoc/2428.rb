a = gets.split.map(&:to_i)
ans = false
a.permutation.to_a.each do |s|
  x, w, y, z = s
  ans = true if x * z == w * y
end
puts ans ? "S" : "N"
