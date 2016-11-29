n, k = gets.split.map(&:to_i)
names = []
n.times { names << gets.chomp }
puts names.sort[k - 1]
