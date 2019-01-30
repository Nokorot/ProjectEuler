using Plots

println()

p = plot()

I = 1;
function fun(line)
    X = map(x->parse(Int64, x), split(line, ','))
    ⋅(i,j) = X[i]*X[j] + X[i+1]*X[j+1]
    ang(i,j) = acos(⋅(i,j) / (sqrt(X[i]^2 + X[i+1]^2)sqrt(X[j]^2 + X[j+1]^2)))

    angs = [ang(1,3),ang(1,5),ang(3,5)]
    ss = sum(angs)

    if any(map(abs,(angs .- pi)) .≤ 1e-2)
        #println(I, " ", ss - 2*pi, " ", abs(ss - 2*pi) ≤ 1e-16, map(abs,(angs .- pi)))
    end
    if 1e-16 ≤ abs(ss - 2*pi) ≤ 1e-12
        println(I, " ", ss - 2*pi, " ", abs(ss - 2*pi) ≤ 1e-16, map(abs,(angs .- pi)))
    end
    if I == 839
        println(ss - 2*pi)
        plot!(p, [X[i] for i in [1, 3, 5, 1]], [X[i+1] for i in [1, 3, 5, 1]])
    end
    global I += 1;
    #return X
    return abs(ss - 2*pi) ≤ 1e-13
end
triangles = map(fun, eachline(open("p102_triangles.txt")))

println(count(triangles))

scatter!(p, [0],[0])
p
