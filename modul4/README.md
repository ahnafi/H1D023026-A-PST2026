# Modul 4 : Analog to Digital Converter (ADC) dan Pulse Width Modulation (PWM) 

## 🎯 Tujuan Praktikum
- Mampu mengonfigurasi dan menggunakan modul ADC
- Mampu mengonfigurasi dan menggunakan modul DAC (atau teknik PWM) pada mikrokontroler

## 📄 Dasar Teori

Dalam pengembangan sistem embedded menggunakan Arduino, dua konsep penting yang sering digunakan adalah Analog to Digital Converter (ADC) dan Pulse Width Modulation (PWM). Keduanya memungkinkan Arduino untuk berinteraksi dengan dunia analog, baik dalam membaca sensor maupun mengontrol perangkat output.

<img width="1024" height="562" alt="image" src="https://github.com/user-attachments/assets/f2dee8fd-12ab-411f-b952-be1b45baa8f0" />

ADC dan PWM sering digunakan bersamaan dalam berbagai aplikasi, misalnya membaca nilai dari potensiometer (ADC) dan menggunakan nilai tersebut untuk mengatur kecerahan LED (PWM). Dengan kombinasi ini, Arduino dapat menerima input analog, memproses data dan menghasilkan output yang responsif.

### Kontrol LED dengan PWM

Pada sistem digital, keluaran mikrokontroler pada umumnya hanya memiliki dua kondisi logika, yaitu HIGH (1) dan LOW (0). Kondisi ini menyebabkan perangkat keluaran seperti LED secara alami hanya dapat dikendalikan dalam keadaan menyala atau mati. Namun, dalam banyak aplikasi sistem tertanam seperti pengaturan kecerahan lampu, pengendalian kecepatan motor DC, dan manajemen daya dibutuhkan kemampuan untuk mengatur tingkat keluaran secara bertahap, bukan sekadar dua kondisi ekstrem tersebut.

Salah satu teknik yang umum digunakan untuk mengatasi keterbatasan tersebut adalah Pulse Width Modulation (PWM). PWM merupakan metode pengaturan sinyal digital dengan cara memodulasi lebar pulsa (duty cycle) dalam satu periode waktu tertentu. Dengan mengubah perbandingan antara waktu sinyal berada pada kondisi HIGH dan LOW, mikrokontroler dapat menghasilkan tegangan rata-rata efektif yang berbeda-beda, sehingga seolah-olah menghasilkan sinyal analog.

PWM digunakan untuk mengendalikan intensitas cahaya LED secara bertahap, mulai dari kondisi redup hingga terang, dan sebaliknya. Melalui praktikum ini, mahasiswa diharapkan dapat memahami konsep dasar PWM, hubungan antara nilai duty cycle dengan tingkat kecerahan LED, serta implementasi PWM pada mikrokontroler menggunakan fungsi ```analogWrite()```.

```cpp
const int LED_PIN = 9;
int i = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600); // Inisialisasi Serial
}

void loop() {

  // Naik (fade in)
  for (i = 0; i < 255; i++) {
    analogWrite(LED_PIN, i);

    Serial.print("PWM Naik: ");
    Serial.println(i);

    delay(100);
  }

  // Turun (fade out)
  for (i = 255; i > 0; i--) {
    analogWrite(LED_PIN, i);

    Serial.print("PWM Turun: ");
    Serial.println(i);

    delay(100);
  }
}
```

https://github.com/user-attachments/assets/8bf525fb-8429-4420-a6c9-8ecb123c1c27

## 🚀 Tugas Pendahuluan

- Membuat semua program (source code) yang diperlukan untuk masing-masing percobaan (sertakan keterangan-keterangan penting pada source code menggunakan komentar); Jelaskan masing-masing baris atau bagian kode tersebut.
- Menyiapkan rangkaian hardware untuk percobaan (sudah dirangkai, sehingga saat percobaan langsung menjalankan program yang telah dibuat). Sertakan pada tugas pendahuluan dalam bentuk foto yang juga menampilkan wajah Anda. (Dilakukan untuk masing-masing percobaan; Sebelum praktikum, cukup siapkan untuk percobaan pertama saja jika space pada breadboard terbatas)


## ⚙️ Alat dan Bahan

Dalam percobaan sederhana ini, berikut alat dan bahan yang digunakan:

