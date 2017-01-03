n, k = gets.split.map(&:to_i)
nums = gets.split.map(&:to_i).sort.reverse
puts n >= k ? "#{nums[k - 1]} #{nums[k - 1]}" : "-1"
