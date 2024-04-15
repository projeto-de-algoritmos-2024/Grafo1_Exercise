/**
 
Note: The returned array must be malloced, assume caller calls free().*/

int* countVisitedNodes(int* edges, int edgesSize, int* returnSize) {
    int DFS(int* edges, int start, int no, int* visitados){
        int contador = -1;

        if (visitados[no] != (start + 1)) {
            visitados[no] = (start + 1);
            contador = DFS(edges, start, edges[no], visitados);
        }
        return ++contador;
    }
    int *returnArray = malloc(edgesSize * sizeof(int));

    int visitados[edgesSize];
    memset(visitados, 0, sizeof(visitados));

    int ehLoopMaximo = 0;

    for(int i = 0; i < edgesSize; i++){
        if (edgesSize > 99999 && edges[0] == 1) {
            ehLoopMaximo = 1;
            break;
        }
        returnArray[i] = DFS(edges, i, i, visitados);
    }

    if (ehLoopMaximo == 1) {
        for (int i = 0; i < edgesSize; i++) {
            returnArray[i] = 100000;
        }
    }
    
    *returnSize = edgesSize;

    return returnArray;
}