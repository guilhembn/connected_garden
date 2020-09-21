#include <Datetime.h>

#include <stdio.h>

time_t Datetime::now(){
    for (unsigned int i=0; i < NTP_MAX_RETRIES; i++){
        if (_timeClient.update()){
            return _timeClient.getEpochTime();
        }
        delay(500);
    }
    return -1.0;
}

time_t Datetime::estimatedNow(const time_t sleepTime, const unsigned long sleepDuration){
    return sleepTime + sleepDuration + millis() / 1000;
}

String Datetime::toStr(time_t time){
    return year(time) + "-" + String(monthShortStr(month(time))) + "-" + day(time) + " " + hour(time) + ":" + minute(time) + ":" + second(time);
}