# Pertanyaan Komunikasi Task

1. Jelaskan perbedaan antara loop() pada Arduino biasa dengan sistem yang menggunakan RTOS!

Jawaban :

> Pada Arduino biasa tanpa RTOS, fungsi `loop()` menjadi pusat eksekusi dan berjalan terus menerus secara sekuensial, sehingga semua logika program harus diatur manual termasuk delay dan pembagian waktu antar proses. Pada sistem dengan FreeRTOS, `loop()` tidak digunakan karena eksekusi diatur oleh scheduler yang menjalankan banyak task secara terpisah dan terstruktur. Setiap task memiliki fungsi sendiri dan dapat berjalan bergantian berdasarkan prioritas dan timing, sehingga sistem lebih modular dan responsif dibanding pendekatan satu loop tunggal.

2. Mengapa fungsi loop() dibiarkan kosong?

Jawaban : 

>  Fungsi loop() dibiarkan kosong karena setelah vTaskStartScheduler() dipanggil, seluruh eksekusi program diambil alih oleh scheduler dari FreeRTOS. Semua logika sudah dipindahkan ke dalam task, sehingga tidak ada lagi kode yang perlu dijalankan secara berulang di loop(). Jika loop() tetap diisi, kode tersebut tidak akan pernah dieksekusi karena sistem terus menjalankan task yang sudah dijadwalkan.

3. Apa insight utama yang Anda pelajari dari praktikum ini?

Jawaban : 

> Insight utama: RTOS memecah program menjadi task terpisah sehingga eksekusi lebih terstruktur dan tidak bergantung pada satu loop(). Mekanisme vTaskDelay membuat task bergantian berjalan tanpa saling blocking, sehingga sistem tetap responsif. Penggunaan queue menunjukkan cara komunikasi antar task yang aman, karena data dikirim terkontrol tanpa konflik akses.
