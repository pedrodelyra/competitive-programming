while (n = gets.to_i) != 0
  a, b = (1..n).to_a, []
  (b << a.shift) and a.rotate! until a.size == 1
  print "Discarded cards: "
  b.each_with_index { |x, i| print((", " if i > 0), "#{x}") }
  puts "\nRemaining card: #{a.first}"
end
