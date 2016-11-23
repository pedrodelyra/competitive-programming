while (s = gets) and (r = gets)
  puts s.chomp.include?(r.chomp) ? "Resistente" : "Nao resistente"
end
