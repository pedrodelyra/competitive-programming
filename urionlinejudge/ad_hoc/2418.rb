puts gets.split.map(&:to_f).sort[1..3].reduce(0, :+).round(1)
