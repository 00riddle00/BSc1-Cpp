#ifndef AUTOMOBILIS_H
#define AUTOMOBILIS_H

#include "object.h"

class Automobilis : public Object {
    std::string gamintojas;
    std::string modelis;
    float variklioTuris;
    int gamybosMetai;
    int kaina;

    public:
        Automobilis();

        Automobilis(const std::string& gamintojas, const std::string& modelis, float variklioTuris, int gamybosMetai, int kaina);

        ~Automobilis();

        void setGamintojas(const std::string& gamintojas);

        std::string getGamintojas();

        void setModelis(const std::string& modelis);

        std::string getModelis();

        void setVariklioTuris(float variklioTuris);

        float getVariklioTuris();

        void setGamybosMetai(int gamybosMetai);

        int getGamybosMetai();

        void setKaina(int kaina);

        int getKaina();

        void print();

        void printToTextFile(std::ofstream& otf);

        void loadFromTextFile(std::ifstream& itf);
};

#endif
