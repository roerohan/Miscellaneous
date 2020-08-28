import networkx as nx

nodes = [i for i in range(16)]
values = ['H', 'S', 'C', 'N', 'C', 'N', 'H', 'H', 'N', 'C', 'N', 'H', 'C', 'H', 'N', 'C']
edges = [
    (0, 1),
    (1, 2),
    (2, 3), (2, 15),
    (3, 4),
    (4, 5), (4, 8),
    (5, 6), (5, 7),
    (8, 9),
    (9, 10), (9, 15),
    (10, 11), (10, 12),
    (12, 13), (12, 14),
    (14, 15)
]

G = nx.Graph()

G.add_nodes_from(nodes)
G.add_edges_from(edges)

nx.draw(G)