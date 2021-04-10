#include <stdio.h>
#include <stdlib.h>

//expected index digunakan saat pengecekan jalur pada matriks
//expected index akan diupdate ketika setiap elemen jalur sudah cocok pada setiap elemen jalur pada matriks
//ketika expected index sudah sama dengan len_jalur, maka akan terdapat jalur yang cocok pada matriks
typedef struct node {
    int row;
    int col;
    int expected_index;
    struct node *next;
} node;

typedef struct headS {
	node *head;
} headS;

typedef struct pos {
    int row;
    int col;
} pos;

typedef struct cell {
    int row;
    int col;
    int expected_index;
} cell;

//push
void push(headS *s, int row, int col, int expected_index){
	node *sNew;
	sNew = (node*) malloc(sizeof(node));
	sNew->row = row;
    sNew->col = col;
    sNew->expected_index = expected_index;
	sNew->next = s->head;
	s->head = sNew;
}

//pop
void pop(node **n){
    node *nNew = *n;
    (*n) = (*n)->next;
    free(nNew);
}

//peek
cell peek(headS *s){
    cell cells;
    if(s->head != NULL){
        cells.row = s->head->row;
        cells.col = s->head->col;
        cells.expected_index = s->head->expected_index;
        return cells;
    } 
}

//inisiasi matriks
int **initialize_matrix(int n, int m){
    int **mat;
    mat = (int **)malloc(n * sizeof(int *));
    for(int i=0; i<n; i++){
        mat[i] = (int *)malloc(m * sizeof(int)); 
    }
    return mat;
}

//mencari posisi start yg sama dengan jalur[0] ada dimana saja
pos *position_start(int **board, int *jalur, int n, int m){
    pos *position = (pos *)malloc(n * m * sizeof(pos));
    int index = 0;
    for(int r=0; r<n; r++){
        for(int c=0; c<m; c++){
            //ketika sama dengan jalur[0]
            if(board[r][c] == jalur[0]){
                position[index].row = r;
                position[index].col = c; 
            //ketika tidak sama dengan jalur[0]    
            } else{
                position[index].row = -1;
                position[index].col = -1;
            }
            index++;
        }
    }
    return position;
}

//push tetangga
void pushNeighbours(headS *s, int **board, int n, int m, cell currentCell, int index){
    pos possible_neighbour[4];
    //4 arah: bawah, atas, kiri, kanan
    possible_neighbour[0].row = currentCell.row+1;
    possible_neighbour[0].col = currentCell.col;
    possible_neighbour[1].row = currentCell.row-1;
    possible_neighbour[1].col = currentCell.col;
    possible_neighbour[2].row = currentCell.row;
    possible_neighbour[2].col = currentCell.col-1;
    possible_neighbour[3].row = currentCell.row;
    possible_neighbour[3].col = currentCell.col+1;
    //tetangga yang valid masih dalam boundary
    for(int i=0; i<4; i++){
        if ((0 <= possible_neighbour[i].row) && (possible_neighbour[i].row < n) && (0 <= possible_neighbour[i].col) && (possible_neighbour[i].col < m) ){
            push(s, possible_neighbour[i].row, possible_neighbour[i].col, index);
        } 
    }
}

//dfs
int dfs(int **board, int *jalur, int len_jalur, int n, int m){
    int index, is_found_path = 0; 
    cell currentCell;
    headS *s;
    s = (headS*) malloc(sizeof(headS));
    s->head = NULL;
    pos *start = (pos *)malloc(n * m * sizeof(pos));
    //ambil semua kemungkinan posisi startnya pada board
    start = position_start(board, jalur, n, m);
    for(int i=0;i<n*m; i++){
        index=0;
        //jika posisi start valid yaitu sama dengan jalur[0]
        if ((start[i].row != -1) && (start[i].col != -1)){
            push(s, start[i].row, start[i].col, index);
            while(s->head != NULL){
                currentCell = peek(s);
                pop(&s->head);
                if((board[currentCell.row][currentCell.col] == jalur[index]) && (index == currentCell.expected_index)){
                    //misal : 1 2 3   path: 2 3 6
                    //        4 5 6
                    //        7 8 9
                    //pertama cek currentCell yaitu 2 apakah sama dengan jalur[index] (misal index=0) dan apakah index==currentCell.expected_index. 
                    //Ternyata sama maka update index, maka push tetangga dari 2 yaitu 1 5 3
                    //sehingga isi stacknya menjadi [((1,1), 1), ((0,0), 1), ((0,2), 1)]
                    index++;

                    pushNeighbours(s, board, n, m, currentCell, index);

                    //ketika expected_index == len_jalur
                    if(s->head->expected_index == len_jalur){
                        //maka ketemu pathnya
                        is_found_path = 1;
                        break;
                    } 
                } else{
                    
                }
            }
        }
    }
    return is_found_path;
}

int main(){
    int len_jalur=0, elemen_jalur, is_found_path, n, m;
    int **board;
    int *jalur;
    
    printf("Masukkan ukuran matrix: ");
    scanf("%d %d", &n, &m);
    board = initialize_matrix(n, m);

    printf("Masukkan input matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &board[i][j]);
        }
    }

    jalur = (int *)malloc(n * m * sizeof(int));
    printf("Masukkan input path yang ingin dicek: ");
    scanf("%d", &elemen_jalur);
    jalur[len_jalur] = elemen_jalur;
    len_jalur++;
    while(len_jalur<n*m){
        scanf("%d", &elemen_jalur);
        if (elemen_jalur != -1){
            jalur[len_jalur] = elemen_jalur;
            len_jalur++;
        } else {
            break;
        }
    }

    printf("Path ");
    for(int i=0; i<len_jalur; i++){
        if(i!=len_jalur-1){
            printf("%d-", jalur[i]);
        } else{
            printf("%d ", jalur[i]);
        }
    }

    is_found_path = dfs(board, jalur, len_jalur, n, m);
    if (is_found_path == 1){
        printf("terdapat pada matriks\n");
    } else{
        printf("tidak terdapat pada matriks\n");
    }
}
