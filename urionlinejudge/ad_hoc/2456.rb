a = gets.split.map(&:to_i)
puts a == a.sort ? 'C' : (a == a.sort.reverse ? 'D' : 'N')
