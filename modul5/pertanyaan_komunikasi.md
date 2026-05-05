# Pertanyaan Komunikasi Task

1. Apakah kedua task berjalan secara bersamaan atau bergantian? Jelaskan mekanismenya!

Jawaban :

> Task berjalan bergantian, bukan benar benar bersamaan, karena hanya ada satu CPU. Scheduler pada FreeRTOS membagi waktu eksekusi ke tiap task dengan teknik time slicing dan prioritas. Saat satu task delay atau menunggu queue, task lain langsung dijalankan sehingga terlihat seperti paralel.

2. Apakah program ini berpotensi mengalami race condition? Jelaskan!

Jawaban :

> Program ini tidak berpotensi race condition karena komunikasi antar task menggunakan queue dari FreeRTOS. Queue bekerja sebagai mekanisme sinkronisasi yang menjamin hanya satu task mengakses data pada satu waktu saat proses kirim atau terima. Selama tidak ada variabel global yang diakses langsung tanpa proteksi, eksekusi tetap aman dan konsisten.

3. Modifikasilah program dengan menggunakan sensor DHT sesungguhnya sehingga informasi yang ditampilkan dinamis. Bagaimana hasilnya?

Jawaban :

> modifikasi menggunakan sensor DHT11 pada pin digital 2. Data suhu dan kelembapan dibaca nyata lalu dikirim lewat queue.

```cpp
#include <Arduino_FreeRTOS.h>
#include <queue.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// struktur data
struct readings {
  float temp;
  float h;
};

QueueHandle_t my_queue;

// deklarasi task
void read_data(void *pvParameters);
void display(void *pvParameters);

void setup() {
  Serial.begin(9600);
  dht.begin();

  my_queue = xQueueCreate(1, sizeof(struct readings));

  xTaskCreate(read_data, "ReadDHT", 128, NULL, 1, NULL);
  xTaskCreate(display, "Display", 128, NULL, 1, NULL);

  vTaskStartScheduler();
}

void loop() {}

// task baca sensor DHT
void read_data(void *pvParameters) {
  struct readings x;

  for (;;) {
    x.temp = dht.readTemperature();
    x.h = dht.readHumidity();

    // kirim ke queue jika valid
    if (!isnan(x.temp) && !isnan(x.h)) {
      xQueueSend(my_queue, &x, portMAX_DELAY);
    }

    vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
}

// task tampilkan data
void display(void *pvParameters) {
  struct readings x;

  for (;;) {
    if (xQueueReceive(my_queue, &x, portMAX_DELAY) == pdPASS) {
      Serial.print("Temp = ");
      Serial.print(x.temp);
      Serial.println(" C");

      Serial.print("Humidity = ");
      Serial.print(x.h);
      Serial.println(" %");
    }
  }
}
```
