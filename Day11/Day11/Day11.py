import numpy as np

#name = "input_small.txt"
name = "input.txt"

octopuse_map = np.zeros(shape=(10,10))

with open(name) as f:
    line_index = 0
    for line in f:
        line = line.strip('\n')
        num = list(map(int, list(line)))
        octopuse_map[line_index] = num
        line_index += 1

#print(octopuse_map)

#loop part1
num_flashes = 0
for iter in range(1000):
    #increase + 1
    print(iter)
    print(octopuse_map)

    #part2
    result = np.max(octopuse_map) == np.min(octopuse_map)
    if result and np.max(octopuse_map) == 0:
        print("found: " + str(iter))
        break

    octopuse_map = np.array([xi + 1 for xi in octopuse_map])
    lightning_map = np.zeros(octopuse_map.shape)

    while(1):
        lightnings = np.where(octopuse_map > 9)
        
        if len(lightnings[0]) == 0: break

        for x,y in zip(lightnings[0], lightnings[1]):
            #print(str(x) + " " + str(y))
            if lightning_map[x][y] != 0:
                continue
            lightning_map[x][y] = 1
            octopuse_map[x][y] = 0
            num_flashes += 1
            
            if x<9 and lightning_map[x+1][y] == 0:
                octopuse_map[x+1][y] += 1
            if x>0 and lightning_map[x-1][y] == 0:
                octopuse_map[x-1][y] += 1
            if y<9 and lightning_map[x][y+1] == 0:
                octopuse_map[x][y+1] += 1
            if y>0 and lightning_map[x][y-1] == 0:
                octopuse_map[x][y-1] += 1
            
            if x<9 and y<9 and lightning_map[x+1][y+1] == 0:
                octopuse_map[x+1][y+1] += 1
            if x>0 and y>0 and lightning_map[x-1][y-1] == 0:
                octopuse_map[x-1][y-1] += 1
            if x>0 and y<9 and lightning_map[x-1][y+1] == 0:
                octopuse_map[x-1][y+1] += 1
            if x<9 and y>0 and lightning_map[x+1][y-1] == 0:
                octopuse_map[x+1][y-1] += 1

        
print(num_flashes)

    #print(octopuse_map)

