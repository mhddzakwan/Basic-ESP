#include <WiFi.h>
#include <WebServer.h>

// Ganti dengan nama dan password WiFi Anda
const char* ssid = "Nama_WiFi";
const char* password = "Password_WiFi";

// LED flash bawaan ESP32-CAM
#define LED_PIN 4

// Membuat web server pada port 80
WebServer server(80);

void setup() {
  // Inisialisasi pin LED
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);  // Matikan LED di awal

  // Memulai koneksi WiFi
  Serial.begin(115200);
  Serial.println();
  Serial.printf("Menghubungkan ke %s", ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.println("WiFi Terhubung!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Rute untuk halaman web
  server.on("/", handleRoot);
  server.on("/led/on", handleLedOn);
  server.on("/led/off", handleLedOff);

  // Mulai server
  server.begin();
  Serial.println("Web server dimulai...");
}

void loop() {
  // Menangani permintaan klien
  server.handleClient();
}

// Fungsi untuk menangani halaman utama
void handleRoot() {
  String html = "<h1>ESP32-CAM LED Control</h1>";
  html = "(Nama)";
  html = "(Kelas)";
  html += "<p><a href='/led/on'><button>Turn ON LED</button></a></p>";
  html += "<p><a href='/led/off'><button>Turn OFF LED</button></a></p>";
  server.send(200, "text/html", html);
}

// Fungsi untuk menyalakan LED
void handleLedOn() {
  digitalWrite(LED_PIN, HIGH);
  server.send(200, "text/html", "<h1>LED is ON</h1><p><a href='/'>Back</a></p>");
}

// Fungsi untuk mematikan LED
void handleLedOff() {
  digitalWrite(LED_PIN, LOW);
  server.send(200, "text/html", "<h1>LED is OFF</h1><p><a href='/'>Back</a></p>");
}
