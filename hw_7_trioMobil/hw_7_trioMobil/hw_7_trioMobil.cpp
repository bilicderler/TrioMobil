#include <opencv2/core.hpp>
#include "opencv2/video.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <chrono>
#include <ctime>


using namespace cv;
using namespace std;
using namespace chrono;


// Tarih ve saati sol-üst köşeye koyan fonksiyon
Mat Write_date_and_time_on_frame(Mat fr) {
    if (fr.empty())
    {
        cout << "Görüntü yüklenemedi." << "\n";
        return fr;
    }

    // Tarih ve saat bilgisini al
    time_t now;
    struct tm timeinfo;
    char dateTime[100];
    time(&now);
    localtime_s(&timeinfo, &now);
    strftime(dateTime, sizeof(dateTime), "%d.%m.%Y %H:%M:%S", &timeinfo);

    // Tarih ve saat yazısını görüntüye ekle
    putText(fr, dateTime, Point(10, 30), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);
    return fr;
}

int main()
{
    // Videoyu aç (döngüyle içindeki tüm dosyaları sırasıyla alabiliriz)
    VideoCapture cap("C:\\Users\\BILICI\\Desktop\\videos_with_frames\\sample.mp4"); // 
    if (!cap.isOpened())
    {
        cout << "Video acilamadi." << endl;
        return -1;
    }

    // Kaydedilecek frame'in numarasını tutacak değişken
    int saveCount{ 0 };
    // Video özelliklerini al
    int frameCount = static_cast<int>(cap.get(CAP_PROP_FRAME_COUNT));
    // VideoWriter oluştur
    int codec = VideoWriter::fourcc('X', 'V', 'I', 'D');
    double fps = cap.get(CAP_PROP_FPS);
    Size frameSize(cap.get(CAP_PROP_FRAME_WIDTH), cap.get(CAP_PROP_FRAME_HEIGHT));
    string outputVideoPath = "C:\\Users\\BILICI\\Desktop\\videos_with_frames\\output_" + to_string(saveCount) + ".mp4"; //videwriter ile tarih ve saati yazdırılmış videonun kaydedileceği yol
    VideoWriter writer(outputVideoPath, codec, fps, frameSize);

    

    while (true)
    {
        Mat frame;
        cap >> frame;
        // Video bittiğinde çık
        if (frame.empty())
            break;
        // her frame'i yaz
        frame = Write_date_and_time_on_frame(frame);

        // Frame'i VideoWriter'a yaz
        writer.write(frame);

        // Frame'i ayrı bir JPEG dosyasına kaydet
        string filename = "C:\\Users\\BILICI\\Desktop\\videos_with_frames\\frames\\frame_" + to_string(saveCount) + ".jpg";
        imwrite(filename, frame);

        saveCount += 1;
    }

    // VideoWriter'ı ve VideoCapture'ı serbest bırak
    writer.release();
    cap.release();

    cout << "Kaydetme tamamlandi." << endl;

    return 0;
}