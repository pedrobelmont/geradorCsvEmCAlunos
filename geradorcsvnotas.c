# include <stdio.h>
# include <string.h>
# include <stdlib.h>


# define ANSI_COLOR_GREEN    "\e[0;32m"
# define ANSI_COLOR_RESET    "\e[0m"  

void linparEntrada(){
    char c;
     while ((c = getchar()) != '\n' && c != EOF)
    {}
    
};

void mensgemDinamica(int valor,char texto1[60],char texto2[60]){
    if(valor == 0){
        printf(texto1);  
    }else{
        printf(texto2); 
    };
};
int criarArquivo( int quantiade, char aluno[quantiade][2][100]){
    printf("criando arquivo dos alunos...");
    FILE * arquivo;
    arquivo = fopen("alunos.csv","w");
    fputs("nome,nota,aprovação \n",arquivo);
    for(int i = 0 ; i < quantiade; i++ ){
        int nota = atoi(aluno[i][1]);
        for (int j = 0; j < 2; j++)
        {   
            fputs(aluno[i][j],arquivo);
            fputs(",",arquivo);
        };
        if(nota >= 7){
            fputs("aprovado",arquivo);
        }else{
            fputs("reprovado",arquivo);
        };
        fputs("\n",arquivo);
        
    };
    fclose(arquivo);
};

int main(){
    printf(ANSI_COLOR_GREEN"programa feito por quantoLTDA \n" ANSI_COLOR_RESET);
    int quantidadeAlunos;
    printf("quantos alunos voce tem que cadastrar a nota > ");
    scanf("%d", &quantidadeAlunos);

    char letra;
    char alunos[quantidadeAlunos][2][100];
    // int notas[quantidadeAlunos];
    for (int i = 0; i < quantidadeAlunos; i++)
    {
        for (int j = 0; j < 2; j++)
        {   
            // printf("escreva o nome do aluno >"); 
            mensgemDinamica(j,"escreva o nome do aluno >","escreva o a nota do aluno >");  
            scanf("%s",&alunos[i][j]); 
        }
    }
    for(int i = 0; i < quantidadeAlunos; i++){
        printf("index: %d >", i); 
        for (int j = 0; j < 2; j++)
        {  
            
            mensgemDinamica(j, "aluno: ", "nota: ");
            printf("%s ", alunos[i][j]);

        }
        printf("\n");
    };

    printf("deseja criar um arquivo dos alunos ? ");
    printf("digite s para confirmar ");
    
    linparEntrada();
    scanf("%c", &letra);
    linparEntrada();
    printf("%c \n", letra);
    if(letra == 's'){
        criarArquivo(quantidadeAlunos,&alunos);
    }else{
        printf("programa encerrado");
    };
    return 0;
}
