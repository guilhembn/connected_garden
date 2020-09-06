#include <ServerInterface.h>
#include <WiFiClientSecure.h>
#include <Config.h>

ServerInterface::ServerInterface(){

}

bool ServerInterface::sendMeasurement(const time_t timestamp, const uint16_t temperature, const uint16_t humidity){
    WiFiClientSecure client;
    String host = SERVER_HOST, url = SERVER_NEW_MEASUREMENT_URL;
    int port = SERVER_PORT;

    client.setInsecure();
    //Serial.printf("Using fingerprint '%s'\n", fingerprint);
    //httpsClient.setFingerprint(fingerprint);
    //httpsClient.setTimeout(15000); // 15 Seconds
    //delay(1000);
    
    Serial.print("HTTPS Connecting");
    int r=0; //retry counter
    while((!client.connect(host, port)) && (r < 30)){
        delay(100);
        Serial.print(".");
        r++;
    }
    if(r==30) {
        Serial.println("Connection failed");
    }
    else {
        Serial.println("Connected to web");
    }
    
    String getData;
    
    Serial.print("requesting URL: ");
    Serial.println("https://" + host + ":" + port + url);
    /*
        POST /url/to/measures HTTP/1.1
        Host: host.example
        Content-Type: application/x-www-form-urlencoded
        Content-Length: 47

        timestamp=1599400956&temperature=25&humidity=41
        Connection: close
        
    */
    String body = String("timestamp=") + timestamp + "&temperature=" + temperature + "&humidity=" + humidity;

    String header = String("POST ") + url + " HTTP/1.1\r\n" +
                "Host: " + host + "\r\n" +
                "Content-Type: application/x-www-form-urlencoded\r\n" +
                "Content-Length: " + body.length() + "\r\n\r\n";

    String close = String("\r\nConnection: close\r\n\r\n");

    String request = header + body + close;
    
    client.print(request);

    Serial.println(request);
    
    Serial.println("request sent");
                    
    while (client.connected()) {
        String line = client.readStringUntil('\n');
        Serial.println(line);
        if (line == "\r") {
        Serial.println("headers received");
        break;
        }
    }
    
    Serial.println("reply was:");
    Serial.println("==========");
    // TODO check if reply was success
    String line;
    while(client.available()){        
        line = client.readStringUntil('\n');  //Read Line by Line
        Serial.println(line); //Print response
    }
    Serial.println("==========");
    Serial.println("closing connection");
    client.stopAll();
    return true;
}