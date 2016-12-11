d = gets.to_i
puts gets.split.map(&:to_i).select { |x| x >= d }.length == 3 ? "S" : "N"
