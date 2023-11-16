#include <iostream>
using namespace std;

class Time_ {

private:

    unsigned short hours_;
    unsigned short minutes_;
    unsigned short seconds_;

public:

    void setHours(unsigned short hours) {
        hours_ = hours;
    }

    void setMinutes(unsigned short minutes) {
        minutes_ = minutes;
    }

    void setSeconds(unsigned short seconds) {
        seconds_ = seconds;
    }

    unsigned short getHours()
    {
        return hours_;
    }

    unsigned short getMinutes()
    {
        return minutes_;
    }

    unsigned short getSeconds()
    {
        return seconds_;
    }

};

int main()
{
    Time_ Todaytime;
    unsigned short hours;
    unsigned short minutes;
    unsigned short seconds;
    cout << "Type hours: ";
    cin >> hours;
    cout << "Type minutes: ";
    cin >> minutes;
    cout << "Type seconds: ";
    cin >> seconds;

    if (hours > 25)
    {
        cout << "Error, there are only 24 hours in a day \n";
        return 1;
    }
    else
    {
        Todaytime.setHours(hours);
        cout << "Time is " << Todaytime.getHours() << ":";
    }

    if (minutes > 60)
    {
        cout << "Error, there are only 60 minutes in a hour \n";
        return 1;
    }
    else
    {
        Todaytime.setMinutes(minutes);
        cout << Todaytime.getMinutes() << ":";
    }

    if (seconds > 60)
    {
        cout << "Error, there are only 60 seconds in a minute \n";
        return 1;
    }
    else
    {
        Todaytime.setSeconds(seconds);
        cout << Todaytime.getSeconds();
    }

    return 0;

}


