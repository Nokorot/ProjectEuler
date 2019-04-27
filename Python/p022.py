
A = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")

def value(name):
    return sum([A.index(k)+1 for k in name]);

with open("p022_names.txt") as f:
    k = f.read().replace('"', '').split(',');
    k.sort()
    print(sum([(i+1)*value(name) for (i,name) in enumerate(k)]))
