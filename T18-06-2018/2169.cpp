#include <bits/stdc++.h>
#define MAX 10010

using namespace std;

int dp[MAX][MAX];

struct pack{
    string nome;
    int balas;
    float potencia;
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool primeiro = true;

    pack disponiveis[8];
    map<string, float> armas;
    map<string, int> monstros;

    armas["HANDGUN"] = 2;
    armas["RED9"] = 3.5;
    armas["BLACKTAIL"] = 3.5;
    armas["MATILDA"] = 2;
    armas["HANDCANNON"] = 60;
    armas["STRIKER"] = 12;
    armas["TMP"] = 1.2;
    armas["RIFLE"] = 12;

    monstros["GANADOS"] = 50;
    monstros["COBRAS"] = 40;
    monstros["ZEALOT"] = 75;
    monstros["COLMILLOS"] = 60;
    monstros["GARRADOR"] = 125;
    monstros["LASPLAGAS"] = 100;
    monstros["GATLINGMAN"] = 150;
    monstros["REGENERATOR"] = 250;
    monstros["ELGIGANTE"] = 500;
    monstros["DR.SALVADOR"] = 350;

    int n_armas, n_monstros, qtd_monstro, max_municao;
    string aux_monstro;

    while(cin >> n_armas){

        if(!primeiro) cout << endl;
        primeiro = false;

        int resistencia_monstros = 0;

        for(int i = 1; i <= n_armas; i++){
            cin >> disponiveis[i].nome >> disponiveis[i].balas;
            disponiveis[i].potencia = armas[disponiveis[i].nome];
        }

        cin >> n_monstros;
        for(int i = 0; i < n_monstros; i++){
            cin >> aux_monstro >> qtd_monstro;
            resistencia_monstros += monstros[aux_monstro]*qtd_monstro;
        }

        cin >> max_municao;

        for(int i = 0; i <= n_armas; i++){
            for(int j = 0; j <= max_municao; j++){
                if(!j || !i)dp[i][j] = 0;
                else{
                    if(disponiveis[i].balas > j){
                        dp[i][j] = dp[i-1][j];
                    }else{
                        dp[i][j] = disponiveis[i].balas*disponiveis[i].potencia + dp[i-1][j-disponiveis[i].balas] > dp[i-1][j] ? disponiveis[i].balas*disponiveis[i].potencia + dp[i-1][j-disponiveis[i].balas]:dp[i-1][j];
                    }
                }
            }
        }
        if(dp[n_armas][max_municao] >= resistencia_monstros) cout << "Missao completada com sucesso" << endl;
        else cout << "Your Are Dead" << endl;
    }

    return 0;
}

