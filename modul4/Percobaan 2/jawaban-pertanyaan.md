# Pertanyaan praktikum
- Jelaskan mengapa LED dapat diatur kecerahannya menggunakan fungsi analogWrite()!

Jawaban : 
> Fungsi analogWrite() dapat mengatur kecerahan LED karena memanfaatkan teknik PWM (Pulse Width Modulation), di mana mikrokontroler memanipulasi kecepatan siklus hidup dan mati arus listrik dalam frekuensi yang sangat tinggi sehingga mata manusia mempersepsikannya sebagai perubahan intensitas cahaya. Melalui nilai parameter 0 hingga 255, program menentukan rasio waktu aktif atau duty cycle dari sinyal tersebut; semakin besar nilainya, semakin lama durasi tegangan tinggi (5V) diberikan dibandingkan durasi tegangan rendah (0V), yang berakibat pada meningkatnya daya rata-rata yang diterima LED dan membuatnya tampak lebih terang.

- Apa hubungan antara nilai ADC (0–1023) dan nilai PWM (0–255)?

Jawaban : 
> Hubungan antara nilai ADC (0–1023) dan nilai PWM (0–255) adalah hubungan linier proporsional yang merepresentasikan resolusi pemrosesan data yang berbeda pada mikrokontroler, di mana ADC memiliki resolusi 10-bit sedangkan PWM bekerja pada resolusi 8-bit. Karena rentang nilai ADC empat kali lebih besar daripada rentang PWM, maka diperlukan proses penskalaan atau pembagian dengan angka empat agar setiap perubahan nilai input analog dapat diterjemahkan secara akurat menjadi lebar pulsa output yang setara. Secara teknis, nilai ADC 1023 mewakili tegangan input maksimal (100% tegangan) yang kemudian dipetakan menjadi nilai PWM 255 yang juga mewakili duty cycle maksimal (100% daya), sehingga perubahan posisi potensiometer dapat mengendalikan kecerahan LED atau kecepatan motor secara halus dan berkesinambungan.

- Modifikasilah program berikut agar LED hanya menyala pada rentang kecerahan sedang, yaitu hanya ketika nilai PWM berada pada rentang 50 sampai 200. Jelaskan program pada file README.md.

Jawaban : 
```cpp
#include <Arduino.h> // library dasar Arduino (tidak wajib diubah)

// ===================== PIN SETUP =====================
// Tentukan pin yang digunakan untuk potensiometer dan LED PWM
const int potPin = A0;   // isi dengan pin analog
const int ledPin = 9;    // isi dengan pin digital PWM

// ===================== VARIABEL =====================
// Variabel untuk menyimpan hasil pembacaan dan konversi PWM
int nilaiADC = 0;  // isi dengan nilai awal
int pwm = 0;       // isi dengan nilai awal

void setup() {

  // ===================== OUTPUT SETUP =====================
  // Atur pin LED sebagai output
  pinMode(ledPin, OUTPUT);

  // ===================== SERIAL MONITOR =====================
  // Aktifkan komunikasi serial untuk melihat data pembacaan
  Serial.begin(9600); // isi baud rate 9600
}

void loop() {

  // ===================== PEMBACAAN SENSOR =====================
  // Baca nilai analog dari potensiometer (rentang 0–1023)
  nilaiADC = analogRead(potPin); 

  // ===================== PEMROSESAN DATA (SCALING) =====================
  // Ubah nilai ADC (0–1023) menjadi nilai PWM (0–255)
  pwm = map(nilaiADC,
            0,      // nilai minimum ADC
            1023,   // nilai maksimum ADC
            0,      // PWM minimum
            255);   // PWM maksimum

  // ===================== OUTPUT PWM DENGAN BATASAN =====================
  // Kirim sinyal PWM ke LED hanya jika berada di rentang 50-200
  if (pwm >= 50 && pwm <= 200) {
    analogWrite(ledPin, pwm); // LED menyala pada kecerahan sedang
  } else {
    analogWrite(ledPin, 0);   // LED mati di luar rentang tersebut
  }

  // ===================== MONITORING DATA =====================
  // Tampilkan data ADC dan PWM ke Serial Monitor
  Serial.print("ADC: ");
  Serial.print(nilaiADC); 

  Serial.print(" | PWM: ");
  Serial.println(pwm); 

  // ===================== STABILISASI SISTEM =====================
  // Delay untuk menstabilkan pembacaan dan tampilan data
  delay(50); 
}
```

> Program ini bekerja dengan membaca nilai potensiometer dan mengonversinya menjadi nilai PWM standar, namun sebelum mengirimkan sinyal ke LED, terdapat logika pengkondisian menggunakan operator logika && (AND) untuk memastikan perintah analogWrite() hanya dieksekusi ketika nilai PWM berada di dalam ambang batas 50 hingga 200. Jika hasil pemetaan berada di bawah 50 atau di atas 200, program secara otomatis menjalankan instruksi analogWrite(ledPin, 0) yang mematikan LED, sehingga tercipta efek di mana lampu hanya akan aktif pada rentang putaran potensiometer tertentu yang merepresentasikan tingkat kecerahan sedang.