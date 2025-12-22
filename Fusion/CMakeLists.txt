cmake_minimum_required(VERSION 3.5)

# Proje adı: "camera-app" (Aşağıdaki satırlarda hep bu isim kullanılmalı)
project(camera-app LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- 1. QT OTOMATİK AYARLARI ---
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# --- 2. KÜTÜPHANELERİ BUL ---
# Qt 5 bileşenlerini buluyoruz
find_package(Qt5 REQUIRED COMPONENTS Widgets PrintSupport)

# OpenCV buluyoruz
find_package(OpenCV REQUIRED)

# OpenCV başlık dosyalarını (Header) ekliyoruz
include_directories(${OpenCV_INCLUDE_DIRS})

# --- 3. DOSYALARI EKLE ---
# DİKKAT: Buradaki "camera-app" ismi yukarıdaki project ismiyle uyumlu
add_executable(camera-app
    main.cpp
    fusion.cpp
    fusion.h
    fusion.ui
    qcustomplot.cpp
    qcustomplot.h
)

# --- 4. BAĞLAMA (LINKING) ---
# DİKKAT: Buradaki "camera-app" ismi de aynı olmalı
target_link_libraries(camera-app PRIVATE
    Qt5::Widgets        # Doğru yazım
    Qt5::PrintSupport   # Doğru yazım
    ${OpenCV_LIBS}      # Doğru (Eski/Yeni tüm OpenCV'leri kapsar)
)
