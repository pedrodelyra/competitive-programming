char, words = gets.chomp, gets.split
occurrences = words.reduce(0) { |sum, s| sum += [s.count(char), 1].min }
puts (100 * occurrences / words.length.to_f).round(1)
