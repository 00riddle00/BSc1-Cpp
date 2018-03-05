#ifndef __INPUT_H_
#define __INPUT_H_

#define MAX_PARAMS 2

class Input {
    int count;
    bool valid;

    public:
        // add additional space for one extra parameter in
        // order for the validation to work
        // (ie error "too many parameters" is displayed)
        std::string params[MAX_PARAMS + 1];

        Input();

        void setParam(int, const std::string&);

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
