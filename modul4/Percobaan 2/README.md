# Percobaan 2: Pulse Width Modulation (PWM)

## 🎯 Tujuan

- Memahami konsep dasar PWM (Pulse Width Modulation) sebagai metode untuk menghasilkan sinyal analog semu dari keluaran digital Arduino.
- Mengetahui cara kerja fungsi ```analogWrite()``` pada Arduino Uno dalam menghasilkan variasi duty cycle.

## 💡 Spesifikasi yang Diharapkan

- Nilai ADC berhasil dikonversi menjadi kecerahan LED
- Nilai ADC pada Serial Monitor berubah sesuai putaran potensiometer
- LED merespons perubahan nilai PWM. LED redup saat nilai potensiometer kecil dan semakin terang saat nilai potensiometer besar
- Menampilkan nilai ADC dan nilai PWM secara real-time di Serial Monitor

## ♻️ Langkah Percobaan

1. Persiapkan alat dan bahan
- Lakukan seperti halnya tugas pendahuluan poin 1
- Pastikan Arduino Uno terhubung dengan komputer
  
2. Program percobaan
```cpp
#include <Arduino.h> // library dasar Arduino (tidak wajib diubah)

// ===================== PIN SETUP =====================
// Tentukan pin yang digunakan untuk potensiometer dan LED PWM
const int potPin = ;   // isi dengan pin analog (contoh A0)
const int ledPin = ;   // isi dengan pin digital PWM (contoh 9)

// ===================== VARIABEL =====================
// Variabel untuk menyimpan hasil pembacaan dan konversi PWM
int nilaiADC = ;  // isi dengan nilai awal (default 0)
int pwm = ;       // isi dengan nilai awal (default 0)

void setup() {

  // ===================== OUTPUT SETUP =====================
  // Atur pin LED sebagai output
  pinMode(ledPin, );

  // ===================== SERIAL MONITOR =====================
  // Aktifkan komunikasi serial untuk melihat data pembacaan
  Serial.begin(); // isi baud rate (contoh 9600)
}

void loop() {

  // ===================== PEMBACAAN SENSOR =====================
  // Baca nilai analog dari potensiometer (rentang 0–1023)
  nilaiADC = analogRead(); // isi dengan potPin

  // ===================== PEMROSESAN DATA (SCALING) =====================
  // Ubah nilai ADC (0–1023) menjadi nilai PWM (0–255)
  pwm = map(nilaiADC,
            ,   // isi nilai minimum ADC
            ,   // isi nilai maksimum ADC
            ,   // isi PWM minimum
            );  // isi PWM maksimum

  // ===================== OUTPUT PWM =====================
  // Kirim sinyal PWM ke LED (mengatur kecerahan)
  analogWrite(ledPin, ); // isi dengan variabel PWM

  // ===================== MONITORING DATA =====================
  // Tampilkan data ADC dan PWM ke Serial Monitor
  Serial.print("ADC: ");
  Serial.print(); // isi variabel ADC

  Serial.print(" | PWM: ");
  Serial.println(); // isi variabel PWM

  // ===================== STABILISASI SISTEM =====================
  // Delay untuk menstabilkan pembacaan dan tampilan data
  delay(); // isi dalam milidetik (contoh 50)
}
```
  
3. Simpan scetch dengan nama file modul4_percobaan2
4. konfigurasi rangkaian

Membuat rangkaian yang menghubungkan Arduino, Potensiometer dengan pin analog dan LED dengan pin PWM menggunakan breadboard sesuai dengan gambar berikut:
<img width="1536" height="632" alt="led_potensio" src="https://github.com/user-attachments/assets/f5bf163c-910a-4eef-841f-0396b768c9a0" />

5. Pertanyaan praktikum
- Jelaskan mengapa LED dapat diatur kecerahannya menggunakan fungsi analogWrite()!
- Apa hubungan antara nilai ADC (0–1023) dan nilai PWM (0–255)?
- Modifikasilah program berikut agar LED hanya menyala pada rentang kecerahan sedang, yaitu hanya ketika nilai PWM berada pada rentang 50 sampai 200. Jelaskan program pada file README.md.

<h2></h2>

<br>

![banner](https://github.com/user-attachments/assets/f1f03032-41c0-4121-94e3-df1d513b42e5)
