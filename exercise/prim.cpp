#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct EdgeListNode{
    int weight;
    int end;
    EdgeListNode *next;
    EdgeListNode(int w, int e){
        weight = w;
        end = e;
        next = NULL;
    }
};

struct VerTexNode{
    int vertex;
    EdgeListNode *firstAdj;
};

struct AdjList{
    int vertexNum;
    int edgeNum;
    vector<VerTexNode> adjlist;
};

struct Prim{
    int adjvertex;
    int weight;
};

AdjList * createGraph();
void addEdge(int start, int end, int weight, AdjList *graph);
void printList(AdjList *graph);
void createPrim(AdjList *graph, vector<Prim> &primList, int startNode);
void printPrim(vector<Prim> &primList);

int main(){
    AdjList *graph = createGraph();
    printList(graph);
    
    vector<Prim> primList;
    createPrim(graph, primList, 1);
    printPrim(primList);
}

AdjList * createGraph(){
    AdjList *graph = new AdjList();
    int vertexNum, edgeNum;
    cin >> vertexNum >> edgeNum;
    graph->adjlist.resize(vertexNum + 1);
    graph->vertexNum = vertexNum;
    graph->edgeNum = edgeNum;
    for(int i=1; i<=vertexNum; i++){
        graph->adjlist[i].vertex = i;
    }
    for(int i=0; i<edgeNum; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        addEdge(start, end, weight, graph);
        addEdge(end, start, weight, graph);
    }

    return graph;
}

void addEdge(int start, int end, int weight, AdjList *graph){
    EdgeListNode * previous = graph->adjlist[start].firstAdj;
    graph->adjlist[start].firstAdj = new EdgeListNode(weight, end);
    graph->adjlist[start].firstAdj->next = previous;
}

void printList(AdjList *graph){
    int v = graph->vertexNum;
    for(int i=1; i<=v; i++){
        cout << graph->adjlist[i].vertex << " ";
        EdgeListNode * start = graph->adjlist[i].firstAdj;
        while(start != NULL){
            cout << "-> " << start->end << "(" << start->weight << ") ";
            start = start->next;
        }
        cout << endl;
    }
}

void createPrim(AdjList *graph, vector<Prim> &primList, int startNode){
    vector<int> mindistance;
    mindistance.assign(graph->vertexNum + 1, 0x7fffffff);
    vector<int> adjVertex;
    adjVertex.resize(graph->vertexNum+1);
    for(int i=1; i<=graph->vertexNum; i++){
        adjVertex[i] = i;
    }

    int treeVerNum = 0;
    primList.resize(graph->vertexNum + 1);
    //create from start point
    primList[startNode].adjvertex = startNode;
    primList[startNode].weight = 0;
    treeVerNum++;

    int currentNode = startNode;
    while(treeVerNum < graph->vertexNum){
        //set to 0
        mindistance[currentNode] = 0;

        //update mindistance
        EdgeListNode *firstEdge = graph->adjlist[currentNode].firstAdj;
        while(firstEdge != NULL){
            if(mindistance[firstEdge->end] > firstEdge->weight && mindistance[firstEdge->end] != 0){
                mindistance[firstEdge->end] = firstEdge->weight;
                adjVertex[firstEdge->end] = currentNode;
            }
            firstEdge = firstEdge->next;
        }

        //find smallest in mindistance to span
        int smallestValue = 0x7fffffff;
        int smallestPoint;
        for(int i=1; i<=graph->vertexNum; i++){ 
            if(mindistance[i] != 0 && smallestValue > mindistance[i]){
                smallestValue = mindistance[i];
                smallestPoint = i;
            }
        }

        //add to tree
        primList[smallestPoint].adjvertex = adjVertex[smallestPoint];
        primList[smallestPoint].weight = mindistance[smallestPoint];


        //set current to the smallest
        currentNode = smallestPoint;
        treeVerNum++;
    }
    primList[currentNode].adjvertex = adjVertex[currentNode];
    primList[currentNode].weight = mindistance[currentNode];
}

void printPrim(vector<Prim> &primList){
    for(int i=1; i<=primList.size()-1; i++){
        cout << "start: " << i << "end: " << primList[i].adjvertex << "weight: " << primList[i].weight << endl;
    }
}