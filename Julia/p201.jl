
#cprod(A,B) = [(i,j) for i in A for j in B]
function flat(X)
    return  collect(Iterators.flatten(X))
end
index(e, X) = findall(x->x==e, X)[1]
del!(A,e) = deleteat!(A, index(e,A))

DistinctTwo(n) = Iterators.flatten(( ( (j,i) for i=j+1:n) for j=1:n))

S = [n^2 for n in 1:100]
B = [1,3,6,8,10,11]
N = Array(1:7)

println("\n\n\n\n")
function swap2(B)
    sums = Dict{Int, Array{Tuple{Int, Int}}}()
    for (i,j) in DistinctTwo(length(B))
        if haskey(sums, B[i]+B[j])
            push!(sums[B[i]+B[j]], (i,j))
        else
            sums[B[i]+B[j]] = [(i,j)]
        end
    end

    return filter!(n->length(n[2])> 1, sums)
end

function extendable(a,b)
    Y = Dict()
    for (α, β) = DistinctTwo(length(a[2])), (γ, δ) = DistinctTwo(length(b[2]))
        A = flat([a[2][α], a[2][β]])
        B = flat([b[2][γ], b[2][δ]])
        I = intersect(A, B)
        #println(I)
        if length(I) == 1
            aa = index(I[1], A)
            bb = index(I[1], B)

            ξ = [tuple(A[func(aa)], B[func2(bb)], B[func2(bb)+1]), tuple(B[func(bb)], A[func2(aa)], A[func2(aa)+1])]


            println(I[1], " ", a[2][α], a[2][β], ", ", b[2][γ], b[2][δ], " ", ai, ", ", bi)
            display(ξ)
            println(map(sum, ξ))
        end
    end
end

C=0
function extend_swap2(X)
    X = collect(X)
    Y = Dict()
    func(aa) = aa+2mod(aa,2)-1
    func2(aa) = mod(div(aa-1,2)+1, 2)*2+1
    for (ai,bi) in DistinctTwo(length(X))
        extendable(X[ai], X[bi])
    end
    return Y
end

function extend_swap(X, T)
    for a in X, b in T

        for (α, β) = DistinctTwo(length(a[2])), (γ, δ) = DistinctTwo(length(b[2]))
        end
    end
end

T = swap2(S)
#display(T)
#extend_swap2(T)
