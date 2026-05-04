#include <Arduino_FreeRTOS.h>
#include <queue.h>

// struktur data
struct readings {
  int temp;
  int h;
};

// handle queue
QueueHandle_t my_queue;

// deklarasi task
void read_data(void *pvParameters);
void display(void *pvParameters);

void setup() {
  Serial.begin(9600);

  // buat queue (1 item)
  my_queue = xQueueCreate(1, sizeof(struct readings));

  // buat task
  xTaskCreate(read_data, "ReadSensors", 128, NULL, 1, NULL);
  xTaskCreate(display, "Display", 128, NULL, 1, NULL);
}

void loop() {
  // kosong karena RTOS
}

// task baca data
void read_data(void *pvParameters) {
  struct readings x;

  for (;;) {
    x.temp = 54;
    x.h = 30;

    xQueueSend(my_queue, &x, portMAX_DELAY);

    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

// task tampilkan data
void display(void *pvParameters) {
  struct readings x;

  for (;;) {
    if (xQueueReceive(my_queue, &x, portMAX_DELAY) == pdPASS) {
      Serial.print("temp = ");
      Serial.println(x.temp);

      Serial.print("humidity = ");
      Serial.println(x.h);
    }
  }
}
