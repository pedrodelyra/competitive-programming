x, y, = gets.split.map(&:to_i)
puts (0 <= x and x <= 432 and 0 <= y and y <= 468) ? "dentro" : "fora"
