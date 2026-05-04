#include <Arduino_FreeRTOS.h>

// deklarasi task
void TaskBlink1(void *pvParameters);
void TaskBlink2(void *pvParameters);
void TaskPrint(void *pvParameters);

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
    vTaskDelay(200 / portTICK_PERIOD_MS);

    digitalWrite(8, LOW);
    vTaskDelay(200 / portTICK_PERIOD_MS);
  }
}

// Task 2
void TaskBlink2(void *pvParameters) {
  pinMode(7, OUTPUT);

  while (1) {
    Serial.println("Task2");

    digitalWrite(7, HIGH);
    vTaskDelay(300 / portTICK_PERIOD_MS);

    digitalWrite(7, LOW);
    vTaskDelay(300 / portTICK_PERIOD_MS);
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
