require 'set'
str = gets.chomp
set = Set.new
str.length.times do
  set.add str
  str = (str.chars[1..-1] << str.chars[0]).join
end
puts set.size
