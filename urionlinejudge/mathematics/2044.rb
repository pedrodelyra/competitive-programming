while ~(n = gets.to_i) != 0
  a = gets.split.map(&:to_i)
  sum = count = 0
  a.each do |x|
    sum += x
    count += 1 if sum % 100 == 0
  end
  puts count
end
