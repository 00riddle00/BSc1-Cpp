#include <iostream>
#include <fstream>
#include <sstream>
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
    const string csvFile = argv[3];

    WriteToTextFile wt(textFile);
    wt.write(automobilis01.getGamintojas());
    wt.write(automobilis01.getModelis());
    wt.write(automobilis01.getVariklioTuris());
    wt.write(automobilis01.getGamybosMetai());
    wt.write(automobilis01.getKaina());
    wt.write("");
    wt.close();

    cout << separator;
    cout << "Automobilis1 irasytas i tesktini faila" << endl;
    cout << separator;

    WriteToBinaryFile wb(binaryFile);

    // track the length of string variables before writing them to a binary file
    const int len_gamintojas = automobilis01.getGamintojas().size();
    const int len_modelis = automobilis01.getModelis().size();

    wb.write(automobilis01.getGamintojas(), len_gamintojas);
    wb.write(automobilis01.getModelis(), len_modelis);
    wb.write(automobilis01.getVariklioTuris());
    wb.write(automobilis01.getGamybosMetai());
    wb.write(automobilis01.getKaina());
    wb.close();

    cout << separator;
    cout << "Automobilis1 irasytas i binarini faila" << endl;
    cout << separator;

    Automobilis automobilis02;
    cout << separator;
    cout << "Automobilis2 inicializuotas be parametru:" << endl;
    automobilis02.print();
    cout << separator;

    LoadFromTextFile lt(textFile);
    automobilis02.setGamintojas(lt.readline());
    automobilis02.setModelis(lt.readline());
    automobilis02.setVariklioTuris(lt.readline());
    automobilis02.setGamybosMetai(lt.readline());
    automobilis02.setKaina(lt.readline());
    lt.close();

    cout << separator;
    cout << "Automobilis2 uzpildytas parametrais is tekstinio failo:" << endl;
    automobilis02.print();
    cout << separator;

    Automobilis automobilis03;
    cout << separator;
    cout << "Automobilis3 inicializuotas be parametru:" << endl;
    automobilis03.print();

    LoadFromBinaryFile lb(binaryFile);

    automobilis03.setGamintojas(lb.readString(len_gamintojas));
    automobilis03.setModelis(lb.readString(len_modelis));
    automobilis03.setVariklioTuris(lb.readFloat());
    automobilis03.setGamybosMetai(lb.readInt());
    automobilis03.setKaina(lb.readInt());
    lb.close();

    cout << separator;
    cout << "Automobilis3 uzpildytas parametrais is binarinio failo:" << endl;
    automobilis03.print();
    cout << separator;

    /* write vector to CSV file */

	vector<Automobilis*> autos;
	autos.push_back(new Automobilis("BMW", "520", 2.5, 2000, 3000));
	autos.push_back(new Automobilis("Audi", "100", 2.0, 2000, 1500));
	autos.push_back(new Automobilis("Chrevrolet", "Colorado", 3.5, 2000, 3500));
	
	ofstream outFailas(csvFile, ios::out);
	
	if (! outFailas) { //perkrautas ! operatorius!
		cerr << "Failas neatidarytas rasymui" << endl;
	}
	else {
		for (size_t i = 0; i < autos.size(); i++)
			// ";" ir endl sukuria failo struktura (CSV su ; separatoriumi)
			outFailas << autos[i]->getGamintojas() <<  ";" << autos[i]->getModelis() << ";" << autos[i]->getVariklioTuris() << ";" << autos[i]->getGamybosMetai() << ";" << autos[i]->getKaina() << endl;
	}
	
	for (size_t i = 0; i < autos.size(); i ++)
		delete autos[i];
	
	outFailas.close();
    cout << separator;
    cout << "Vektorius su automobiliais irasytas i CSV faila" << endl;
    cout << separator;

    /* read CSV file to vector */

	ifstream inFailas(csvFile, ios::in);
	
	if (!inFailas) {
		cerr << "Failas neatidarytas skaitymui" << endl;
		return 1;
	}
	
	vector<Automobilis*> autos2;
	
	string eilute;
	while (getline(inFailas, eilute)) {
		istringstream eiluteStream(eilute);
		string g;
		getline(eiluteStream, g, ';');
		string m;
		getline(eiluteStream, m, ';');
		string VT;
		getline(eiluteStream, VT, ';');
		float vt = stof(VT);
        string GM;
		getline(eiluteStream, GM, ';');
        int gm = stoi(GM);
        string K;
		getline(eiluteStream, K, ';');
        int k = stoi(K);

		autos2.push_back(new Automobilis(g, m, vt, gm, k));
	}

    cout << separator;
    cout << "I vektoriu irasyti automobiliai is CSV failo" << endl;
    cout << separator;
	
	for (size_t i = 0; i < autos2.size(); i++ )
        cout << autos2[i]->getGamintojas() <<  " " << autos2[i]->getModelis() << " " << autos2[i]->getVariklioTuris() << " " << autos2[i]->getGamybosMetai() << " " << autos2[i]->getKaina() << endl;
	
	for (size_t i = 0; i < autos2.size(); i++ )
		delete autos2[i];
	
	inFailas.close();

}

