// Pola biner untuk karakter (dp,g,f,e,d,c,b,a)
const byte numeral[12] = {
  B10111110, // 0 - G
  B11111100, // 1 - 0
  B01100000, // 2 - 1
  B11011010, // 3 - 2
  B11110010, // 4 - 3
  B01100110, // 5 - 4
  B10110110, // 6 - 5
  B00111110, // 7 - 6
  B11100000, // 8 - 7
  B11111110, // 9 - 8
  B11100110, // 10 - 9
  B00000000  // 11 - Kosong (semua segmen mati)
};

// Urutan tampilan “G . 231 . 22 . 0038”
const int urutan[] = {
  0,   // G
  11,  // titik (DP)
  3,   // 2
  4,   // 3
  2,   // 1
  11,  // titik (DP)
  3,   // 2
  3,   // 2
  11,  // titik (DP)
  1,   // 0
  1,   // 0
  4,   // 3
  9    // 8
};

const int segmentPins[8] = {2, 10, 9, 8, 7, 6, 5, 4}; // dp,g,f,e,d,c,b,a

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 13; i++) { // total 13 langkah
    bool titikAktif = (i == 1 || i == 5 || i == 8); // posisi titik aktif

    // 1️⃣ Tampilkan karakter
    tampilKarakter(urutan[i], titikAktif);
    delay(100);

    // 2️⃣ Kedip (matikan semua segmen sebentar)
    tampilKarakter(11, false); // 11 = semua mati
    delay(150);

    // 4️⃣ Matikan sebelum karakter berikutnya
    tampilKarakter(11, false);
    delay(200);
  }

  delay(2000); // jeda sebelum mengulang siklus
}

// Fungsi menampilkan karakter pada 7-segmen
void tampilKarakter(int index, bool titik) {
  for (int seg = 0; seg < 8; seg++) {
    bool nyala = bitRead(numeral[index], seg);
    if (seg == 0) nyala = titik; // segmen dp (decimal point)
    digitalWrite(segmentPins[seg], nyala);
  }
}
