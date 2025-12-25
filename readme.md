---
# Analisis Kompleksitas Algoritma: Permasalahan Tangga (Staircase Problem)
**Mata Kuliah:** Analisis Kompleksitas Algoritma (AKA)
**Semester:** 3
**Tugas:** Tugas Besar

---

Anggota Kelompok

1. **Bagas Setiaji** - 103042400084
2. **Aqsyal Raihan Jamil** - 103042400089

---

## 📖 Pendahuluan

Repositori ini berisi implementasi dan analisis dari dua algoritma berbeda untuk menyelesaikan masalah komputasi yang sama. Tujuan utama dari proyek ini adalah untuk mendemonstrasikan implikasi praktis dari **Kompleksitas Waktu** dengan membandingkan pendekatan **Iteratif** melawan pendekatan **Rekursif**.

Dengan menganalisis waktu eksekusi (*running time*) algoritma-algoritma ini terhadap berbagai ukuran input, kami bertujuan untuk memvisualisasikan kesenjangan efisiensi antara kelas kompleksitas waktu linear  dan eksponensial .

---

## 🏗️ Studi Kasus: Masalah Logistik "Robo-Climb"

### Latar Belakang

Dalam bidang logistik otomatis dan robotika, efisiensi pencarian jalur (*pathfinding*) adalah hal yang krusial. Pertimbangkan skenario navigasi sederhana yang melibatkan robot logistik bernama **"ClimbBot-X"**.

ClimbBot-X perlu memanjat rak penyimpanan vertikal (yang direpresentasikan sebagai tangga) untuk mencapai rak paling atas. Robot ini memiliki batasan pada mekanisme pergerakannya:

1. Ia dapat bergerak naik **1 langkah** sekaligus.
2. Ia dapat melompat naik **2 langkah** sekaligus.

### Permasalahan

Untuk rak penyimpanan dengan ** anak tangga**, sistem harus menghitung **berapa banyak cara berbeda** yang dapat dilakukan ClimbBot-X untuk mencapai puncak. Perhitungan ini vital bagi sistem untuk memprediksi pola pergerakan potensial dan mengoptimalkan penggunaan baterai untuk penjelajahan di masa depan.

Secara matematis, masalah ini memetakan langsung ke **Deret Fibonacci**, di mana jumlah cara untuk mencapai langkah ke- adalah jumlah cara untuk mencapai langkah ke- dan .

### Contoh

* **Input:**  (3 Langkah)
* **Perhitungan:**
1. 1 langkah + 1 langkah + 1 langkah
2. 1 langkah + 2 langkah
3. 2 langkah + 1 langkah


* **Output:** 3 cara berbeda.

---

## ⚙️ Algoritma yang Diimplementasikan

Untuk menyelesaikan masalah Robo-Climb, kami telah mengimplementasikan dua versi solusi dalam bahasa **C++**:

### 1. Pendekatan Rekursif

* **Konsep:** Fungsi memanggil dirinya sendiri untuk menghitung jalur bagi  dan  hingga mencapai *base case*.
* **Kelebihan:** Kode bersih, elegan, dan secara langsung mencerminkan definisi matematisnya.
* **Kekurangan:** Sangat tidak efisien untuk  yang besar karena perhitungan berulang pada sub-masalah yang sama.
* **Kompleksitas yang Diharapkan:** Eksponensial .

### 2. Pendekatan Iteratif

* **Konsep:** Menggunakan *loop* (perulangan) untuk menghitung urutan dari bawah ke atas (*bottom-up*), hanya menyimpan dua nilai sebelumnya untuk menghitung nilai berikutnya.
* **Kelebihan:** Sangat efisien dengan *overhead* memori yang dapat diabaikan.
* **Kekurangan:** Kode sedikit lebih panjang (*verbose*) dibandingkan versi rekursif.
* **Kompleksitas yang Diharapkan:** Linear .

---

## 📊 Metodologi Pengujian (Benchmarking)

Untuk menganalisis efisiensi, aplikasi melakukan langkah-langkah berikut:

1. **Variasi Input:** Menguji algoritma terhadap berbagai ukuran input ().
2. **Pencatatan Waktu Presisi Tinggi:** Menggunakan pustaka (library) C++ `<chrono>` untuk mengukur waktu eksekusi dalam **mikrodetik/nanodetik**.
3. **Pengumpulan Data:** Mencatat waktu eksekusi kedua algoritma untuk menghasilkan grafik perbandingan ("Ukuran Input vs. Running Time").

**Catatan mengenai Batasan:**
Karena sifat eksponensial dari algoritma rekursif, input untuk pengujian rekursif akan dibatasi pada ambang batas yang lebih rendah (misalnya, ) untuk mencegah sistem macet (*freeze*), sedangkan versi iteratif akan diuji dengan input yang jauh lebih besar (misalnya, ).

---

## 🚀 Cara Menjalankan

1. *Clone* repositori ini.
2. Buka proyek di IDE C++ Anda (VS Code, CLion, atau Visual Studio).
3. Kompilasi `main.cpp`.
4. Jalankan *executable*-nya.
5. Lihat *output* konsol untuk data waktu.

```bash
g++ main.cpp -o staircase_solver
./staircase_solver

```
