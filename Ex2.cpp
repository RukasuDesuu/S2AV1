#include<iostream>
using namespace std;
/*
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
#### 1. Cadastro de Livros ####
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
https://github.com/RukasuDesuu/S2AV1
*/
class Livro{

private:
    //Atributos que precisam ser privados pra o encapsulamento
    string status;
    int code;
public:
    //Atributos e metodos que devem/podem ser publicos
    string title;
    string author;
    int edition;
    string publisher;
    int year;
    int npag;
    string fonte[2] = {"Comprado", "Doado"};
    string sts[3] = {"Disponivel", "Emprestado", "Arquivado"};
    string source;


    Livro(string t, int c, string a, int ed, string pub, int y, int sou, int sta){/*
    t = titulo, c = codigo, a = autor, ed = edicao, pub = editora, y = ano
    sou = indice da fonte 0 = comprado, 1 = doado
    sta = indice do status 0 = disponivel, 1 = emprestado, 2 = arquivado*/
        title = t;
        code = c;
        author = a;
        edition = ed;
        publisher = pub;
        year = y;
        source = fonte[sou];
        status = sts[sta];
    }

    void emprestar(int c){
        if (this -> code == c){
            status = sts[1];
            cout << "\nO status do livro foi alterado para: emprestado\n";
        }else{
            cout << "\nEste codigo nao condiz, tente novamente\n";
        }
    }

    void devolver(int c){
        if (this -> code == c){
            status = sts[0];
            cout << "\nO status do livro foi alterado para: disponivel \n";
        }else{
            cout << "\nEste codigo nao condiz, tente novamente\n";
        }
    }

    void arquivar(){
        status = sts[2];
        cout << "\nO status do livro foi alterado para: arquivado \n";
    }

    void mudar(int c){
        if (c > 9999 & c < 100000){
            code = c;
            cout << "\nO codigo foi alterado!\n";
        }else{
            cout <<"\nCodigo invalido, o codigo deve ter 5 digitos\n" << endl;
        }
    }

    void info(){
       cout << "\nTitulo: " << title << "\nCodigo: " << code << "\nAutor: " << author << "\nEdicao: " << edition << "\nEditora: " << publisher << "\nAno: " << year << "\nFonte: " << source << "\nStatus: " << status << "\nNo de Paginas: " << npag << "\n";
    }
};

int main(){
//Teste das classes e dos metodos
    Livro A("Guia dos Mochileiros da Galaxia", 14242, "Douglas Adams", 6, "Arqueiro", 2006, 0, 0);
    A.npag = 672;
    A.info();

    A.emprestar(142422);
    A.info();
    A.emprestar(14242);
    A.info();
    A.devolver(142421);
    A.info();
    A.devolver(14242);
    A.info();
    A.arquivar();
    A.info();
    A.mudar(4242);
    A.mudar(142421);
    A.mudar(42421);
    A.info();
}
