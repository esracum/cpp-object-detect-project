#include "fusion.h"
#include "ui_fusion.h"

Fusion::Fusion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fusion)
{
    ui->setupUi(this);

    // 1. Timer'ı Kur
    timer = new QTimer(this);


    connect(timer, &QTimer::timeout, this, &Fusion::updateCameras);

    timer->start(33); // Başlat
}

Fusion::~Fusion()
{
    delete ui;
}

void Fusion::updateCameras()
{
    // --- 1. GÖRÜNTÜ OLUŞTUR (Simülasyon) ---
    if(frameRGB.empty()) frameRGB = cv::Mat(240, 320, CV_8UC3);
    if(frameThermal.empty()) frameThermal = cv::Mat(240, 320, CV_8UC3);

    // RGB Gürültü
    cv::randu(frameRGB, cv::Scalar(0, 0, 0), cv::Scalar(255, 255, 255));

    // Termal Kutu (Hareketli)
    frameThermal.setTo(cv::Scalar(0,0,0)); // Önce temizle
    static int x = 0;
    x = (x + 5) % 320;
    cv::rectangle(frameThermal, cv::Rect(x, 100, 50, 50), cv::Scalar(0, 0, 255), -1);

    // --- 2. FÜZYON ---
    cv::resize(frameThermal, frameThermal, frameRGB.size()); // Boyut eşitleme şart!
    cv::addWeighted(frameRGB, 0.6, frameThermal, 0.4, 0.0, frameFusion);

    // --- 3. EKRANA BASMA ---
    // A) RGB
    cv::cvtColor(frameRGB, frameRGB, cv::COLOR_BGR2RGB);
    QImage qimgRGB(frameRGB.data, frameRGB.cols, frameRGB.rows, frameRGB.step, QImage::Format_RGB888);
    ui->lblRGB->setPixmap(QPixmap::fromImage(qimgRGB));
    cv::cvtColor(frameRGB, frameRGB, cv::COLOR_RGB2BGR); // Geri çevir

    // B) Termal
    cv::cvtColor(frameThermal, frameThermal, cv::COLOR_BGR2RGB);
    QImage qimgThermal(frameThermal.data, frameThermal.cols, frameThermal.rows, frameThermal.step, QImage::Format_RGB888);
    ui->lblThermal->setPixmap(QPixmap::fromImage(qimgThermal));
    cv::cvtColor(frameThermal, frameThermal, cv::COLOR_RGB2BGR); // Geri çevir

    // C) Füzyon
    cv::cvtColor(frameFusion, frameFusion, cv::COLOR_BGR2RGB);
    QImage qimgFusion(frameFusion.data, frameFusion.cols, frameFusion.rows, frameFusion.step, QImage::Format_RGB888);
    ui->lblFusion->setPixmap(QPixmap::fromImage(qimgFusion).scaled(ui->lblFusion->size(), Qt::KeepAspectRatio));
}
