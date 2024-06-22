#pragma once

class Graph {

virtual void addEdge(int v, int w) = 0;

virtual void addWeigthedEdge(int v, int w, int weight) = 0;

virtual void removeEdge(int v, int w) = 0;

virtual bool hasEdge(int v, int w) = 0;

virtual int getEdge(int v, int w) = 0;

virtual bool* DFS(int v, bool* visited) = 0;
};