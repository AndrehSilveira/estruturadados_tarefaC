#include <cstdlib>
#include <iostream>
#include <math.h>
#include "pilhas.h"

#define COLOR_VERMELHO     "\x1b[31m"
#define COLOR_VERDE        "\x1b[32m"
#define COLOR_AMARELO      "\x1b[33m"
#define COLOR_RESET        "\x1b[0m"

using namespace std;

void PilhaInt::Inicia(int tamanhoI, int idI){
            topo = -1;
            tamanho = tamanhoI;
            //Alocando o total de memoria equivalente ao tamanho inserido
            elementos = (double*) malloc(sizeof(double)*tamanhoI);
            //Id que sera usado posteriormente para operacoes
            id = idI;
        }
        //Metodo para inserir elemento na pilha
        int PilhaInt::empilhar(double elem){
            //Verifica se ela ainda possui espaco
            if(topo+1 == tamanho){
                //Caso nao possua, retorna falso
                return 0;
            }else{
                //Se ela possuir espaco, incrementamos o topo
                topo++;
                //E adicionamos o elemento
                elementos[topo] = elem;
            }
            //No final se tudo ocorrer como planejado, retornamos verdadeiro
            return 1;
        }
        //Metodo para imprimir pilha
        void PilhaInt::imprimir(){
            cout << COLOR_VERDE "------------ PILHA id: " << id << "------------\n";
            //Percorre cada elemento da pilha
            for(int i = topo; i >= 0 ;i--){
                cout << elementos[i];
                if(i == topo){
                    //Apenas demosntra qual e o topo
                    cout << " <- TOPO\n";
                }else{
                    cout << endl;
                }
            }
            cout << "--------------------------------\n" COLOR_RESET;
        }
        //Metodo para dsempilhar
        double PilhaInt::desempilhar(){
            //Variavel para salvar o numero que esta sendo retirado
            double num = elementos[topo];
            topo--;//Diminuindo o topo
            //Nao e necessario limpar memoria pois o espaco pode ser usado novamente
            return num;
        }
        //Getter da informacao topo
        int PilhaInt::getTopo(){
            return topo;
        }
        //Metodo para limpar os elementos da pilha
        void PilhaInt::limpar(){
            //Liberando memoria
            free(elementos);
            //Criando novamente o array
            elementos = (double*) malloc(sizeof(double)*tamanho);
        }
        //Metodo para inverter a pilha
        int PilhaInt::inverter(){
            //Array auxiliar para salvar a pilha original e topo original
            int topoAux = topo;
            double *auxElem = (double*) malloc(sizeof(double)*(topo+1)); 
            //Copiando os elementos da pilha para auxElem
            for(int i = 0; i <= topoAux;i++){
                auxElem[i] = desempilhar();
            }
            //Inserindo os valores novamente usando a pilha auxiliar
            while(topoAux != topo){
                empilhar(auxElem[topo+1]);
            }
            return 1;
        }
        //Metodo para encontrar o maior numero e menor numero da pilha e calcular a media de todos os elementos.
        int PilhaInt::maiorMenorMedia(){
            double menor;
            double maior;
            double soma=0;

            //Array auxiliar para salvar a pilha original
            int topoAux = topo;
            double *auxElem = (double*) malloc(sizeof(double)*(topo+1)); 

            //Percorrendo os elementos da pilha e copiando eles para auxElem
            for(int i = 0; i <= topoAux;i++){
                auxElem[i] = desempilhar();
                //Fazendo a verificacao de qual e o maior valor e o menor valor
                if(i == 0){
                    maior = auxElem[i];
                    menor = auxElem[i];
                }else{
                    if(auxElem[i] > maior)
                    {
                        maior = auxElem[i];
                    }
                    if(auxElem[i] < menor)
                    {
                        menor = auxElem[i];
                    }
                }
                //Somando para o calculo da aritmetica
                soma+=auxElem[i];
            }

            //Retornando os valores para a pilha
            while(topoAux != -1){
                empilhar(auxElem[topoAux]);
                topoAux--;
            }
            //Imprimindo os valores que foram encontrados.
            cout << COLOR_VERDE "Maior valor: " << maior << endl;
            cout << "Menor valor: " << menor << endl;
            cout << "Media dos valores: " << soma/(topo+1) << COLOR_RESET << endl;
            return 1;
        }
        /*Metodo para verificar se uma pilha é maior que outra pilha
        * Para verificar, nao e necessario percorrer a pilha pois temos
        * o identificador do topo da mesma.
        */
        int PilhaInt::comparaTamPilha(int tetoPilha2){
            if(tetoPilha2 > topo){
                return 1;
            }else if(tetoPilha2 < topo){
                return 0;
            }else{
                return 2;
            }
        }
        //Metodo para verificar se duas pilhas sao iguais
        int PilhaInt::verificaIgualdade(PilhaInt pilha2){
            //Ate entao as pilhas sao consideradas como iguais e retorna verdadeiro
            int iguais = 1;
            /* Esse metodo e chamado por uma pilha auxiliar nunca pela pilha original
            *  e dessa forma, podemos desempilhar ela sem armazenar os valores. Nao
            *  e necessario fazer a verificacao de tamanho por aqui, na funcao main
            *  essa verificacao ja foi realizada antes de chamar a funcao verificaIgualdade.
            */
            while(topo != -1){
                //Desempilho ambas as pilhas e vejo se o valor e igual ate chegarmos no inicio dela
                if(desempilhar() != pilha2.desempilhar()){
                   iguais = 0;
                   //Nao e necessario percorrer o restante da pilha
                   break;
                }
            }
            return iguais;
        }
        //Metodo para retornar os valores impares de uma pilha
        int PilhaInt::retornaImpar(){
            //Variavel auxiliar para armazenar o numero retirado do topo
            double auxNum = 0;
            //Flag para sabermos se retornamos algum numero ou se todos sao pares
            int flag = 0;
            //Irei percorrer a pilha desempilhando a mesma
            while(topo != -1)
            {   
                auxNum = desempilhar();
                //Se o valor nao for divisivel por 2, considero ele com par e imprimo ele;
                if(fmod(auxNum,2) != 0){
                    cout << auxNum << "\t";
                    //Altero a flag para informar que encontramos um impar
                    flag++;
                };
            }
            if(!flag){
                cout << COLOR_VERDE "Pilha nao possui numeros pares.\n" COLOR_RESET;
            }
            cout << endl;
            return 1;
        }

        //Construtor da pilha para definir o tamanho do array de elementos.
