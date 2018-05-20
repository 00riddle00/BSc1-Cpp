#include <iostream>
#include <iomanip>
#include "time.h"
using namespace std;

Time::Time( int h /*= 0*/, int m /*= 0*/, int s /*= 0*/ ) {
    if (h < 0 || h > 23) {
        throw IncorrectTimeException("Hour cannot be negative or above 23", "Time constructor");
    }
    hour = h;

    if (m < 0 || m > 59) {
        throw runtime_error("Minutes cannot be negative or above 59");
    }
    minute = m;

    if (s < 0 || s > 59) {
        throw runtime_error("Seconds cannot be negative or above 59");
    }
    second = s;
}

// set functions
void Time::setTime( int h, int m, int s ) {
    if (h < 0 || h > 23) {
        throw runtime_error("Hour cannot be negative or above 23");
    }
    hour = h;

    if (m < 0 || m > 59) {
        throw runtime_error("Minutes cannot be negative or above 59");
    }
    minute = m;

    if (s < 0 || s > 59) {
        throw runtime_error("Seconds cannot be negative or above 59");
    }
    second = s;
}

void Time::setHour( int h ) {
    if (h < 0 || h > 23) {
        throw runtime_error("Hour cannot be negative or above 23");
    }
    hour = h;
}

void Time::setMinute( int m ) {
    if (m < 0 || m > 59) {
        throw runtime_error("Minutes cannot be negative or above 59");
    }
    minute = m;
}

void Time::setSecond( int s ) {
    if (s < 0 || s > 59) {
        throw runtime_error("Seconds cannot be negative or above 59");
    }
    second = s;
}

// get functions
int Time::getHour() {
    return hour;
} 
int Time::getMinute() {
    return minute;
}

int Time::getSecond() {
    return second;
}

// output time in universal-time format HH:SS:MM
void Time::printUniversal() {
    cout << setfill('0') << setw(2) << hour << ":";
    cout << setfill('0') << setw(2) << minute << ":";
    cout << setfill('0') << setw(2) << second << endl;
}

// output time in standard-time format HH:SS:MM AM or PM
void Time::printStandard() { 
    char am_pm = 'A';

    if (hour == 0) {
        cout << 12 << ":";
    }
    else if (hour > 12) {
        cout << (hour % 12) << ":";
        am_pm = 'P';
    } else {
        cout << hour << ":";
    }
    cout << setfill('0') << setw(2) << minute << ":";
    cout << setfill('0') << setw(2) << second << " " << am_pm << "M" << endl;
}


IncorrectTimeException::IncorrectTimeException(const string& re, const string& fn)
        : range_error(re), function_name(fn) { }

const char* IncorrectTimeException::what() const noexcept {
    const string exc_message =  "[Incorrectly set time] [in function: " + function_name + "] " + range_error::what();
    //cout << exc_message << endl;
    return exc_message.c_str();
}




