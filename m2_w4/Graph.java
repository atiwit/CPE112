//67070501048 Atiwit
package m2_w4;

import java.util.*;

public abstract class Graph {
    protected int numVertices;
    protected Map<String, List<Edge>> adjacencyList;
    protected boolean isWeighted;

    public Graph(boolean isWeighted) {
        this.numVertices = 0;
        this.isWeighted = isWeighted;
        this.adjacencyList = new HashMap<>();
    }

    protected void addNode(String name) {
        if (!adjacencyList.containsKey(name)) {
            adjacencyList.put(name, new ArrayList<>());
        }
    }

    // fot unweighted graph
    public boolean addEdge(String source, String destination) {
        if (!isWeighted) {
            addEdgeWithWeight(source, destination, -1);
            return true;
        } else {
            return false;
        }
    }

    // for weighted graph
    public boolean addEdge(String source, String destination, int weight) {
        if (isWeighted) {
            addEdgeWithWeight(source, destination, weight);
            return true;
        } else {
            return false;
        }
    }

    public int getOutDegree(String name) {
        return adjacencyList.get(name).size();
    }

    public int getInDegree(String name) {
        int inDegree = 0;
        for (List<Edge> edges : adjacencyList.values()) {
            for (Edge edge : edges) {
                if (edge.destination.equals(name)) {
                    inDegree++;
                }
            }
        }
        return inDegree;
    }

    // ยังไม่ทำ
    public int sumWeightOutDegree(String name) {
        if (!adjacencyList.containsKey(name)) {
            return 0;
        }
        int sum = 0;
        for (Edge edge : adjacencyList.get(name)) {
            if (isWeighted) {
                sum += edge.weight;
            } else {
                sum += 1;
            }
        }
        return sum;
    }

    // ยังไม่ทำ
    public int sumWeightInDegree(String name) {
        int sum = 0;
        for (List<Edge> edges : adjacencyList.values()) {
            for (Edge edge : edges) {
                if (edge.destination.equals(name)) {
                    if (isWeighted) {
                        sum += edge.weight;
                    } else {
                        sum += 1;
                    }
                }
            }
        }
        return sum;
    }

    protected abstract void addEdgeWithWeight(String source, String destination, int weight);

}
