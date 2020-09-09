#include <iostream>
using namespace std;


class Siuntinys {
    // siuntejo duomenys
    string s_vardas;
    string s_pavarde;
    string s_adresas;
    string s_miestas;
    string s_pastoKodas;

    // gavejo duomenys
    string g_vardas;
    string g_pavarde;
    string g_adresas;
    string g_miestas;
    string g_pastoKodas;

    protected:
        float siuntinioSvoris;
        float siuntimoKaina100g;

    public:
        Siuntinys(
                const string& s_va,
                const string& s_pa,
                const string& s_ad,
                const string& s_mi,
                const string& s_pk,
                const string& g_va,
                const string& g_pa,
                const string& g_ad,
                const string& g_mi,
                const string& g_pk,
                float svoris,
                float kaina100g
            ) 
        : s_vardas(s_va),
          s_pavarde(s_pa),
          s_adresas(s_ad),
          s_miestas(s_mi),
          s_pastoKodas(s_pk),
        
          g_vardas(g_va),
          g_pavarde(g_pa),
          g_adresas(g_ad),
          g_miestas(g_mi),
          g_pastoKodas(g_pk) {

              if (svoris > 0) {
                  siuntinioSvoris = svoris;
              } 
              if (kaina100g > 0) {
                  siuntimoKaina100g = kaina100g;
              }

            cout << "Siuntinys object is created with given parameters" << endl;
        }

        ~Siuntinys() {
            cout << "Siuntinys object is destroyed" << endl;
        }

        float apskaiciuotiKaina() {
            return (siuntinioSvoris / 100) * siuntimoKaina100g;
        }

};

class StandartinisSiuntinys : public Siuntinys {
    float mokestis;

    public:
    StandartinisSiuntinys (
        const string& s_va,
        const string& s_pa,
        const string& s_ad,
        const string& s_mi,
        const string& s_pk,
        const string& g_va,
        const string& g_pa,
        const string& g_ad,
        const string& g_mi,
        const string& g_pk,
        float svoris,
        float kaina100g,
        float mok
    )
    : Siuntinys(
        s_va,
        s_pa,
        s_ad,
        s_mi,
        s_pk,
        g_va,
        g_pa,
        g_ad,
        g_mi,
        g_pk,
        svoris,
        kaina100g
      ), 
      mokestis(mok) { 
            
            cout << "Standartinis siuntinys object is created with given parameters" << endl;
    }

    ~StandartinisSiuntinys() {
        cout << "Standartinis siuntinys object is destroyed" << endl;
    }

    float apskaiciuotiKaina() {
        return Siuntinys::apskaiciuotiKaina() + mokestis;
    }
};


class GreitasisSiuntinys : public Siuntinys {
    float papildomaKaina100g;

    public:
    GreitasisSiuntinys (
        const string& s_va,
        const string& s_pa,
        const string& s_ad,
        const string& s_mi,
        const string& s_pk,
        const string& g_va,
        const string& g_pa,
        const string& g_ad,
        const string& g_mi,
        const string& g_pk,
        float svoris,
        float kaina100g,
        float pk
    )
    : Siuntinys(
        s_va,
        s_pa,
        s_ad,
        s_mi,
        s_pk,
        g_va,
        g_pa,
        g_ad,
        g_mi,
        g_pk,
        svoris,
        kaina100g
      ), 
      papildomaKaina100g(pk) { 

        cout << "Greitasis siuntinys object is created with given parameters" << endl;
    }

    ~GreitasisSiuntinys() {
        cout << "Greitasis siuntinys object is destroyed" << endl;
    }

    float apskaiciuotiKaina() {
        return (siuntinioSvoris / 100) * (siuntimoKaina100g + papildomaKaina100g) ;
    }

};


int main() {
    StandartinisSiuntinys stdSiuntinys(
            // siuntejas
            "Tomas",
            "Giedraitis",
            "Vilniaus g. 13-84",
            "Vilnius", 
            "02234",

            // gavejas
            "Vardas",
            "Pavarde",
            "Kauno g. 13-96",
            "Kaunas",
            "01234",

            //svoris
            520.0,
            // siuntimoKaina100g
            2.45,
            // mokestis
            1.25
        );

    GreitasisSiuntinys greitSiuntinys(
            // siuntejas
            "Romas",
            "Jonaitis",
            "Vilniaus g. 13-48",
            "Vilnius", 
            "02334",

            // gavejas
            "Tomas",
            "Tomaitis",
            "Kauno g. 13-93",
            "Kaunas",
            "01224",

            //svoris
            520.0,
            // siuntimoKaina100g
            2.45,
            // papildomaKaina100g
            2.05
        );

    cout << "---------------------" << endl;
    cout << "Standartinio siunitnio kaina: " << stdSiuntinys.apskaiciuotiKaina() << endl;
    cout << "Greitojo siunitnio kaina: " << greitSiuntinys.apskaiciuotiKaina() << endl;
    cout << "---------------------" << endl;

}