<div align="center">
<table border="1" cellpadding="10" cellspacing="0" width="100%">
  <tr>
    <th>Arduino</th>
    <th>Potensiometer</th>
    <th>Motor Servo</th>
    <th>LED</th>
  </tr>

  <tr align="center">
    <td>
      <img width="192" height="136,1" alt="arduino_uno" src="https://github.com/user-attachments/assets/3e61e208-bb23-42aa-bbef-0ac539279ce0" /><br>
    </td>
    <td>
      <img width="179,5" height="175,75" alt="image" src="https://github.com/user-attachments/assets/f44c78e5-fd37-47e0-a2f4-0a5af2b6c86a" />
    </td>
    <td>
      <img width="318" height="260" alt="image" src="https://github.com/user-attachments/assets/e54280b7-5fd3-4ce7-b4f8-41163ed3bed3" /><br>
    </td>
    <td>
      <img width="54" height="134" alt="RedLED_Fritzing" src="https://github.com/user-attachments/assets/80556570-c129-43fa-904b-39eac5677a2d" />
    </td>
  </tr>

  <tr align="center">
    <td>Arduino Uno, Leonardo, atau lainnya</td>
    <td>Potensiometer</td>
    <td>Motor Servo</td>
    <td>LED Merah</td>
  </tr>
</table>
</div>

## 💻 Percobaan

<h3><a href="Percobaan 1">Percobaan 4A: Analog to Digital Converter (ADC)</a></h3>

ADC (Analog to Digital Converter) adalah fitur yang digunakan untuk mengubah sinyal analog menjadi data digital yang dapat diproses oleh mikrokontroler. Contohnya Potensiometer menghasilkan nilai tegangan variabel.

Pembacaan ADC dilakukan menggunakan fungsi:
```cpp
analogRead(pin);
```

Pada percobaan ADC praktikan akan mengendalikan perputaran motor servo dengan menggunakan potensiometer.

Selanjutnya dapat membuka bagian percobaan di [Percobaan 4A: Analog to Digital Converter](https://github.com/reslabunsoed/modul4_adc_pwm/tree/f475b133e0ab903880fb2ab24aede81f04d8948a/Percobaan%201)

<h3><a href="Percobaan 2">Percobaan 4B: Pulse Width Modulation (PWM)</a></h3>

PWM (Pulse Width Modulation) adalah teknik untuk menghasilkan sinyal analog semu menggunakan sinyal digital dengan cara mengatur lebar pulsa (duty cycle). PWM biasanya digunakan untuk mengatur kecerahan LED, mengontrol kecepatan motor DC dan mengatur intensitas daya pada perangkat.

Nilai PWM pada Arduino umumnya berkisar antara 0 hingga 255 yang dikontrol menggunakan fungsi:
```cpp
analogWrite(pin, value);
```

Pada percobaan PWM, praktikan akan mengendalikan intensitas cahaya dari LED dengan menggunakan potensiometer.

Selanjutnya dapat membuka bagian percobaan di [Percobaan 4B : Pulse Width Modulation (PWM)](https://github.com/reslabunsoed/modul4_adc_pwm/tree/f475b133e0ab903880fb2ab24aede81f04d8948a/Percobaan%202)

## 📚 Pertanyaan Praktikum

- Bagaimana proses konversi sinyal analog menjadi digital pada Arduino? Jelaskan!
- Faktor apa saja yang dapat mempengaruhi keakuratan pembacaan ADC?
- Apa kendala yang mungkin terjadi saat mengintegrasikan ADC dan PWM dalam satu sistem?

## 🧰 Mengakhiri Percobaan

Berikut hal yang perlu dilakukan setelah selesai praktikum:
- Sebelum keluar dari ruang praktikum, pastikan meja dalam keadaan rapi.
- Jangan lupa untuk mendokumentasikan dalam bentuk foto dan video serta diunggah lewat google drive dan sertakan tautan dokumentasi tersebut di Buku Catatan Praktikum.
- Pastikan asisten telah menandatangani catatan percobaan kali ini pada Buku Catatan Praktikum Anda. Catatan percobaan yang tidak ditandatangani oleh asisten tidak akan dinilai.
- Kumpulkan kode program tugas tambahan pada setiap percobaan dalam repository github [Laporan Praktikum](https://github.com/reslabunsoed/modul4_adc_pwm/tree/3cd3e51389ea52b7968ab0ef6452d6716c95323d/Laporan%20Praktikum) dengan format nama repository “Kelas(value)_Modul(value)_Nama_NIM”

<h2></h2>

<br>

![banner](https://github.com/user-attachments/assets/f1f03032-41c0-4121-94e3-df1d513b42e5)
