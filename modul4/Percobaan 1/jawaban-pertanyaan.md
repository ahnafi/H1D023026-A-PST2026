# 💡 Pertanyaan praktikum
- Apa fungsi perintah analogRead() pada rangkaian praktikum ini?

Jawaban :
> Fungsi analogRead() berperan sebagai pengonversi sinyal analog dari potensiometer menjadi data digital melalui fitur ADC (Analog-to-Digital Converter) pada mikrokontroler, di mana tegangan input antara 0V hingga 5V akan diubah menjadi nilai numerik dalam rentang 0 sampai 1023. Dalam praktikum ini, perintah tersebut digunakan untuk mendeteksi perubahan posisi tuas potensiometer yang menghasilkan variasi tegangan, sehingga program mendapatkan data angka yang presisi untuk kemudian dipetakan menjadi instruksi sudut gerak pada motor servo.

- Mengapa diperlukan fungsi map() dalam program tersebut?
Jawaban : 
> Fungsi map() diperlukan untuk mensinkronisasikan dua rentang nilai yang berbeda, yaitu mengubah input digital hasil pembacaan potensiometer (0 hingga 1023) menjadi rentang sudut yang dapat diterima oleh motor servo (0 hingga 180 derajat). Tanpa fungsi ini, nilai mentah dari potensiometer akan melebihi batas maksimal pergerakan servo, sehingga pemetaan ini memastikan bahwa setiap perubahan posisi pada potensiometer berkorelasi secara akurat dan proporsional terhadap posisi sudut motor servo.

- Modifikasi program berikut agar servo hanya bergerak dalam rentang 30° hingga 150°, meskipun potensiometer tetap memiliki rentang ADC 0–1023. Jelaskan program pada file README.md

Jawaban :
```cpp
#include <Servo.h> 

Servo myservo; 

const int potensioPin = A0; 
const int servoPin = 9; 

int pos = 0; 
int val = 0; 

void setup() {
  myservo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(potensioPin);

  // Perubahan pada parameter output minimum dan maksimum
  pos = map(val, 0, 1023, 30, 150);

  myservo.write(pos);

  Serial.print("ADC Potensio: ");
  Serial.print(val);
  Serial.print(" | Sudut Servo: ");
  Serial.println(pos);

  delay(15);
}
```

> Program ini bekerja dengan membaca nilai analog dari potensiometer melalui pin A0 yang menghasilkan rentang angka digital 0 hingga 1023, kemudian nilai tersebut diproses menggunakan fungsi map() untuk mengubah skala input menjadi skala output baru yang dibatasi secara spesifik pada sudut 30° hingga 150°. Setelah nilai sudut ditentukan, instruksi myservo.write(pos) mengirimkan sinyal PWM ke motor servo agar bergerak menuju posisi yang sesuai, sementara data pembacaan tersebut dikirimkan ke Serial Monitor untuk keperluan pemantauan real-time sebelum program berhenti sejenak selama 15 milidetik guna menjaga stabilitas gerakan motor.
