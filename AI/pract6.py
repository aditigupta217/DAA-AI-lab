import random
import itertools

departments = ["Assembly", "Packaging", "Quality", "Storage", "Shipping"]

interaction = {
    ("Assembly", "Packaging"): 8,
    ("Assembly", "Quality"): 6,
    ("Packaging", "Quality"): 7,
    ("Storage", "Shipping"): 9,
    ("Quality", "Shipping"): 5,
}

for (a, b), v in list(interaction.items()):
    interaction[(b, a)] = v

positions = [(i, j) for i in range(3) for j in range(3)]

def calculate_cost(layout):
    cost = 0
    for (d1, d2), freq in interaction.items():
        if d1 in layout and d2 in layout:
            (x1, y1) = layout[d1]
            (x2, y2) = layout[d2]
            distance = abs(x1 - x2) + abs(y1 - y2)
            cost += freq * distance
    return cost
def random_layout():
    chosen_positions = random.sample(positions, len(departments))
    return dict(zip(departments, chosen_positions))

def get_neighbors(layout):
    neighbors = []
    deps = list(layout.keys())
    for d1, d2 in itertools.combinations(deps, 2):
        new_layout = layout.copy()
        new_layout[d1], new_layout[d2] = new_layout[d2], new_layout[d1]
        neighbors.append(new_layout)
    return neighbors

def hill_climbing():
    current = random_layout()
    current_cost = calculate_cost(current)

    while True:
        neighbors = get_neighbors(current)
        next_layout = min(neighbors, key=calculate_cost)
        next_cost = calculate_cost(next_layout)

        if next_cost >= current_cost:
            break 

        current = next_layout
        current_cost = next_cost

    return current, current_cost

best_layout, best_cost = hill_climbing()

print("Best Layout:")
for dept, pos in best_layout.items():
    print(dept, "->", pos)

print("Minimum Cost:", best_cost)