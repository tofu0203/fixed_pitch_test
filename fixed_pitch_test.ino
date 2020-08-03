#include <Arduino.h>
#include <Servo.h>
float throttle = 0.0;
int throttle_command;
Servo brushlessmotor;
float rc = 0.0;
float a = 0.95;

void setup()
{
    Serial.begin(115200);
    brushlessmotor.attach(13);
    throttle_command = 1000;
    brushlessmotor.writeMicroseconds(throttle_command);
    delay(8000);
}

void loop()
{
    if (Serial.available())
    {
        char key;            // 受信データがあるか？
        key = Serial.read(); // 1文字だけ読み込む
        if (key == '+')
        {
            throttle_command += 10;
        }
        else if (key == '-')
        {
            throttle_command -= 10;
        }
    }

    Serial.print("throttle = ");
    Serial.println(throttle_command);
    brushlessmotor.writeMicroseconds(throttle_command);
    delay(10);
}
