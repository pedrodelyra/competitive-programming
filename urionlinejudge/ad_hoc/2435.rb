i, d1, v1 = gets.split.map(&:to_i)
j, d2, v2 = gets.split.map(&:to_i)
puts d1 / v1.to_f < d2 / v2.to_f ? i : j
