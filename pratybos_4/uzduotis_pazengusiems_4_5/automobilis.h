#ifndef AUTOMOBILIS_H
#define AUTOMOBILIS_H

class Automobilis {
    std::string gamintojas;
    std::string modelis;
    float variklioTuris;
    int gamybosMetai;
    int kaina;

    public:
        Automobilis();

        Automobilis(const std::string& gamintojas, const std::string& modelis, float variklioTuris, int gamybosMetai, int kaina);
        Automobilis(const std::string& gamintojas, const std::string& modelis, const std::string& variklioTuris, const std::string& gamybosMetai, const std::string& kaina);

        ~Automobilis();

        void setGamintojas(const std::string& gamintojas);

        std::string getGamintojas();

        void setModelis(const std::string& modelis);

        std::string getModelis();

        void setVariklioTuris(float variklioTuris);

        void setVariklioTuris(const std::string& variklioTuris);

        float getVariklioTuris();

        void setGamybosMetai(int gamybosMetai);

        void setGamybosMetai(const std::string& gamybosMetai);

        int getGamybosMetai();

        void setKaina(int kaina);

        void setKaina(const std::string& kaina);

        int getKaina();

        void print();
};

#endif
