#include <bits/stdc++.h>
using namespace std;

class RouteOptimizer {
private:
    struct Edge {
        int to;
        int distance;
    };

    int nodes;
    vector<vector<Edge>> graph;
    vector<string> locationNames;

public:
    RouteOptimizer(int n) {
        nodes = n;
        graph.resize(nodes);
        locationNames.resize(nodes);
    }

    void setLocationName(int index, const string& name) {
        locationNames[index] = name;
    }

    void addRoad(int u, int v, int distance) {
        graph[u].push_back({v, distance});
        graph[v].push_back({u, distance});
    }

    pair<vector<int>, vector<int>> dijkstra(int source) {
        const int INF = 1e9;

        vector<int> dist(nodes, INF);
        vector<int> parent(nodes, -1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int currentDistance = pq.top().first;
            int currentNode = pq.top().second;
            pq.pop();

            if (currentDistance > dist[currentNode]) continue;

            for (auto edge : graph[currentNode]) {
                int adjacentNode = edge.to;
                int edgeWeight = edge.distance;

                if (currentDistance + edgeWeight < dist[adjacentNode]) {
                    dist[adjacentNode] = currentDistance + edgeWeight;
                    parent[adjacentNode] = currentNode;
                    pq.push({dist[adjacentNode], adjacentNode});
                }
            }
        }

        return {dist, parent};
    }

    vector<int> reconstructPath(int source, int destination, vector<int>& parent) {
        vector<int> path;

        int current = destination;

        while (current != -1) {
            path.push_back(current);

            if (current == source) break;

            current = parent[current];
        }

        reverse(path.begin(), path.end());

        if (path.empty() || path[0] != source) {
            return {};
        }

        return path;
    }

    void printPath(const vector<int>& path) {
        for (int i = 0; i < path.size(); i++) {
            cout << locationNames[path[i]];

            if (i != path.size() - 1) {
                cout << " -> ";
            }
        }

        cout << endl;
    }

    int calculateETA(int distance) {
        int averageSpeed = 30;
        int eta = (distance * 60) / averageSpeed;
        return eta;
    }

    void assignDeliveryPartner(vector<int>& deliveryPartners, int restaurant, int customer) {
        const int INF = 1e9;

        int selectedPartner = -1;
        int minimumDistanceToRestaurant = INF;
        vector<int> bestPartnerToRestaurantPath;

        for (int partner : deliveryPartners) {
            auto result = dijkstra(partner);

            vector<int> dist = result.first;
            vector<int> parent = result.second;

            if (dist[restaurant] < minimumDistanceToRestaurant) {
                minimumDistanceToRestaurant = dist[restaurant];
                selectedPartner = partner;
                bestPartnerToRestaurantPath = reconstructPath(partner, restaurant, parent);
            }
        }

        if (selectedPartner == -1 || minimumDistanceToRestaurant == INF) {
            cout << "No delivery partner can reach the restaurant." << endl;
            return;
        }

        auto restaurantResult = dijkstra(restaurant);

        vector<int> restaurantDist = restaurantResult.first;
        vector<int> restaurantParent = restaurantResult.second;

        if (restaurantDist[customer] == INF) {
            cout << "Restaurant cannot reach customer location." << endl;
            return;
        }

        vector<int> restaurantToCustomerPath = reconstructPath(restaurant, customer, restaurantParent);

        int totalDistance = minimumDistanceToRestaurant + restaurantDist[customer];
        int eta = calculateETA(totalDistance);

        cout << "Route Optimization and Delivery Assignment System" << endl;
        cout << "------------------------------------------------" << endl;

        cout << "\nSelected Delivery Partner: " << locationNames[selectedPartner] << endl;
        cout << "Restaurant: " << locationNames[restaurant] << endl;
        cout << "Customer Location: " << locationNames[customer] << endl;

        cout << "\nShortest route from delivery partner to restaurant:" << endl;
        printPath(bestPartnerToRestaurantPath);
        cout << "Distance: " << minimumDistanceToRestaurant << " km" << endl;

        cout << "\nShortest route from restaurant to customer:" << endl;
        printPath(restaurantToCustomerPath);
        cout << "Distance: " << restaurantDist[customer] << " km" << endl;

        cout << "\nTotal optimized delivery distance: " << totalDistance << " km" << endl;
        cout << "Estimated delivery time: " << eta << " minutes" << endl;
    }

    void displayLocations() {
        cout << "Available Locations:" << endl;

        for (int i = 0; i < nodes; i++) {
            cout << i << " - " << locationNames[i] << endl;
        }
    }
};

int main() {
    int n = 8;

    RouteOptimizer system(n);

    system.setLocationName(0, "Restaurant A");
    system.setLocationName(1, "Mall Road");
    system.setLocationName(2, "City Center");
    system.setLocationName(3, "Railway Station");
    system.setLocationName(4, "Customer Home");
    system.setLocationName(5, "Delivery Partner 1");
    system.setLocationName(6, "Delivery Partner 2");
    system.setLocationName(7, "Delivery Partner 3");

    system.addRoad(0, 1, 4);
    system.addRoad(0, 2, 3);
    system.addRoad(1, 3, 5);
    system.addRoad(2, 3, 2);
    system.addRoad(3, 4, 6);
    system.addRoad(1, 5, 7);
    system.addRoad(2, 6, 4);
    system.addRoad(3, 7, 3);
    system.addRoad(5, 6, 5);
    system.addRoad(6, 7, 2);

    vector<int> deliveryPartners = {5, 6, 7};

    int restaurant = 0;
    int customer = 4;

    system.assignDeliveryPartner(deliveryPartners, restaurant, customer);

    return 0;
}