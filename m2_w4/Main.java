package m2_w4;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int graphType = scanner.nextInt();
        scanner.nextLine();

        Graph graph;
        boolean isWeighted;

        switch (graphType) {
            case 1: // Directed Unweighted
                graph = new DirectedGraph(false);
                isWeighted = false;
                break;
            case 2: // Directed Weighted
                graph = new DirectedGraph(true);
                isWeighted = true;
                break;
            case 3: // Undirected Unweighted
                graph = new UndirectedGraph(false);
                isWeighted = false;
                break;
            case 4: // Undirected Weighted
                graph = new UndirectedGraph(true);
                isWeighted = true;
                break;
            default:
                scanner.close();
                return;
        }

        int E = scanner.nextInt();
        scanner.nextLine();

        // Add edges
        for (int i = 0; i < E; i++) {
            String[] parts = scanner.nextLine().split(" ");
            String src = parts[0];
            String dest = parts[1];

            if (isWeighted) {
                int weight = Integer.parseInt(parts[2]);
                graph.addEdge(src, dest, weight);
            } else {
                graph.addEdge(src, dest);
            }
        }

        int n = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < n; i++) {
            String vertex = scanner.nextLine();

            if (graphType == 1 || graphType == 2) {
                int outDegree = graph.getOutDegree(vertex);
                int inDegree = graph.getInDegree(vertex);

                if (isWeighted) {
                    int sumOutWeight = graph.sumWeightOutDegree(vertex);
                    int sumInWeight = graph.sumWeightInDegree(vertex);
                    System.out.println(outDegree + " " + inDegree + " " + sumOutWeight + " " + sumInWeight);
                } else {
                    System.out.println(outDegree + " " + inDegree);
                }
            }

            else {
                int degree = graph.getOutDegree(vertex);

                if (isWeighted) {
                    int sumWeight = graph.sumWeightOutDegree(vertex);
                    System.out.println(degree + " " + sumWeight);
                } else {
                    System.out.println(degree);
                }
            }
        }

        scanner.close();
    }
}