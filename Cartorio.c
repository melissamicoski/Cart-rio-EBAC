#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registrar()//Cadastro de usuarios no sistema
{   
    //inicio cria��o de viari�veis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado:");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e salva na mesma pasta que o codigo
    fprintf(file, cpf); //salva o valor da variavel
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado:");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado:");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado:");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    system("pause");
}

int consultar()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a l�ngua
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
            printf("N�o foi possivel abrir o arquivo, n�o localizado.\n");   
    }
    
    while(fgets(conteudo, 200, file) != NULL)
    { 
            printf("\nEssas so as informa��es do usu�rio:");
            printf("%s", conteudo);
            printf("\n\n");
    }
    
    system("pause");
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL);
    { 
      printf("O usuario n�o se encontra no sistema!.\n");
      system("pause");
    } 
    
}

int main()
{
    int opcao=0; //Definindo vari�veis
    int laco=1;
    
    for(laco=1;laco=1;)
    {

        system("cls");
        setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
    
        printf("\t Cart�rio da EBAC \n\n"); //in�cio do menu
    
        printf("Escolha a op��o desejada:\n\n");
    
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Op��o: ");//fim do menu
    
        scanf("%d", &opcao); //in�cio da sele��o do usu�rio
    
        system("cls");
        
        switch(opcao)
        {
            case 1:
            registrar();
            break;
            
            case 2:
            consultar();
            break;
            
            case 3:
            deletar();
            break;
            
            case 4:
            printf("Obrigado por utilizar o sistema!");
            return 0;
            break;
            
            default:
            printf("Essa op��o n�o est� dispon�vel!\n");
            system("pause");
            break;
        }
    
       
    }
}
