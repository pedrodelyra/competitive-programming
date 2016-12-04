length, dist = gets.split.map(&:to_i)
kmcost, toll = gets.split.map(&:to_i)
puts toll * (length / dist) + length * kmcost
