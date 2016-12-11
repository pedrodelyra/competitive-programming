cv, ce, cs, fv, fe, fs = gets.split.map(&:to_i)
x, y = 3 * cv + ce, 3 * fv + fe
if x == y
  puts cs > fs ? "C" : (fs > cs ? "F" : "=")
else
  puts x > y ? "C" : "F"
end
