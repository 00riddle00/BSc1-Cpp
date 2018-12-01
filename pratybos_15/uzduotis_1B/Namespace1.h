// prevent multiple inclusions of header file
#ifndef NAMESPACE_1
#define NAMESPACE_1

namespace Namespace {
// Time abstract data type definition
class Time 
{
public:
   Time( int = 0, int = 0, int = 0 ); // default constructor

   // set functions
   void setTime( int, int, int ); // set hour, minute, second
   void setHour( int ); // set hour (after validation)
   void setMinute( int ); // set minute (after validation)
   void setSecond( int ); // set second (after validation)

   // get functions
   int getHour(); // return hour
   int getMinute(); // return minute
   int getSecond(); // return second

   void printUniversal(); // output time in universal-time format HH:SS:MM
   void printStandard(); // output time in standard-time format HH:SS:MM AM or PM
private:
   int hour; // 0 - 23 (24-hour clock format)
   int minute; // 0 - 59
   int second; // 0 - 59
}; // end class Time

}

#endif

