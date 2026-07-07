# Route Optimization and Delivery Assignment System

A C++ based DSA project that optimizes delivery partner assignment and delivery route selection using graph algorithms.

## Project Overview

This project simulates a delivery system where restaurants, customers, delivery partners, and city locations are represented as graph nodes. Roads between locations are represented as weighted edges.

The system selects the nearest available delivery partner and finds the shortest route from the delivery partner to the restaurant and then from the restaurant to the customer.

## Features

- Represents city locations using a weighted graph
- Uses Dijkstra's Algorithm to find the shortest path
- Uses priority queue for efficient shortest distance calculation
- Assigns the nearest available delivery partner using greedy logic
- Reconstructs and displays the optimized delivery route
- Calculates total optimized delivery distance
- Estimates delivery time based on average speed

## DSA Concepts Used

- Graph
- Weighted Graph
- Dijkstra's Algorithm
- Priority Queue / Min Heap
- Greedy Algorithm
- Path Reconstruction
- Adjacency List

## Tech Stack

- C++
- STL
- Priority Queue
- Graph using Adjacency List

## How It Works

1. City locations are represented as nodes.
2. Roads between locations are represented as weighted edges.
3. Delivery partners, restaurant, and customer are assigned specific locations.
4. Dijkstra's Algorithm is used to calculate the shortest distance from each delivery partner to the restaurant.
5. The nearest delivery partner is selected using greedy logic.
6. Dijkstra's Algorithm is again used to find the shortest route from the restaurant to the customer.
7. The optimized route, total distance, and estimated delivery time are displayed.

## Example Locations

| Node | Location |
|---|---|
| 0 | Restaurant A |
| 1 | Mall Road |
| 2 | City Center |
| 3 | Railway Station |
| 4 | Customer Home |
| 5 | Delivery Partner 1 |
| 6 | Delivery Partner 2 |
| 7 | Delivery Partner 3 |

## Sample Output

```text
Route Optimization and Delivery Assignment System
------------------------------------------------

Selected Delivery Partner: Delivery Partner 2
Restaurant: Restaurant A
Customer Location: Customer Home

Shortest route from delivery partner to restaurant:
Delivery Partner 2 -> City Center -> Restaurant A
Distance: 7 km

Shortest route from restaurant to customer:
Restaurant A -> City Center -> Railway Station -> Customer Home
Distance: 11 km

Total optimized delivery distance: 18 km
Estimated delivery time: 36 minutes
```

## Time Complexity

Dijkstra's Algorithm using priority queue takes:

```text
O((V + E) log V)
```

Where:

- V = number of locations
- E = number of roads

If there are K delivery partners, then the system checks shortest distance from each partner to the restaurant.

Overall complexity:

```text
O(K * (V + E) log V)
```

## Space Complexity

```text
O(V + E)
```

This is because the graph is stored using an adjacency list.

## Future Improvements

- Add real-time traffic updates
- Add multiple restaurants and customers
- Add delivery partner availability status
- Add order priority handling
- Add map-based route visualization
- Build a simple UI dashboard
- Integrate real-world map APIs
