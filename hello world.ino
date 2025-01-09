void setup() {
  // Memulai komunikasi serial dengan kecepatan 115200 bps
  Serial.begin(115200);
  
  // Menunggu beberapa saat agar Serial Monitor siap
  delay(1000);
  
  // Menampilkan pesan "Hello, World!" ke Serial Monitor
  Serial.println("Hello, World!");
}

void loop() {
  // Menampilkan pesan berulang setiap 2 detik
  Serial.println("Hello, World!");
  delay(2000);  // Jeda 2 detik
}
