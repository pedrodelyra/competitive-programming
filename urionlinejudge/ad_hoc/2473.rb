a = gets.split.map(&:to_i)
b = gets.split.map(&:to_i)
hits = 6 - (b - a).size
puts case hits
  when 0..2
    "azar"
  when 3
    "terno"
  when 4
    "quadra"
  when 5
    "quina"
  when 6
    "sena"
end