void PilhaCha::Inicia(int tamanhoI, int idI){
    topo = -1;
    tamanho = tamanhoI;
    elementos = (char*) malloc(sizeof(char)*tamanhoI);
    //O mesmo ID que consta em pilhaInt para as escolhas.
    id = idI;
    }
        //Setter para a variavel topo, somente sera usado em casos de duplicacao de pilha
        int PilhaCha::setTopo(int i){
            topo = i;
            return 1;
        }
        //Metodo para inserir elemento na pilha
        int PilhaCha::empilhar(char elem){
            //Empilha ate que o topo seja o tamanho
            if((topo+1) == tamanho){
                //Se o topo for o tamanho, a pilha esta cheia e retorna falso
                return 0;
            }else{
                //Se o topo nao for igual, inserimos o valor no topo da pilha
                topo++;
                elementos[topo] = elem;
            }
            return 1;
        }
        //Metodo para imprimir pilha
        void PilhaCha::imprimir(){
            cout << COLOR_VERDE "------------ PILHA id: " << id << "------------\n";
            for(int i = topo; i >= 0 ;i--){
                cout << elementos[i];
                if(i == topo){
                    cout << " <- TOPO\n";
                }else{
                    //cout << endl;
                }
            }
            cout << "--------------------------------\n" COLOR_RESET;
        }
        //Metodo para dsempilhar
        char PilhaCha::desempilhar(){
            //Variavel para salvar o char que esta sendo retirado
            char cha = elementos[topo];
            topo--;//Diminuindo o topo
            //Nao e necessario limpar memoria pois o espaco pode ser usado novamente
            return cha;
        }
        //Metodo para inverter a pilha
        int PilhaCha::inverter(){
            //Array auxiliar para salvar a pilha original
            int topoAux = topo;
            char *auxElem = (char*) malloc(sizeof(char)*(topo+1)); 
            //Copiando os elementos da pilha para auxElem
            for(int i = 0; i <= topoAux;i++){
                auxElem[i] = desempilhar();
            }
            //Inserindo os valores novamente usando a pilha auxiliar
            while(topoAux != topo){
                empilhar(auxElem[topo+1]);
            }
            return *auxElem;
        }
        /*Metodo para verificar se e um palindromo
        * irei usar uma pilha auxiliar e inverter para verificar se 
        * ela persiste a memsa ou se ela e alterada
        */
        int PilhaCha::palindromo(){
            PilhaCha aux;
            PilhaCha aux2;
            aux.Inicia(tamanho,-1);
            aux2.Inicia(tamanho,-1);
            //Copia os valores do espaço de memoria que esta a pilha original.
            memcpy(aux.elementos,elementos,sizeof(elementos));
            memcpy(aux2.elementos,elementos,sizeof(elementos));
            //Definindo os topos
            aux.setTopo(topo);
            aux2.setTopo(topo);
            //Invertemos uma pilha
            aux2.inverter();
            //Desempilhamos
            while(aux.topo != -1){
                char a = aux.desempilhar();
                char a2 = aux2.desempilhar();
                if(a != a2){
                    return 0;
                }
            }
            return 1;
        }
        /** Metodo para inverter as palavras mas sem trocar a posicao delas
         * irei salvar os valores em um vetor de char, entao irei percorrer
         * ele ate encontrar o ' '(espaco), irei guardar a posicao do espaco
         * e inverter apenas aquele trecho. Outra forma mais trabalhosa de
         * se fazer esse metodo, seria criando 2 pilhas, uma seria usada para
         * armazenar a palavra e a outra seria usada para temporiariamente 
         * armazenar a frase, assim a cada espaco eu iria inverter a pilha
         * da palavra e depois inserir a palavra na pilha frase.
         */
        int PilhaCha::inverteLetras(){
            //Variavel auxiliar para guardar a posicao inicial da palavra
            int inicioP = topo;
            //Variavel auxiliar para armazenar a posicao final da palavra
            int fimP = 0;//Lembrando que na pilha, o fim da palavra acaba sendo o inicio da mesma
            //Variavel para armazenar temporiamente o char para fazer a troca
            char aux = ' ';//32
            //Array auxiliar para salvar a pilha original e topo original
            int topoAux = topo;
            char *auxElem = (char*) malloc(sizeof(char)*(topo+1)); 
            //Copiando os elementos da pilha para auxElem
            for(int i = topoAux; i >= 0;i--){
                //Primeiro eu tiro o elemento do topo
                auxElem[i] = desempilhar();
                //Verifico se e um espaco ou se e o inicio da pilha
                //Ambos os casos significa que eu terminei uma palavra
                if(auxElem[i] == 32 || i == 0){
                    //Caso seja o inicio da pilha, irei inverter desde o inicio
                    //Do contrario, irei inverter do espaco mais um
                    fimP = (i==0)? 0:i+1;
                    while(fimP != inicioP){
                        aux = auxElem[fimP];
                        auxElem[fimP] = auxElem[inicioP];
                        auxElem[inicioP] = aux;
                        fimP++;
                        if(fimP == inicioP){
                            break;
                        }else{
                            inicioP--;
                        }
                    }
                    inicioP = i-1;
                }
            }
            //Inserindo os valores novamente usando a pilha auxiliar
            while(topoAux != topo){
                empilhar(auxElem[topo+1]);
            }
            return 1;
        }

/* Caso seja necessario verificar o tipo da pilha, util se fosse combinar as opcoes
Por exemplo: Permitir inverter ambas as pilhas
bool a = typeid(pilha).name() == typeid(PilhaInt).name();
bool b = typeid(pilha2).name() == typeid(PilhaInt).name();
*/

//Imprime todas as pilhas
void imprimePilhasInt(int idPilhaInt, int* arrInt[]){
    //Imprimindo todas as pilhas de inteiros
    for(int i = 0; i < idPilhaInt;i++){
        PilhaInt *_pilha = (PilhaInt *) arrInt[i];
        _pilha->imprimir();
    }
}

//Imprime todas as pilhas
void imprimePilhasCha(int idPilhaCha, int* arrCha[]){
    //Imprimindo todas as pilhas de inteiros
    for(int i = 0; i < idPilhaCha;i++){
        PilhaCha *_pilha = (PilhaCha *) arrCha[i];
        _pilha->imprimir();
    }
}