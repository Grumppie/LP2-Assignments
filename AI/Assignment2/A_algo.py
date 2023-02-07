def a_staralgo(start_node, stop_node):
    open_set = set(start_node)
    close_set = set()

    g = {}  # store distance from starting node
    parents = {}         # parents contains an adjacency map of all nodes

    g[start_node] = 0

    # start_node is root node i.e it has no parent nodes
    # so start_node is set to its own parent node
    parents[start_node] = start_node
    while len(open_set) > 0:
        n = None
        # node with lowest f() is found
        for v in open_set:
            if n == None or g[v] + heuristic(v) < g[n] + heuristic(n):
                n = v
            if n == stop_node or Graph_nodes[n] == None:
                pass

            else:
                for (m, weight) in get_neighbors(n):
                    # nodes 'm' not in first and last set are added to first
                    # n is set its parent
                    if m not in open_set and m not in closed_set:
                        open_set.add(m)
                        parents[m] = n
                        g[m] = g[n] + weight

                    else:
                        if g[m] > g[n] + weight:
                        #update g(m)
                            g[m] = g[n] + weight
                        #change parent of m to n
                            parents[m] = n
                        #if m in closed set,remove and add to open
                        if m in closed_set:
                            closed_set.remove(m)
                            open_set.add(m)
