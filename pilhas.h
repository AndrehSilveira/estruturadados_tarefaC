//Criando a pilha para armazenamento de double. A quantidade de elemento e limitada a variavel tamanho.
class PilhaInt{
    private:
        int topo;
        int tamanho;
        double *elementos;
        int id;
    public:
        //Construtor da pilha para definir o tamanho do array de elementos:
        void Inicia(int tamanhoI, int idI);
        //Metodo para inserir elemento na pilha:
        int empilhar(double elem);
        //Metodo para imprimir pilha:
        void imprimir();
        //Metodo para dsempilhar
        double desempilhar();
        //Getter da informacao topo
        int getTopo();
        //Metodo para limpar os elementos da pilha
        void limpar();
        //Metodo para inverter a pilha
        int inverter();
        //Metodo para encontrar o maior numero e menor numero da pilha e calcular a media de todos os elementos.
        int maiorMenorMedia();
        //Metodo para verificar se uma pilha é maior que outra pilha
        // Para verificar, nao e necessario percorrer a pilha pois temos o identificador do topo da mesma.
        int comparaTamPilha(int tetoPilha2);
        //Metodo para verificar se duas pilhas sao iguais
        int verificaIgualdade(PilhaInt pilha2);
        //Metodo para retornar os valores impares de uma pilha
        int retornaImpar();
};

//Criando a pilha para armazenamento de char. A quantidade de elemento e limitada a variavel tamanho.
class PilhaCha{
    private:
        int topo;
        int tamanho;
        char *elementos;
        int id;
    public:
        //Construtor da pilha para definir o tamanho do array de elementos.
        void Inicia(int tamanhoI, int idI);
        //Setter para a variavel topo, somente sera usado em casos de duplicacao de pilha
        int setTopo(int i);
        //Metodo para inserir elemento na pilha
        int empilhar(char elem);
        //Metodo para imprimir pilha
        void imprimir();
        //Metodo para dsempilhar
        char desempilhar();
        //Metodo para inverter a pilha
        int inverter();
        /*Metodo para verificar se e um palindromo
        * irei usar uma pilha auxiliar e inverter para verificar se 
        * ela persiste a memsa ou se ela e alterada
        */
        int palindromo();
        /** Metodo para inverter as palavras mas sem trocar a posicao delas
         * irei salvar os valores em um vetor de char, entao irei percorrer
         * ele ate encontrar o ' '(espaco), irei guardar a posicao do espaco
         * e inverter apenas aquele trecho. Outra forma mais trabalhosa de
         * se fazer esse metodo, seria criando 2 pilhas, uma seria usada para
         * armazenar a palavra e a outra seria usada para temporiariamente 
         * armazenar a frase, assim a cada espaco eu iria inverter a pilha
         * da palavra e depois inserir a palavra na pilha frase.
         */
        int inverteLetras();
};

/* Caso seja necessario verificar o tipo da pilha, util se fosse combinar as opcoes
Por exemplo: Permitir inverter ambas as pilhas
bool a = typeid(pilha).name() == typeid(PilhaInt).name();
bool b = typeid(pilha2).name() == typeid(PilhaInt).name();
*/
