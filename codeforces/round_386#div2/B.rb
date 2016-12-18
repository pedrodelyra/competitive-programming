n = gets.to_i
s = gets.chomp.reverse
x, y = "", ""
s.chars.each_with_index do |c, i|
  if i % 2 == 0
    x << c
  else
    y << c
  end
end
puts y + x.reverse
