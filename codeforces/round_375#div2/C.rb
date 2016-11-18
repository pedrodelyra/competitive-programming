n, m  = gets.split.map(&:to_i)
array = gets.split.map(&:to_i)
count = Array.new(m + 1, 0)
label = []
array.each_with_index do |x, i|
  if x <= m and count[x] < n / m
    count[x] += 1
  else
    label[i] = true
  end
end
changes = 0
(1..m).each do |i|
  while count[i] < n / m
    j = label.index(true)
    array[j] = i
    label[j] = false
    count[i] += 1
    changes  += 1
  end
end
puts "#{n / m} #{changes}"
array.each { |x| print "#{x} " }
puts
