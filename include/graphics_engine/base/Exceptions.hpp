#ifndef EXCEPTIONS_HPP_
#define EXCEPTIONS_HPP_

#include <exception>

class DisplayException : public std::exception{
    const char* what(){
        return "Unable to create display!";
    }
};

#endif
