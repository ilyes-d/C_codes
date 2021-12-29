#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
//NOM : YAHIA 
//Prenom : AEK Ilyes 
//MAT : 181838009464 

//SECTION : ISIL A gr : 02 

typedef struct person {
    char P[20] ;
    char N[20] ;
    char adr[20] ;
    int a ;
}Personne ;
//this is for what ? /? ? ? ? 




Personne *cree_tab(int n){
    int i ;
    Personne *p ;
    p = malloc(n * sizeof(Personne)) ;
    for ( i = 0; i < n; i++){
        printf("person : %d",i+1 );
        printf("\n\tnom :");
        scanf(" %[^\n]" , p[i].N ) ;
        printf("\n\tprenom :");
        scanf(" %[^\n]" , p[i].P ) ;
        printf("\n\tadr :");
        scanf(" %[^\n]" , p[i].adr ) ;
        printf("\n\tage :");
        scanf(" %d" , &p[i].a ) ;
    }
    return p ;
}
void afficher_tab(Personne *p , int n){
    int i ;
    printf("\n\t--------------------------------------------------------------------------");
    for ( i = 0; i < n; i++)
    {
        printf("\n\t|%20s%d%51s|","person :" , i+1," " );
        printf("\n\t|%20s|%20s|%30s|"," ","nom : %s ",p[i].N) ;
        printf("\n\t|%20s|%20s|%30s|"," ","prenom : %s ",p[i].P) ;
        printf("\n\t|%20s|%20s|%30s|"," ","adress : %s ",p[i].adr);
        printf("\n\t|%20s|%20s|%30d|"," ","age : %d ",p[i].a);
        printf("\n\t--------------------------------------------------------------------------");


    }
    printf("\n");
}
void tri(Personne *p ,int n ){
    int i ,imin  ;
    int j ; 
    Personne temp ;
    char min[20] ;
    for ( i = 0; i <n-1 ; i++){
        strcpy(min , p[i].N) ;
        imin = i ;
        for ( j = 0; j < n; j++)
        {
            if(strcmp(min , p[j].N) == 1 ) {
                strcpy(min  ,p[j].N );
                imin = j ;
            }
        }
        if(imin != i ){
            temp = p[i] ;
            p[i] = p[imin] ;
            p[imin] = temp ;
        }
    }
    
}
int main(int argc, char const *argv[])
{
    int nbr ;
    Personne *p ;
    printf("donner le nbre de perssones a remplir : ");
    scanf("%d", &nbr) ;
    p = cree_tab( nbr ) ;
    afficher_tab(p , nbr);
    printf("apres tri : \n");
    tri(p,nbr);
    afficher_tab(p , nbr);

    return 0;
}
