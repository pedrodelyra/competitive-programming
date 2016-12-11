a = gets.split.map(&:to_i)
b = gets.split.map(&:to_i)
c = gets.split.map(&:to_i)
ans = false
(0..1).each do |i|
  h1, w1 = a[i], a[i ^ 1]
  (0..1).each do |j|
    h2, w2 = b[j], b[j ^ 1]
    (0..1).each do |k|
      h3, w3 = c[k], c[k ^ 1]
      ans = true if h1 >= h2 + h3 && w1 >= [w2, w3].max
    end
  end
end
puts ans ? "S" : "N"
