#ifndef __INPUT_H_
#define __INPUT_H_

#define MAX_PARAMS 2

class Input {
    int count;
    bool valid;
    bool cmd;

    public:
        // add additional space for one extra parameter in
        // order for the validation to work
        // (ie error "too many parameters" is displayed)
        std::string params[MAX_PARAMS + 1];

        // shows whether the input is gathered from a command line
        // at the time of starting the program (true), or it is
        // entered during the program runtime by the user (false)

        Input();

        void setParam(int, const std::string&);

        void setCMD();

        bool isCMD();

        int getCount();

        bool isValid();

        // ::params: input - input structure is modified
        void get_input();

        // ::params: input - input structure 
        // ::return: 1 if input is valid, else 0
        bool validate_input();

        // set input value and input count to 0, nullify pointers 
        // inside input->params
        //
        // ::params: input - input structure is modified
        void clear_input();
};

#endif
