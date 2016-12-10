a = gets.split.map(&:to_i).tap(&:pop)
puts a.max
