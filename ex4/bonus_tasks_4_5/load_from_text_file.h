#ifndef __LOAD_FROM_TEXT_FILE_H_
#define __LOAD_FROM_TEXT_FILE_H_

class LoadFromTextFile {
    std::ifstream itf;
    std::string filename;

    public:
        LoadFromTextFile(const std::string&);
        ~LoadFromTextFile();

        std::string readline();
        void close();
};

#endif

