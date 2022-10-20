#include<iostream>
using namespace std;
/*
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
#### 3. Cadastro de Carros ####
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
https://github.com/RukasuDesuu/S2AV1
*/

class Carro{

private:
    //Atributos que precisam ser privados pra o encapsulamento
    int number;
    float price;
    bool status; //se o carro se encontra disponível ou não disponível (number = 0)
public:
    //Atributos e metodos que devem/podem ser publicos
    string model;
    string producer;
    int year;
    string clutch;
    int capacity;
    string gas;
    bool novo; //carro novo ou usado (True ou False)

    Carro(string m, string p, int y, string c, float pr, int n){
      //m = modelo, p = fabricante, y = ano, c = t de cambio, pr = preço, n = nº de carros*
      model = m;
      producer = p;
      year = y;
      clutch = c;
      price = pr;
      number = n;
      if (number == 0){  //Verifica se o carro esta disponivel ou nao
        status = 0;
      }else{
        status = 1;
      }
    }

    void sell(){
        if (status){
            number--;
            cout << "Um Carro vendido!\n";
            if (number == 0){
                status = 0;
            }else{
                status = 1;
            }
        }else{
            cout << "\nEste Carro nao esta disponivel\n";
        }
    }

    void buy(){
        number++;
        status = 1;
        cout << "Um Carro comprado!\n";
    }

    void change(float p){
        price = p;
    }

    void getDisponibility(){
        cout << "\nStatus: ";
        if (status){
            cout << "Disponivel\n";
        }else{
            cout << "Indisponivel\n";
        }
        cout << "No de Carros: "<< number << endl;
    }

    void info(){
        string NoU;
        if (novo){
            NoU = "Novo";
        }else{ NoU = "Usado"; }
        cout << "\nModelo: " << model << "\nFabricante: " << producer << "\nAno: " << year<<"\nTipo de Cambio: " << clutch << "\nCapacidade: " << capacity << " pessoas" << "\nTipo de Combustivel: " <<gas << "\nNovo ou Usado: " << NoU << endl;
    }

};

int main(){
    //Teste da classe e de seus metodos
    Carro A("Corolla", "Toyota", 2012, "Automatico", 80000.00, 2);
    A.sell();
    A.sell();
    A.getDisponibility();
    A.sell();
    A.getDisponibility();
    A.buy();
    A.getDisponibility();
    A.change(82200.80);
    A.info();
    A.capacity = 5;
    A.gas = "Gasolina";
    A.novo = 0;
    A.info();
}
