#ifndef AUTOMOBILIS_H
#define AUTOMOBILIS_H

struct Automobilis {
    std::string gamintojas;
    std::string modelis;
    float variklioTuris;
    
    void setGamintojas(std::string gamintojas);

    std::string getGamintojas();

    void setModelis(std::string modelis);

    std::string getModelis();

    void setVariklioTuris(float variklioTuris);

    float getVariklioTuris();

    void print();
};

#endif
