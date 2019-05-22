#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);

using namespace std;

map< int, string > bichos;
map< string, map<string,double> > freq;

struct Resultado{
    int r1, r2, r3, r4, r5;
};

void inicializa(){
    bichos[1] = "avestruz"; bichos[2] = "avestruz"; bichos[3] = "avestruz"; bichos[4] = "avestruz";
    bichos[5] = "aguila"; bichos[6] = "aguila"; bichos[7] = "aguila"; bichos[8] = "aguila";
    bichos[9] = "burro"; bichos[10] = "burro"; bichos[11] = "burro"; bichos[12] = "burro";
    bichos[13] = "borboleta"; bichos[14] = "borboleta"; bichos[15] = "borboleta"; bichos[16] = "borboleta";
    bichos[17] = "cachorro"; bichos[18] = "cachorro"; bichos[19] = "cachorro"; bichos[20] = "cachorro";
    bichos[21] = "cabra"; bichos[22] = "cabra"; bichos[23] = "cabra"; bichos[24] = "cabra";
    bichos[25] = "carneiro"; bichos[26] = "carneiro"; bichos[27] = "carneiro"; bichos[28] = "carneiro";
    bichos[29] = "camelo"; bichos[30] = "camelo"; bichos[31] = "camelo"; bichos[32] = "camelo";
    bichos[33] = "cobra"; bichos[34] = "cobra"; bichos[35] = "cobra"; bichos[36] = "cobra";
    bichos[37] = "coelho"; bichos[38] = "coelho"; bichos[39] = "coelho"; bichos[40] = "coelho";
    bichos[41] = "cavalo"; bichos[42] = "cavalo"; bichos[43] = "cavalo"; bichos[44] = "cavalo";
    bichos[45] = "elefante"; bichos[46] = "elefante"; bichos[47] = "elefante"; bichos[48] = "elefante";
    bichos[49] = "galo"; bichos[50] = "galo"; bichos[51] = "galo"; bichos[52] = "galo";
    bichos[53] = "gato"; bichos[54] = "gato"; bichos[55] = "gato"; bichos[56] = "gato";
    bichos[57] = "jacare"; bichos[58] = "jacare"; bichos[59] = "jacare"; bichos[60] = "jacare";
    bichos[61] = "leao"; bichos[62] = "leao"; bichos[63] = "leao"; bichos[64] = "leao";
    bichos[65] = "macaco"; bichos[66] = "macaco"; bichos[67] = "macaco"; bichos[68] = "macaco";
    bichos[69] = "porco"; bichos[70] = "porco"; bichos[71] = "porco"; bichos[72] = "porco";
    bichos[73] = "pavao"; bichos[74] = "pavao"; bichos[75] = "pavao"; bichos[76] = "pavao";
    bichos[77] = "peru"; bichos[78] = "peru"; bichos[79] = "peru"; bichos[80] = "peru";
    bichos[81] = "touro"; bichos[82] = "touro"; bichos[83] = "touro"; bichos[84] = "touro";
    bichos[85] = "tigre"; bichos[86] = "tigre"; bichos[87] = "tigre"; bichos[88] = "tigre";
    bichos[89] = "urso"; bichos[90] = "urso"; bichos[91] = "urso"; bichos[92] = "urso";
    bichos[93] = "veado"; bichos[94] = "veado"; bichos[95] = "veado"; bichos[96] = "veado";
    bichos[97] = "vaca"; bichos[98] = "vaca"; bichos[99] = "vaca"; bichos[0] = "vaca";
}

int main(){_
    Resultado result;
    int ant, prox;
    double acm;
    double soma=0;

    inicializa();
    cin>>ant;
    while(cin>>prox){
        string bicho1 = bichos[ant%100];
        string bicho2 = bichos[prox%100];

        freq[bicho1][bicho2]++;
        ant = prox;
    }
    for(auto i : freq){
        acm = 0.0;
        soma=0;
        for(auto j : freq[i.first]){
            // cout<<freq[i.first][j.first]<<" ";
            acm+=freq[i.first][j.first];
        }
        for(auto j : freq[i.first]){
            freq[i.first][j.first] = freq[i.first][j.first]/acm;
            // soma+=freq[i.first][j.first];
            cout<<freq[i.first][j.first]<<" ";
            // printf("%.2lf ",freq[i.first][j.first]);
        }
        cout<<endl;
        // cout<<soma<<endl<<endl;
    }
    return 0;
}
