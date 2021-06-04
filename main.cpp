#include <iostream>
#include <string.h>
#include <math.h>
#include "pilhas.cpp"

using namespace std;

//Definindo cores para impressão
#define COLOR_VERMELHO     "\x1b[31m"
#define COLOR_VERDE        "\x1b[32m"
#define COLOR_AMARELO      "\x1b[33m"
#define COLOR_RESET        "\x1b[0m"


int main()
{
    //Flag para determinar o momento fim da execucao
    int flag = 1;
    //Variavel para determinar se já foi criada alguma pilha
    int idPilhaInt = 0;
    int idPilhaCha = 0;
    //Variavel para armazenar se sera criada uma pilha de inteiro ou caracteres
    int tipPilha = 0;
    /** Variaveis para armazenar os enderecos das pilhas.
     * Nao e possivel, nativamente, armazenar um objeto que seja dinamico
     * isso pois cada um possui seu tamanho e quantidade de elementos e a linguagem
     * nao possui suporte para encontrar o inicio e o fim dele, deixando a informacao
     * incompleta.
    */
    int **arrInt = NULL;
    int arrIntSize = 0;
    int **arrCha = NULL;
    int arrChaSize = 0;
    //Variavel para escolha de pilha em algumas opcoes
    int idEscolha = 0;
    //Variavel para segunda escolha em comparacoes
    int idEscolha2 = 0;
    int tam = 0;
    //variavel para armazenamento de respostas dos metodos
    int res = 0;
    while(flag){
        if(idPilhaInt||idPilhaCha){
            cout << COLOR_AMARELO "------------------------------------ OPCOES ------------------------------------\n\n";
            cout << "OBS: Opcoes 2|-|6 apenas para pilhas INTEIRAS, 7 e 8 pilhas de CARACTERES\n";
            cout << "1 - Criar uma nova pilha.\n";
            cout << "2 - Inverter pilha.\n";
            cout << "3 - Encontrar o maior e o menor valor, calcular a media de todos os elementos.\n";
            cout << "4 - Comparar se uma pilha possui mais elementos que outra.\n";
            cout << "5 - Verificar se duas pilhas sao iguais.\n";
            cout << "6 - Retornar valores impares de uma pilha.\n";
            cout << "7 - Verificar se uma palavra é um palíndromo.\n";
            cout << "8 - Inverter letras de uma frase sem interferir na ordem das palavras\n";
            cout << "9 - Imprimir pilha de inteiros\n";
            cout << "10 - Imprimir pilha de caracteres\n";
            cout << "0 - Sair\n";
        }else{
            system("clear");
            cout << COLOR_AMARELO "------------------------------------ OPCOES ------------------------------------\n\n";
            cout << "1 - Criar uma nova pilha.\n";
            cout << "0 - Sair\n";
        }
        cin >> flag;
        switch (flag)
        {
        case 1:
            system("clear");
            cout << "Deseja criar uma pilha de inteiros(1) ou uma pilha de caracteres(2)?: ";
            cin >> tipPilha;
            cout << "Qual o tamanho da pilha?\n" COLOR_RESET;
            cin >> tam;
            if(tam < 1 ){
                cout << COLOR_VERMELHO "Tamanho inserido invalido\n" COLOR_RESET;
                break;
            }
            if(tipPilha == 1){
                //Criando as variaveis da pilha auxiliar
                PilhaInt *aux = (PilhaInt *) malloc(sizeof(PilhaInt));
                double elem = 0;
                aux->Inicia(tam,idPilhaInt);
                //Inserindo elementos na pilha
                for(int i = 0; i<tam;i++){
                    system("clear");
                    cout << COLOR_AMARELO "Insira o elemento " << i+1 << " da pilha: " COLOR_RESET;
                    cin >> elem;
                    aux->empilhar(elem);
                }
                //Pilha criada com sucesso
                aux->imprimir();
                //Realocando o array de pilhas inteiras para inserir mais um endereco
                arrIntSize++;
                arrInt = (int**) realloc(arrInt, sizeof(int**)*arrIntSize); // + posição
                //Inserindo o endereco da pilha no array
                arrInt[idPilhaInt] = (int *) aux;
                idPilhaInt++;
            }
            else if(tipPilha == 2){
                //Criando as variaveis da pilha auxiliar
                PilhaCha *aux = (PilhaCha *) malloc(sizeof(PilhaCha));
                string elem = "";
                aux->Inicia(tam,idPilhaCha);
                cout << COLOR_AMARELO "Insira os caracteres da pilha (SEM ACENTO) e pressione ENTER: " COLOR_RESET;
                //cin >> elem;
                cin.ignore();
                getline(cin,elem);
                //Inserindo elementos na pilha
                for(int i = 0; i<tam;i++){
                    aux->empilhar(elem[i]);
                }
                //Pilha criada com sucesso
                aux->imprimir();
                //Realocando o array de pilhas inteiras para inserir mais um endereco
                arrChaSize++;
                arrCha = (int**) realloc(arrCha, sizeof(int**)*arrChaSize); // + posição
                //Inserindo pilha no array
                arrCha[idPilhaCha] = (int *) aux;
                idPilhaCha++;
            }
            else{
                cout << COLOR_VERMELHO "Tipo invalido, insira novamente.\n" COLOR_RESET;
            }
            break;
        case 2:
            system("clear");
            imprimePilhasInt(idPilhaInt,arrInt);
            cout << COLOR_AMARELO "Escolha qual pilha deseja inverter, insira o ID:\n" COLOR_RESET;
            cin >> idEscolha;
            //Verificando se a escolha e valida
            if(idEscolha > idPilhaInt || idEscolha < 0){
                cout << COLOR_VERMELHO "ID invalido\n" COLOR_RESET;
            }else{
                PilhaInt *_pilha = (PilhaInt *) arrInt[idEscolha];
                _pilha->inverter();
                cout << COLOR_VERDE "Pilha invertida:\n" COLOR_RESET;
                _pilha->imprimir();
            }
            break;
        case 3:
            system("clear");
            imprimePilhasInt(idPilhaInt,arrInt);
            cout << COLOR_AMARELO "Escolha qual pilha deseja saber o maior/menor valor e a media aritmetica, insira o ID:\n" COLOR_RESET;
            cin >> idEscolha;
            //Verificando se a escolha e valida
            if(idEscolha > idPilhaInt || idEscolha < 0){
                cout << COLOR_VERMELHO "ID invalido\n" COLOR_RESET;
            }else{
                PilhaInt *_pilha = (PilhaInt *) arrInt[idEscolha];
                _pilha->maiorMenorMedia();
            }
            break;
        case 4:
            system("clear");    
            imprimePilhasInt(idPilhaInt,arrInt);
            cout << COLOR_AMARELO "Escolha a primeira pilha a ser comparada (digite o id): ";
            cin >> idEscolha;
            cout << "Escolha a segunda pilha a ser comparada (digite o id): " COLOR_RESET;
            cin >> idEscolha2;
            if(idEscolha > idPilhaInt || idEscolha < 0){
                cout << COLOR_VERMELHO "ID invalido\n" COLOR_RESET;
            }else{
                PilhaInt *_pilha  = (PilhaInt *) arrInt[idEscolha];
                PilhaInt *_pilha2 = (PilhaInt *) arrInt[idEscolha2];
                res = _pilha->comparaTamPilha(_pilha2->getTopo());
                if(res && res != 2){
                    cout << COLOR_VERDE "Segunda pilha possui mais elementos.\n" COLOR_RESET;
                }else if(!res && res != 2){
                    cout << COLOR_VERDE "Primeira pilha possui mais elementos.\n" COLOR_RESET;
                }else{
                    cout << COLOR_VERDE "As duas pilhas possuem o mesmo tamanho.\n" COLOR_RESET;
                }
            }
            break;
        case 5:
            {
                system("clear");
                imprimePilhasInt(idPilhaInt,arrInt);
                cout << COLOR_AMARELO "Escolha a primeira pilha a ser comparada (digite o id): ";
                cin >> idEscolha;
                cout << "Escolha a segunda pilha a ser comparada (digite o id): " COLOR_RESET;
                cin >> idEscolha2;
                //Irei verificar primeiro se os topos das pilhas sao iguais
                PilhaInt *_pilha  = (PilhaInt *) arrInt[idEscolha];
                PilhaInt *_pilha2 = (PilhaInt *) arrInt[idEscolha2];
                res = _pilha->comparaTamPilha(_pilha2->getTopo());
                if(res != 2){
                    cout << COLOR_VERDE "As pilhas sao diferentes\n" COLOR_RESET;
                }else{
                    //Criando as pilhas auxiliares para nao perder o valor da pilha
                    PilhaInt aux1 = *_pilha;
                    PilhaInt aux2 = *_pilha2;
                    //Irei chamar o metodo na primeira pilha passando por valor
                    res = aux1.verificaIgualdade(aux2);
                    if(res){
                        cout << COLOR_VERDE "As pilha sao iguais.\n" COLOR_RESET;
                    }else{
                        cout << COLOR_VERDE "As pilhas nao sao iguais.\n" COLOR_RESET;
                    }
                }
                break;
            }
        case 6:
            {
                system("clear");
                imprimePilhasInt(idPilhaInt,arrInt);
                cout << COLOR_AMARELO "Qual pilha deseja consultar os valores impares (digite o id)? " COLOR_RESET;
                cin >> idEscolha;
                PilhaInt *_pilha  = (PilhaInt *) arrInt[idEscolha];
                //Realizando copia da pilha para nao alterar os valores.
                PilhaInt aux = *_pilha;
                aux.retornaImpar();
            }
            break;
        case 7:
            {
                system("clear");
                imprimePilhasCha(idPilhaCha,arrCha);
                cout << COLOR_AMARELO "Qual pilha deseja verificar se e um palindromo (digite o id)? " COLOR_RESET;
                cin >> idEscolha;
                PilhaCha *_pilha = (PilhaCha *) arrCha[idEscolha]; 
                res = _pilha->palindromo();
                if(res){
                    cout << COLOR_VERDE "E um palindromo!\n" COLOR_RESET;
                }else{
                    cout << COLOR_VERDE "Nao e um palindromo.\n" COLOR_RESET;
                }
            }
            break;
        case 8:
            {
                system("clear");
                imprimePilhasCha(idPilhaCha,arrCha);
                cout << COLOR_AMARELO "Qual pilha deseja inverter? (digite o id) " COLOR_RESET;
                cin >> idEscolha;
                //Faz a conversao do espaco de memoria e salva o endereco da pilha no ponteiro
                PilhaCha *_pilha = (PilhaCha *) arrCha[idEscolha]; 
                _pilha->inverteLetras();
                _pilha->imprimir();
            }
            break;
        case 9:
            imprimePilhasInt(idPilhaInt,arrInt);
            break;
        case 10:
            imprimePilhasCha(idPilhaCha,arrCha);
            break;
        case 0:
            break;
        default:
            cout<< COLOR_VERMELHO "Opcao nao identificada, selecione novamente!\n" COLOR_RESET;
            break;
        }
    }
    system("clear");
    cout << COLOR_VERMELHO "Saindo..." COLOR_RESET;

    return 0;
}