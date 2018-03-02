#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "automobilis.h"
#include "write_to_binary_file.h"
#include "load_from_binary_file.h"
#include "write_to_text_file.h"
#include "load_from_text_file.h"
using namespace std;


int main(int argc, char *argv[]) {

    Automobilis automobilis01("Toyota", "Avensis", 1.8, 2000, 2500);

    string separator = "-------------------------\n";

    cout << separator;
    cout << "Automobilis1:" << endl;
    automobilis01.print();
    cout << separator;

    const string textFile = argv[1];
    const string binaryFile = argv[2];

    WriteToTextFile wt(textFile);
    wt.write(automobilis01.getGamintojas());
    wt.write(automobilis01.getModelis());
    wt.write(automobilis01.getVariklioTuris());
    wt.write(automobilis01.getGamybosMetai());
    wt.write(automobilis01.getKaina());
    wt.write("");
    wt.close();

    WriteToBinaryFile wb(binaryFile);

    const int len_gamintojas = automobilis01.getGamintojas().size();
    const int len_modelis = automobilis01.getModelis().size();

    wb.write(automobilis01.getGamintojas(), len_gamintojas);
    wb.write(automobilis01.getModelis(), len_modelis);
    wb.write(automobilis01.getVariklioTuris());
    wb.write(automobilis01.getGamybosMetai());
    wb.write(automobilis01.getKaina());
    wb.close();

    Automobilis automobilis02;

    LoadFromTextFile lt(textFile);
    automobilis02.setGamintojas(lt.readline());
    automobilis02.setModelis(lt.readline());
    automobilis02.setVariklioTuris(lt.readline());
    automobilis02.setGamybosMetai(lt.readline());
    automobilis02.setKaina(lt.readline());
    lt.close();

    cout << separator;
    cout << "Automobilis2:" << endl;
    automobilis02.print();
    cout << separator;

    Automobilis automobilis03;

    LoadFromBinaryFile lb(binaryFile);

    automobilis03.setGamintojas(lb.readString(len_gamintojas));
    automobilis03.setModelis(lb.readString(len_modelis));
    automobilis03.setVariklioTuris(lb.readFloat());
    automobilis03.setGamybosMetai(lb.readInt());
    automobilis03.setKaina(lb.readInt());
    lb.close();

    cout << separator;
    cout << "Automobilis3:" << endl;
    automobilis03.print();
    cout << separator;
}

