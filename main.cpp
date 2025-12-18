#include "fusion.h" // Senin hazırladığın pencere sınıfı
#include <QApplication> // Qt uygulamasını yöneten sınıf

int main(int argc, char *argv[])
{
    // 1. Qt Uygulamasını Başlat
    QApplication a(argc, argv);

    // 2. Bizim Fusion Penceresini Oluştur
    Fusion w;

    // 3. Pencereyi Göster
    w.show();

    // 4. Olay Döngüsüne Gir (Pencere kapanana kadar bekle)
    return a.exec();
}
