n, m = gets.split.map(&:to_i)
a = gets.split.map(&:to_i) << 42195
max_diff = 0
(1..n).each { |i| max_diff = [max_diff, a[i] - a[i - 1]].max }
puts max_diff <= m ? "S" : "N"
