#ifndef FUSION_H
#define FUSION_H

#include <QDialog>


#include <QWidget>
#include <QTimer> // Zamanlayıcı
#include <opencv2/opencv.hpp> // OpenCV Kütüphanesi

namespace Ui {
class Fusion;
}

class Fusion : public QDialog
{
    Q_OBJECT

public:
    explicit Fusion(QWidget *parent = nullptr);
    ~Fusion();

private slots:
    void updateCameras(); // Her saniye çalışacak fonksiyonumuz

private:
    Ui::Fusion *ui;
    QTimer *timer; // Kamerayı sürekli yenileyecek saat

    // Görüntüleri tutacak değişkenler (OpenCV Matrisleri)
    cv::Mat frameRGB;
    cv::Mat frameThermal;
    cv::Mat frameFusion;
};

#endif // FUSION_H
