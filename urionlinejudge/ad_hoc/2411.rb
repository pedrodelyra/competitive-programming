def hole? x, y
  (x < 0 or x > 7 or y < 0 or y > 7) or (x == 1 and y == 3) or (x == 2 and y == 3) or (x == 2 and y == 5) or (x == 5 and y == 4)
end

n = gets.to_i
a = gets.split.map(&:to_i)
moves = [{ x:  1, y:  2 }, { x:  2, y:  1}, { x:  2, y: -1}, { x:  1, y: -2},
         { x: -1, y: -2 }, { x: -2, y: -1}, { x: -2, y:  1}, { x: -1, y:  2}]
x, y, k = 4, 3, 0
a.each do |i|
  break if hole? x, y
  x += moves[i - 1][:x]
  y += moves[i - 1][:y]
  k += 1
end
puts k
