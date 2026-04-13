# Pertanyaan Praktikum Serial monitor

## Pertanyaan
1) Jelaskan proses dari input keyboard hingga LED menyala/mati!
2) Mengapa digunakan Serial.available() sebelum membaca data? Apa yang terjadi jika baris tersebut dihilangkan?
3) Modifikasi program agar LED berkedip (blink) ketika menerima input '2' dengan kondisi jika ‘2’ aktif maka LED akan terus berkedip sampai perintah selanjutnya diberikan dan berikan penjelasan disetiap baris kode nya dalam bentuk README.md!
4) Tentukan apakah menggunakan delay() atau milis()! Jelaskan pengaruhnya terhadap sistem

## Jawaban
1) Jelaskan proses dari input keyboard hingga LED menyala/mati!

- Program dimulai dengan inisialisasi komunikasi serial menggunakan Serial.begin(9600).
- LED dihubungkan ke pin digital dan diatur sebagai output.
- Arduino menunggu input dari Serial Monitor menggunakan Serial.available().
- Data yang masuk dibaca menggunakan Serial.read().
- Jika input adalah ‘1’, LED dinyalakan.
- Jika input adalah ‘0’, LED dimatikan.
- Jika input tidak sesuai, program menampilkan pesan error di Serial Monitor.
- Proses berjalan terus dalam loop.


2) Mengapa digunakan Serial.available() sebelum membaca data? Apa yang terjadi jika baris tersebut dihilangkan?

Serial.available() digunakan untuk memastikan bahwa buffer penerima pada perangkat (seperti Arduino) telah menerima data sebelum perintah pembacaan dieksekusi, karena proses pengiriman data secara serial membutuhkan waktu dan tidak terjadi secara instan. Jika baris ini dihilangkan, program akan langsung menjalankan fungsi Serial.read() tanpa menunggu, yang mengakibatkan variabel pembacaan sering kali berisi nilai -1 (atau karakter kosong) karena sensor atau komputer belum selesai mengirimkan bit data ke buffer. Dengan memeriksa ketersediaan data terlebih dahulu, Anda menjamin bahwa kode hanya akan memproses informasi yang valid dan mencegah terjadinya error logika atau output sampah pada Serial Monitor.

3) Modifikasi program agar LED berkedip (blink) ketika menerima input '2' dengan kondisi jika ‘2’ aktif maka LED akan terus berkedip sampai perintah selanjutnya diberikan dan berikan penjelasan disetiap baris kode nya dalam bentuk README.md!

```cpp
const int PIN_LED = 12;
char mode = '0'; // Variabel global untuk menyimpan status/mode terakhir

void setup() {
  Serial.begin(9600);
  Serial.println("Ketik '1': ON, '0': OFF, '2': Blink"); 
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  // Cek apakah ada data masuk dari Serial Monitor
  if (Serial.available() > 0) {
    char input = Serial.read(); // Membaca 1 karakter input

    // Filter agar karakter 'Enter' (\n atau \r) tidak dianggap sebagai input salah
    if (input != '\n' && input != '\r') {
      
      // Update status 'mode' hanya jika input valid (0, 1, atau 2)
      if (input == '1' || input == '0' || input == '2') {
        mode = input; 
        
        // Memberikan feedback ke Serial Monitor berdasarkan mode yang dipilih
        if (mode == '1') {
          digitalWrite(PIN_LED, HIGH);
          Serial.println("Mode: LED Tetap Menyala (ON)");
        } else if (mode == '0') {
          digitalWrite(PIN_LED, LOW);
          Serial.println("Mode: LED Mati (OFF)");
        } else if (mode == '2') {
          Serial.println("Mode: LED Berkedip (BLINKING)");
        }
      } else {
        // Jika user mengetik selain 0, 1, atau 2
        Serial.println("Perintah tidak dikenal");
      }
    }
  }

  // Logika Perulangan untuk Mode Blink
  // Bagian ini berada di luar blok 'Serial.available' agar LED terus berkedip 
  // meskipun tidak ada data baru yang dikirim.
  if (mode == '2') {
    digitalWrite(PIN_LED, HIGH);
    delay(300); // Durasi LED menyala
    digitalWrite(PIN_LED, LOW);
    delay(300); // Durasi LED mati
  }
}
```

4) Tentukan apakah menggunakan delay() atau milis()! Jelaskan pengaruhnya terhadap sistem

Gunakan millis() jika mau program tidak memblokir eksekusi program, sehingga Arduino tetap bisa membaca input Serial secara real-time. Jika memakai delay(), sistem akan berhenti sementara selama durasi delay, sehingga input dari user bisa terlambat atau terlewat. Dengan millis(), LED tetap bisa berkedip sambil sistem responsif terhadap perubahan mode tanpa jeda.

