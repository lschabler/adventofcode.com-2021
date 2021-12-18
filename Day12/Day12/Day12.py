input_file = 'input_small.txt'

with open(input_file) as f:
    testsite_array=f.readlines()

graph = {}

for line in testsite_array:
    subs = line.strip('\n').split('-')
    node1 = subs[0]
    node2 = subs[1]

    if node1 in graph:
        graph[node1].append(node2)
    else:
        graph[node1] = [node2]

    if node2 in graph:
        graph[node2].append(node1)
    else:
        graph[node2] = [node1]
    
    pass

print(graph)

visited = []
queue = []

def search(visited, graph, node):
    visited.append(node)
    queue.append(node)
    
    while queue:
        m = queue.pop(0)
        print(m, end = " ")

        for neighbour in graph[m]:
            if (neighbour not in visited) or neighbour.isupper():
                visited.append(neighbour)
                queue.append(neighbour)
                pass
    pass

search(visited, graph, "start")
print(visited)