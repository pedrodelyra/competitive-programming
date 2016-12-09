n, k = gets.split.map(&:to_i)
a, b = gets.split.map(&:to_i).sort, []
k.downto(0) { |i| b << a[n - i - 1] - a[k - i] }
puts b.min
