#ifndef OBJECTDETECT_H
#define OBJECTDETECT_H
#include <QMainWindow>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv4/opencv2/opencv.hpp>
#include <QImage>              // Görüntü dönüşümü için
#include <QPixmap>             // Ekrana basmak için

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ObjectDetect; }
QT_END_NAMESPACE

class ObjectDetect : public QMainWindow
{
    Q_OBJECT

public:
    ObjectDetect(QWidget *parent = nullptr);
    ~ObjectDetect();
private slots:
    void kameraGuncelle();

    void on_labelKamera_linkActivated(const QString &link);

private:
    Ui::ObjectDetect *ui;
    cv::VideoCapture cap; // Kamera/Video nesnesi
        QTimer *timer;        // Zamanlayıcı
        cv::Mat frame;        // Görüntü matrisi
        QImage qtImage;
        cv::dnn::Net net;
        std::vector<std::string> sinifListesi;
        void nesneleriTani(cv::Mat &img);
};
#endif // OBJECTDETECT_H
