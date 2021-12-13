import copy as cp

filename = "input.txt"

lines=[]
with open(filename) as file:
    lines = file.readlines()

graph = {}
for x in lines:
    line_split = x.strip('\n').split('-')
    if line_split[0] in graph:
        graph[line_split[0]].append(line_split[1])
    else:
        graph[line_split[0]] = [line_split[1]]

    if line_split[1] in graph:
        graph[line_split[1]].append(line_split[0])
    else:
        graph[line_split[1]] = [line_split[0]]

print(graph)
node = "start"
visited = ["start"]
final = []
print("-------------------------------")
def SearchAllPaths(graph, node, visited, twice=True):
    #print(node)
    if node == "end":
        #print(visited)
        final.append(list(visited))
        return

    for neighbour in list(graph[node]):
        #print(graph[node])
        if (((neighbour not in visited) or (twice==False) or (neighbour.isupper())) and (neighbour != "start")): 

            if ((neighbour in visited and not neighbour.isupper()) or twice==True):
                new_twice = True
            else:
                new_twice = False
            new_visited = list(visited)
            new_visited.append(neighbour)
            SearchAllPaths(graph, neighbour, new_visited, new_twice)

#SearchAllPaths(graph, node, visited)
SearchAllPaths(graph, node, visited, False)

print(len(final))



#for x in final:
#    print(x)
#    pass

    
    
