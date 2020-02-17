#include <iostream>

using namespace std;

int main(){

    double cost = 0;
    double time = 0;
    double path_els = 0; 
    double avg_cost = 0;
    double avg_time = 0;
    double avg_path_els = 0;

    for (int i = 0; i < 5; i++){
        cin >> cost;
        cin >> path_els;
        cin >> time;

        avg_cost += cost;
        avg_time += time;
        avg_path_els += path_els;
    }

    avg_cost /= 5;
    avg_path_els /= 5;
    avg_time /= 5;


    cout << "Metricas: " << endl;
    cout << "Media de custos: " << avg_cost << endl;
    cout << "Número médio de elementos que formam o caminho: " << avg_path_els << endl;
    cout << "Media de tempo: " << avg_time*1000 << "ms" << endl;

    // calcular outras metricas aqui ;
    // sugetoes : desvio padrao, variancia, valor esperado,...

}