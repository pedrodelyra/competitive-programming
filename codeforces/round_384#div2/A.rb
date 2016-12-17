n, a, b = gets.split.map(&:to_i)
str = gets.chomp
puts str[a - 1] != str[b - 1] ? 1 : 0
