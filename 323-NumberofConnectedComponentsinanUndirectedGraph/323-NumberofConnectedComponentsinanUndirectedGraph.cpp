def countComponents(self, n, edges):

    from collections import defaultdict
    adjacency_list = defaultdict(list)

    for cNode, nNode in edges:
        adjacency_list[cNode].append(nNode)
        adjacency_list[nNode].append(cNode)

    seen = {}
          
    i = 0

    keys = list(adjacency_list.keys())

    while keys:  
        i += 1
        stack = [keys[0]]
        
        while stack:
            parent = stack.pop()              

            for child in adjacency_list[parent]:                    
                if child in seen:
                    continue 
                seen[child] = True
                stack.append(child) 
                keys.remove(child)

    return i