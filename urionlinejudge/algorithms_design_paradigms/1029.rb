calls, fib = [0, 0], [0, 1]
(2...40).each do |i|
  fib[i] = fib[i - 1] + fib[i - 2]
  calls[i] = calls[i - 1] + calls[i - 2] + 2
end
gets.to_i.times do
  i = gets.to_i
  puts "fib(#{i}) = #{calls[i]} calls = #{fib[i]}"
end
