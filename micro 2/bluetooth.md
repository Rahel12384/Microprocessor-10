## نام آزمایش
کنترل ماژول بلوتوث با اپلیکیشن terminal bt


##تجهیزات موردنیاز

    * ماژول بلوتوث
    * اپلیکیشن terminal bt
   * led
    * مقاومت 220اهم
    * بردبورد
    * برد آردوینو uno
    * سیم

## کد آزمایش

#include <SoftwareSerial.h>

SoftwareSerial BTserial(2,3);

#define ledPin 7

int state = 0;

void setup() {

pinMode(ledPin, OUTPUT);

digitalWrite(ledPin, LOW);

Serial.begin(9600);

BTserial.begin(9600);

}

void loop() {

if(BTserial.available() > 0){

state = BTserial.read(); 

}

if (state == '0') {

digitalWrite(ledPin, LOW);

Serial.println("LED: OFF");

state = 1;

}

else if (state == '1') {

digitalWrite(ledPin, HIGH);

Serial.println("LED: ON");

state = 0;

}

}
## توضیحات سخت افزاری

ماژول بلوتوث HC05 دارای 6 پایه به شرح زیر است:

VIN: تغذیه ماژول – 6-3.6 ولت

GND: زمین

STATE: تعیین وضعیت اتصال

EN: تنظیم جهت ورود به تنظیمات AT Command

RX: دریافت اطلاعات از طریق پروتکل سریال

TX: ارسال اطلاعات از طریق پروتکل سریال

## توضیحات کد

    ابتدا لازم است پایه‌هایی که ال ای دی به آن متصل شده و سپس متغیری که داده‌های دریافتی از تلفن همراه را در آن ذخیره می‌کنیم، تعریف شود. در تابع setup، پین LED را به عنوان خروجی تعریف کرده و آن را در وضعیت LOW قرار می‌دهیم.
    
    در تابع loop با کمک تابع ()Serial.available بررسی می‌کنیم که آیا داده‌ای از پورت سریال برای خواندن وجود دارد. یعنی زمانی که داده‌ای برای ماژول بلوتوث ارسال می‌کنیم این عبارت صحیح خواهد بود،
   
    سپس از تابع ()Serial.read برای خواندن این داده استفاده کرده و آن را در متغیر “state” ذخیره می‌کنیم. به این ترتیب اگر آردوینو کاراکتر ‘0’ را دریافت کند، ال ای دی را خاموش خواهد کرد و از طریق پورت سریال و با کمک تابع ()Serial.println رشته‌ی “LED: OFF” به تلفن همراه ارسال خواهد شد.


  ## شماتیک مدار:
![توضیح تصویر](https://github.com/Rahel12384/Microprocessor-10/blob/main/micro%202/100.jpg)


## خروجی آزمایش:
![توضیح تصویر](https://github.com/Rahel12384/Microprocessor-10/blob/main/micro%202/10000.jpg)


