int DFS(int* edges, int inicio, int no, int *visitados){
    int contador = -1;

    if(edges[no] == -1){return contador--;}

    if(visitados[no] == (inicio + 1)){
        if(no == inicio){
            return ++contador;
        }
        else{
            return contador = -1;;
        }
    }
    else{
        visitados[no] = (inicio + 1);
        contador = DFS(edges, inicio, edges[no], visitados);
    }

    if(contador == -1){return contador = -1;}
    else{return ++contador;}
}

int longestCycle(int* edges, int edgesSize) {
    int ciclo = -1;

    int visitados[edgesSize];
    memset(visitados, 0, sizeof(visitados));

    for(int i = 0; i < edgesSize; i++){
        int contador = DFS(edges, i, i, visitados);

        if(contador > ciclo){ciclo = contador;}
    }

    return ciclo;
}