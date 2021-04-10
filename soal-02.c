/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
*   Modul               : 
*   Soal                : 
*   Hari dan Tanggal    : 
*   Nama (NIM)          : 
*   Asisten (NIM)       : 
*   Nama File           : 
*   Deskripsi           : 
*/

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
    //implementasi
}

//pop
void pop(node **n){
    //implementasi
}

//peek
cell peek(headS *s){
    //implementasi
}

//mencari posisi start yg sama dengan jalur[0] ada dimana saja
pos *position_start(int **board, int *jalur, int n, int m){
    pos *position = (pos *)malloc(n * m * sizeof(pos));
    
    //implementasi
    
    return position;
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

//push tetangga yang valid
void pushNeighbours(headS *s, int **board, int n, int m, cell currentCell, int index){
    //4 arah: bawah, atas, kiri, kanan

    //implementasi
}

//boleh pakai dfs atau bfs
int dfs(int **board, int *jalur, int len_jalur, int n, int m){
    //is_found_path = 0 ketika belum menemukan path pada board yang cocok dengan input path
    //is_found_path = 1 ketika sudah menemukan path pada board yang cocok dengan input path
    int is_found_path = 0; 

    //implementasi

    return is_found_path;
}

int main(){
    int len_jalur=0, is_found_path, n, m;
    int **board;
    int *jalur;
    
    printf("Masukkan ukuran matrix: ");
    //input ukuran matriks
    // board = initialize_matrix(n, m);

    printf("Masukkan input matrix:\n");
    //input matriks 

    // jalur = (int *)malloc(n * m * sizeof(int));
    printf("Masukkan input path yang ingin dicek: ");
    //input jalur hingga ketemu batas -1 lalu stop
    //update len_jalur sesuai dengan panjang jalur yang di input

    printf("Path ");
    // for(int i=0; i<len_jalur; i++){
    //     if(i!=len_jalur-1){
    //         printf("%d-", jalur[i]);
    //     } else{
    //         printf("%d ", jalur[i]);
    //     }
    // }
    
    // is_found_path = dfs(board, jalur, len_jalur, n, m);
    // if (is_found_path == 1){
    //     printf("terdapat pada matriks\n");
    // } else{
    //     printf("tidak terdapat pada matriks\n");
    // }
}
