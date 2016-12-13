puts gets.split.map { |s| s.chars.select.with_index { |c, i| i.odd? }.join }.join(" ")
