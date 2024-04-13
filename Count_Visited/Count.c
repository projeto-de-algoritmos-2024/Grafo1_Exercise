/**
 
Note: The returned array must be malloced, assume caller calls free().*/

int DFS(int* edges, int start, int no, int* visitados){
    int contador = -1;

    if(visitados[no] == (start + 1)){
        if(start == no){return ++contador;}
        else{return ++contador;}
    } else{
        visitados[no] = (start + 1);
        contador = DFS(edges, start, edges[no], visitados);
    }
    return ++contador;
}

int* countVisitedNodes(int* edges, int edgesSize, int* returnSize) {
    returnSize = malloc(edgesSize * sizeof(int));

    int visitados[edgesSize];
    memset(visitados, 0, sizeof(visitados));

    for(int i = 0; i < edgesSize; i++){
        int valor = DFS(edges, i, i, visitados);
        returnSize[i] = valor;
        //printf("%d", returnSize[i]);
    }

    return returnSize;
}