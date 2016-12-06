n = gets.to_i
mul, div = 1, 1
n.times do
  x, cmd = gets.split
  mul *= x.to_i if cmd == '*'
  div *= x.to_i if cmd == '/'
end
puts mul / div
