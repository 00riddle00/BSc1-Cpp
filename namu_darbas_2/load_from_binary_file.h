#ifndef __LOAD_FROM_BINARY_FILE_H_
#define __LOAD_FROM_BINARY_FILE_H_

class LoadFromBinaryFile {
    std::ifstream itf;
    std::string filename;

    public:
        explicit LoadFromBinaryFile(const std::string&);
        ~LoadFromBinaryFile();

        std::string readString(int);
        int readInt();
        float readFloat();
        void close();
};

#endif
