# Praktikum Pemrograman Sistem Tertanam

## Pertanyaan praktikum bagian percabangan

1. Pada kondisi apa program masuk ke blok `if`?
2. Pada kondisi apa program masuk ke blok `else`?
3. Apa fungsi dari perintah `delay(timeDelay)`?
4. Jika program yang dibuat memiliki alur mati → lambat → cepat → reset (mati),
   ubah menjadi LED tidak langsung reset → tetapi berubah dari cepat → sedang →
   mati.

### Jawaban

1. Pada kondisi apa program masuk ke blok `if`?

```c
if (timeDelay <= 100) {
```

pada kondisi ketika nilai dari variabel `timeDelay` lebih kecil samadengan 100 (<= 100)

2. Pada kondisi apa program masuk ke blok else?

```c
else {
  timeDelay -= 100;
}
```

Ketika variabel `timeDelay` lebih besar dari 100 (>100), maka akan memasuki kondisi else.

3. Apa fungsi dari perintah `delay(timeDelay)`?

```c
  delay(timeDelay);
```

Fungsi `delay` akan menunda (delay) eksekusi kode selanjutnya sebanyak isi dari variabel `timeDelay`.

4. Jika program yang dibuat memiliki alur mati → lambat → cepat → reset (mati),
   ubah menjadi LED tidak langsung reset → tetapi berubah dari cepat → sedang →
   mati.

```c
// inisialisasi led pin, variabel timeDelay dan isReverse
const int ledPin = 12;
int timeDelay = 1000;
bool isReverse = false;

// Setup pinmode led pin menjadi output
void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Nyalakan LED
  digitalWrite(ledPin, HIGH);
  delay(timeDelay);
  // Matikan LED
  digitalWrite(ledPin, LOW);
  delay(timeDelay);

  /*
   * jika isReverse = false
   * maka lampu akan berkedip lebih cepat
   *
   * jika isReverse = true
   * maka lampu akan berkedip melambat
   */
  if (isReverse == false){
    timeDelay -= 100;

    // jika timeDelay lebih kecil samadengan 100 maka isReverse berubah menjadi true
    if(timeDelay <= 100){
      isReverse = true;
    }
  } else {
    timeDelay += 100;

    // jika timeDelay lebih besar samadengan 1000 maka isreverse berubah menjadi false
    if(timeDelay >= 1000){
      isReverse = false;
    }
  }

}

```
