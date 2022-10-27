#include<iostream>
using namespace std;
/*
-=-=-=-=-=-=-=-=-=-=-=-=-=-
#### 1. Conta Bancaria ####
-=-=-=-=-=-=-=-=-=-=-=-=-=-
https://github.com/RukasuDesuu/S2AV1
*/
class ContaBanco{

private:
    //Atributos Privados que serão usados com encapsulamento
    float saldo;

public:
    //Atributos e Metodos que podem/devem ser públicos
    string nome;
    string dataNasc;
    string endereco;
    string agencia;
    int conta;
    float divida;
    string dataA;

    //Métodos:
    void deposito(float a){
        if (a > 0){  //Apenas sera atribuido o valor ao saldo se o valor for positivo
            saldo += a;
        }else{
            cout << "Valor invalido. Tente novamente"<<endl;
        }
    }

    void saque(float a){
        if (saldo >= a){  //Apenas sera subtraido o valor do saldo diretamente se o valor de saque for maior ou igual ao saldo
            saldo -= a;
        }else{
            cout << "Valor de saque maior que o saldo, voce ficara individado, tem certeza?"<< endl;
            cout << " 1.Sim \n 0.Cancelar\n";

            bool d;
            cin >> d;
            if (d == 1){
                saldo -= a;
                divida = -1*saldo;
                saldo = 0;
                cout << "Voce ficou com a divida de: R$";
                cout << divida << endl;
            }else if(d == 0){
                cout << "\n Acao cancelada";
            }
        }
    }

    void envio(float s, int c){
        if (c > 99999 && s>0){ //Verificação para conta ter 6 digitos
            this -> saldo -= s;
        }else if (s<0){
            cout << "Valor de Transferencia Invalida"<<endl;
        }else if (c <= 99999){
            cout << "Conta nao encontrada\n";
        }
    }

    void pago(){
        if (saldo > divida){
            saldo -= divida;
            divida = 0;
            cout << "Divida paga!\n";
        }else{
            cout << "Saldo menor que a divida \n";
        }
    }

    //encapsulamentos
    float getSaldo(){
        return saldo;
    }

    ContaBanco(string a, string b, string c){
        nome = a;
        dataNasc = b;
        endereco = c;
        saldo = 0;
        divida = 0;
    }
};

int main(){

    //Programa para testar a classe e seus metodos
    ContaBanco A("Lucas", "25/12/2002", "Segredo");
    A.deposito(1000);
    cout << "Saldo: " <<A.getSaldo()<<endl;
    A.saque(200);
    cout << "Saldo: " <<A.getSaldo()<<endl;
    A.saque(900);
    cout << "Saldo: " <<A.getSaldo()<<endl;
    A.deposito(1000);
    cout << "Saldo: " <<A.getSaldo()<<endl;
    A.envio(300, 123456);
    cout << "Saldo: " <<A.getSaldo()<<endl;
    A.envio(300, 12345); //numero de conta c/ <6 digitos
    cout <<"valor da divida: R$" << A.divida<<endl;
    A.pago();
    cout << "Saldo: " <<A.getSaldo()<<endl;
    cout << A.divida<<endl;
}
