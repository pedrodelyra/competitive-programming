p1, c1, p2, c2 = gets.split.map(&:to_i)
puts (p2 * c2 - p1 * c1) / [(p2 * c2 - p1 * c1).abs, 1].max
