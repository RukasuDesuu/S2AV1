#include<iostream>
using namespace std;
/*
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
#### 4. Estação Meteorologica ####
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
https://github.com/RukasuDesuu/S2AV1
*/

class weatherstation{
private:
    //Atributos que precisam ser privados pra o encapsulamento
    bool status;
    int use;

public:
    //Atributos e metodos que devem/podem ser publicos
    int model;
    int nsensor;
    string tipo[2] = {"Analogico", "Digital"};
    string type;
    int frequencia[5] = {2,5,10,15,20};
    int frequency;
    float price;
    string energia[2] = {"Bateria", "Painel Solar"};
    string power;
    int disco[3] = {200,400,600};
    int disk;
    bool maintain;

    weatherstation(int m, int n, int t, int d){
        //m = modelo, n = Nº de sensores, t = Tipo de sensor [0=A, 1=D], d = Arm. do disco [0=200, 1=400,2=600]
        use = 0;
        if (m>999 & m<10000){
            model = m;
        }else{ cout << "\nModelo Invalido\n";}
        if (n>=2 & n<=4){
            nsensor = n;
        }else{ cout << "\nNo de Sensores Invalidos\n";}
        type = tipo[t];
        disk = disco[d];
        price = 0;
        status = "false";
        frequency = 0;
        maintain = true;
        string power = "";
    }

    void start(){
        cout << "\nLigando Estacao...\n";
        status = 1;
        cout << "Estacao Ligada!";
    }

    void endi(){
        cout << "\nDesligando Estacao...\n";
        status = 0;
        cout << "Estacao Desligada!";
    }

    void save(int dias){
        int tempDisk;
        tempDisk = 1*dias;
        if((tempDisk+use)>disk){
            cout << "\nERRO: Memoria Insuficiente no disco\n";
        }else{
            use += tempDisk;
            cout << "\nSUCESSO: Informacoes Salvas\n";
        }
    }

    void exporte(){
        cout << "\nExportando Informacoes...\n";
        use = 0;
        cout << "\nInformacoes Exportadas\n";
    }

    void info(){
     cout << "\nModelo: " << model << "\nNo de Sensores: " << nsensor << "\nTipo de Sensor: " << type << "\nPreco: R$" << price << "\nFonte de Energia: "<< power << "\nTamanho do Disco: " << disk <<endl;
    }
    int getUse(){
        return use;
    }
};

int main(){
    weatherstation A(1213, 3, 0, 0);
    A.start();
    A.save(100);
    A.save(100);
    A.save(10);
     cout << A.getUse() << endl;
    A.exporte();
    A.save(100);
    A.info();
    A.power = A.energia[0];
    A.info();
    A.price = 19000;
    A.info();
    A.endi();
}
