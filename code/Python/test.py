import numpy as np

# Parameters for the ACO algorithm
n_ants = 5
n_cities = 5
pheromone_evaporation_coefficient = 0.5
pheromone_intensity = 0.037
alpha = 1  # Pheromone importance
beta = 2.5  # Distance priority
Q = 1  # Constant

# Distance matrix for the cities
distance_matrix = np.array([
    [0, 18, 22, 45, 55],
    [18, 0, 20, 38, 50],
    [22, 20, 0, 25, 42],
    [45, 38, 25, 0, 18],
    [55, 50, 42, 18, 0]
])

# Inverse of the distance matrix to represent the heuristic desirability
heuristic_info = 1 / (distance_matrix + np.diag([np.inf] * n_cities))

# Pheromone matrix initialization
pheromone_matrix = np.ones((n_cities, n_cities)) * pheromone_intensity


# Function to calculate the next city to visit
def calculate_transition_probabilities(pheromone_matrix, heuristic_info, alpha, beta, visited):
    pheromone_influence = pheromone_matrix ** alpha
    heuristic_influence = heuristic_info ** beta

    # Create a boolean array from the visited set
    visited_mask = np.array([city in visited for city in range(n_cities)])

    # Set the probabilities for visited cities to 0
    pheromone_influence[visited_mask, :] = 0
    heuristic_influence[visited_mask, :] = 0

    product_matrix = np.multiply(pheromone_influence, heuristic_influence)
    row_sums = product_matrix.sum(axis=1, keepdims=True)
    probability_matrix = np.divide(product_matrix, row_sums, out=np.zeros_like(product_matrix), where=row_sums!=0)

    return probability_matrix

# Function to simulate the path of a single ant
def simulate_ant(pheromone_matrix, heuristic_info, alpha, beta, start_city):
    path = [start_city]
    visited = set(path)
    current_city = start_city

    while len(path) < n_cities:
        probabilities = calculate_transition_probabilities(
            pheromone_matrix, heuristic_info, alpha, beta, visited
        )

        # Normalize the probabilities
        prob_sum = probabilities[current_city].sum()
        if prob_sum > 0:
            normalized_probabilities = probabilities[current_city] / prob_sum
        else:
            # Handle case where all cities are visited or probabilities sum to 0
            normalized_probabilities = np.zeros(n_cities)
            normalized_probabilities[list(set(range(n_cities)) - visited)] = 1 / (n_cities - len(visited))

        next_city = np.random.choice(n_cities, p=normalized_probabilities)
        path.append(next_city)
        visited.add(next_city)
        current_city = next_city

    # Return to the start city
    path.append(start_city)
    return path


# Run the ACO algorithm
for step in range(1):
    # List to hold the paths of all ants
    all_paths = []
    for ant in range(n_ants):
        start_city = np.random.randint(n_cities)
        path = simulate_ant(pheromone_matrix, heuristic_info, alpha, beta, start_city)
        all_paths.append(path)
        print(f"Ant {ant + 1} path: {path}")

    # Evaluate the paths
    path_lengths = [sum(distance_matrix[path[i - 1], path[i]] for i in range(1, len(path))) for path in all_paths]
    print(f"Path lengths: {path_lengths}")

    # Update pheromones
    for path, length in zip(all_paths, path_lengths):
        for i in range(1, len(path)):
            pheromone_matrix[path[i - 1], path[i]] *= (1 - pheromone_evaporation_coefficient)
            pheromone_matrix[path[i - 1], path[i]] += Q / length
    print(f"Updated pheromone matrix: \n{pheromone_matrix}")

# Output the best path found
best_path_length = min(path_lengths)
best_path = all_paths[path_lengths.index(best_path_length)]
print(f"Best path: {best_path} with length: {best_path_length}")

