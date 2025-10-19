// Pola biner (dp,g,f,e,d,c,b,a) berdasarkan Siekoo Alphabet
const byte huruf[18] = {
  B11101110, // 0 - A
  B01110110, // 1 - G
  B11101100, // 2 - U
  B01101110, // 3 - N
  B01111100, // 4 - D
  B11110110, // 5 - W
  B11111100, // 6 - I
  B01101110, // 7 - S
  B01111000, // 8 - L
  B01111110, // 9 - O
  B00000000  // 10 - Kosong (semua mati)
};

// Urutan tampilan “AGUNG DWI SUSILO”
const int urutan[] = {
  0,  // A
  1,  // G
  2,  // U
  3,  // N
  1,  // G
  10, // spasi
  4,  // D
  5,  // W
  6,  // I
  10, // spasi
  7,  // S
  2,  // U
  7,  // S
  6,  // I
  8,  // L
  9   // O
};

// Pin segmen 7-segment: dp,g,f,e,d,c,b,a
const int segmentPins[8] = {2, 10, 9, 8, 7, 6, 5, 4};

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 16; i++) { // 16 karakter termasuk spasi
    tampilKarakter(urutan[i], false);
    delay(600);

    // Kedip sekali sebelum pindah
    tampilKarakter(10, false);
    delay(200);
    tampilKarakter(urutan[i], false);
    delay(300);

    // Matikan semua segmen
    tampilKarakter(10, false);
    delay(250);
  }

  delay(3000); // jeda sebelum ulangi seluruh nama
}

void tampilKarakter(int index, bool titik) {
  for (int seg = 0; seg < 8; seg++) {
    bool nyala = bitRead(huruf[index], seg);
    if (seg == 0) nyala = titik; // segmen dp
    digitalWrite(segmentPins[seg], nyala);
  }
}
