#include <Datetime.h>

#include <stdio.h>

time_t Datetime::now(){
    _timeClient.update();
    return _timeClient.getEpochTime();
}

String Datetime::toStr(time_t time){
    return year(time) + "-" + String(monthShortStr(month(time))) + "-" + day(time) + " " + hour(time) + ":" + minute(time) + ":" + second(time);
}