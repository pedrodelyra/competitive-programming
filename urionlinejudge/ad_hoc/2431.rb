x, y, z = gets.split.map(&:to_i).each_slice(2).to_a
possible = false
(0..1).each do |i|
  h1, b1 = x[i], x[i ^ 1]
  (0..1).each do |j|
    h2, b2 = y[j], y[j ^ 1]
    (0..1).each do |k|
      h, b = h1 + h2, [b1, b2].min
      possible = true if (h >= z[k] and b >= z[k ^ 1]) or (h1 >= z[k] and b1 >= z[k ^ 1]) or (h2 >= z[k] and b2 >= z[k ^ 1])
    end
  end
end
puts possible ? "S" : "N"
