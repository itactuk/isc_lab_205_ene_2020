//
// Created by pi on 3/31/20.
//
#include<stdio.h>   
#include<stdlib.h>
#include<string.h>

typedef struct listado_palabras{
    char ** listado;
    int n;
}LIST_PALABRAS;

char * lee_texto(char * nombre_archivo);
void estructura_ejemplo3();
LIST_PALABRAS obten_listado_palabras(char * texto);
char * agrega_ok_despues_de_esto(char *);
void rodar_hacia_dcha_texto(char* texto, int n);

typedef struct jugadores{
    char nombre[40];
    JUEGO **juegos;
    int n_juegos;
    
}JUGADORES;

typedef struct juego{
    double bono;
    
}JUEGO;

JUEGO j1, j2, j3, j4;

int main_xavier_proj(){
    
    JUGADORES xavier;
    xavier.n_juegos = 0;
    // Elige un juego (1,2,3,4,..)
    JUEGO * je = &j1;
    //Despues que elija
    xavier.juegos = realloc(xavier.juegos, xavier.n_juegos * sizeof(JUEGO));
    xavier.juegos[xavier.n_juegos-1] = je; //&j1;
    xavier.n_juegos++;
    
    printf("%f", (xavier.juegos[xavier.n_juegos-1])->bono);
    
}

int main_xavier_proj_asumiendo_que_juegos_es_arr(){ // JUEGO juegos[10];
    
    JUGADORES xavier;
    xavier.n_juegos = 0;
    // Elige un juego (1,2,3,4,..)
    JUEGO je = j1;
    //Despues que elija
    xavier.juegos[xavier.n_juegos-1] = je; //j1;
    xavier.n_juegos++;
    
    printf("%f", xavier.juegos[xavier.n_juegos-1].bono);
    
}

int ld_publica (char * a, char * b){
    return ld_privada(a,strlen(a)-1,b, strlen(b)-1);
}

int ld_privada (char * a, int i, char * b, int j){
    if (i<0||j<0) {
        return max(i,j) + 1;
    }
    int r1, r2, r3, k=0;
    if (a[i]==b[j]){
        k=0;
    }else{
        k=1;
    }
    r1 = ld_privada(a,i-1,b,j) + 1;
    r2 = ld_privada(a,i, b, j-1) + 1;
    r3 = ld_privada(a, i-1, b, j-1) + k;
    
    r = min_3(r1, r2, r3);
    return r;
}

int main(){
    char * contenido = lee_texto("mi_archivo.txt");
    printf("%s", agrega_ok_despues_de_esto(contenido));

}

char * agrega_ok_despues_de_esto(char * texto){
    /*
     estook es un cont
esta es otra linea
bien 
* 
* i=3
esto es un cont
esta es otra linea
bien 
     * */
     int x;
    for(int i=0; texto[i]!='\0';i++){
        if (strncmp(texto+i, "esto", 4) == 0){
            texto = realloc(texto, (strlen(texto)+3) * sizeof(char));
            rodar_hacia_dcha_texto(texto+i+4,2);
            strncpy(texto+i+4, "ok", 2);
            i+=2;
        }
    }
    return texto;
}

// 012345
// holaxx
// holaxa
// holala
// holola
// hohola
void rodar_hacia_dcha_texto(char* texto, int n){
    /*n==2
     * cant_chars =38
     * es un cont
esta es otra linea
bien 
     * */
    int cant_chars = strlen(texto);
    for(int i = cant_chars + n; i>=n; i--){
        printf("\nVUELTA %d:\n", i);
        printf("%s", texto);
        printf("\nFIN VUELTA\n");
        texto[i]=texto[i-n];
    }
}



LIST_PALABRAS obten_listado_palabras(char * texto){
    char buffer[255];
    LIST_PALABRAS res;
    res.listado = malloc(1*sizeof(char*));
    res.n = 0;
    int cant_c, indice_pal=0, i_anterior=0;
    for(int i=0; texto[i]!='\0';i++){
        if (texto[i] == ' ' || texto[i] == '\n'){
            cant_c = i - i_anterior;
            res.listado[indice_pal]= malloc((cant_c+1) * sizeof(char));
            strncpy(res.listado[indice_pal], texto + i_anterior, cant_c);
            i_anterior = i+1;
            indice_pal++;
        }
    }
    return res;
}

void estructura_ejemplo3(){
    //Reciben por parametreo esta variable
    char * s = "Hola. Estoy en clase. Bien";
    char * mi_oracion;
    for (s = mi_oracion; *s != '\0'; ++s) {
        if (*s == '.'){
            return s+1;
        }
    }
    //return s;
}

char * lee_texto(char * nombre_archivo){
    FILE * arch = fopen(nombre_archivo,"r");
    char * texto = calloc(1, sizeof(char));
    char buffer[250];
    int x, n=0;
    while (fgets(buffer, 249, arch)!=NULL){ 
        x = strlen(buffer); // buffer ="Hola";
        n+=x;
        texto = realloc( texto, (n+1) * sizeof(char)); // texto era " Bien"
        strcat(texto, buffer); // El resultado seria "Hola Bien"
    }
    //printf("%d",n);
    fclose(arch);
    return texto;
}
