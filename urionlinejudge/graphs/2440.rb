class UnionFind

  attr_reader :size

  def initialize n
    @parents, @size = [], n
    (1..n).each { |i| @parents[i] = i }
  end

  def union_set u, v
    unless same_set u, v
      x, y = find_set(u), find_set(v)
      @parents[y] = @parents[x]
      @size -= 1
    end
  end

  private
    def find_set u
      u == @parents[u] ? u : (@parents[u] = find_set(@parents[u]))
    end

    def same_set u, v
      find_set(u) == find_set(v)
    end
end

n, m = gets.split.map(&:to_i)
ufds = UnionFind.new n
m.times do
  u, v = gets.split.map(&:to_i)
  ufds.union_set(u, v)
end
puts ufds.size
