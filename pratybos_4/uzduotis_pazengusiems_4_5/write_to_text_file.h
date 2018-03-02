#ifndef __WRITE_TO_TEXT_FILE_H_
#define __WRITE_TO_TEXT_FILE_H_

class WriteToTextFile {
    std::ofstream otf;
    std::string filename;

    public:
        WriteToTextFile(const std::string&);
        ~WriteToTextFile();

        void write(const std::string&);
        void write(float); 
        void write(int);
        void close();
};

#endif
