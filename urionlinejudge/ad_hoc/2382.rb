x, y, z, r = gets.split.map(&:to_i)
puts x ** 2 + y ** 2 + z ** 2 <= 4 * r ** 2 ? "S" : "N"
