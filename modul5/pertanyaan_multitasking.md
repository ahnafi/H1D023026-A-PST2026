# Pertanyaan percobaan Multitasking
1. Apakah ketiga task berjalan secara bersamaan atau bergantian? Jelaskan mekanismenya!

Jawaban :

> Ketiga task tidak berjalan benar benar bersamaan, tetapi bergantian melalui mekanisme penjadwalan pada FreeRTOS. Scheduler menjalankan task dengan teknik time slicing dan prioritas yang sama, sehingga setiap task mendapat giliran eksekusi dalam potongan waktu yang sangat cepat. Saat sebuah task memanggil vTaskDelay, task tersebut masuk state blocked sehingga CPU langsung dialihkan ke task lain, membuat eksekusi terlihat seperti paralel padahal sebenarnya bergantian. 

2. Bagaimana cara menambahkan task keempat? Jelaskan langkahnya!

Jawaban : 

> Tambahkan fungsi baru, misalnya `void Task4(void *pvParameters)`, lalu isi dengan logika yang ingin dijalankan dalam loop `while(1)`. Setelah itu, daftarkan task tersebut di dalam `setup()` menggunakan `xTaskCreate` dengan parameter nama fungsi, nama task, ukuran stack, parameter, prioritas, dan handle jika diperlukan. Pastikan tidak terjadi konflik resource seperti penggunaan Serial atau pin yang sama agar semua task tetap berjalan stabil.

3. Modifikasilah program dengan menambah sensor (misalnya potensiometer), lalu gunakan nilainya untuk mengontrol kecepatan LED! Bagaimana hasilnya? 

Jawaban : 

```cpp

#include <Arduino_FreeRTOS.h>

// deklarasi task
void TaskBlink1(void *pvParameters);
void TaskBlink2(void *pvParameters);
void TaskPrint(void *pvParameters);

volatile int delayed = 200;

void setup() {
  // inisialisasi serial
  Serial.begin(9600);

  // buat task
  xTaskCreate(
    TaskBlink1,
    "Task1",
    128,
    NULL,
    1,
    NULL
  );

  xTaskCreate(
    TaskBlink2,
    "Task2",
    128,
    NULL,
    1,
    NULL
  );

  xTaskCreate(
    TaskPrint,
    "Task3",
    128,
    NULL,
    1,
    NULL
  );

  xTaskCreate(
    TaskSensor,
    "Task 4",
    128,
    NULL,
    1,
    NULL
  );

  // jalankan scheduler
  vTaskStartScheduler();
}

void loop() {
  // kosong karena pakai RTOS
}

// Task 1
void TaskBlink1(void *pvParameters) {
  pinMode(8, OUTPUT);

  while (1) {
    Serial.println("Task1");

    digitalWrite(8, HIGH);
    vTaskDelay(delayed / portTICK_PERIOD_MS);

    digitalWrite(8, LOW);
    vTaskDelay(delayed / portTICK_PERIOD_MS);
  }
}

// Task 2
void TaskBlink2(void *pvParameters) {
  pinMode(7, OUTPUT);

  while (1) {
    Serial.println("Task2");

    digitalWrite(7, HIGH);
    vTaskDelay(delayed / portTICK_PERIOD_MS);

    digitalWrite(7, LOW);
    vTaskDelay(delayed / portTICK_PERIOD_MS);
  }
}

// Task 3
void TaskPrint(void *pvParameters) {
  int counter = 0;

  while (1) {
    counter++;
    Serial.println(counter);

    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void TaskSensor(void *pvParameters){
    pinMode(A0,INPUT);

    while(1){
        int sensorValue = analogRead(A0);

        delayed = map(sensorValue, 0, 1023, 100, 1000);

        Serial.print("Delay: ");
        Seria;.println(delayed);

        vTaskDelay(200/portTICK_PERIOD_MS);
    }
}
```

> Hasilnya langsung terasa saat diputar. Jika potensiometer kecil, delay jadi pendek dan LED berkedip cepat. Jika diputar ke nilai besar, delay meningkat sehingga LED berkedip lebih lambat, dan kedua LED mengikuti kecepatan yang sama karena memakai variabel global yang sama.
