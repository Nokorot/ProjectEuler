
using Polynomials

p = Poly([(-1)^i for i in 0:10])

OP(k, n) = polyfit(Vector(1:k), map(p, Vector(1:k)))(n)
BOP(k) = OP(k, k+1)

println(sum(BOP, 1:10))
