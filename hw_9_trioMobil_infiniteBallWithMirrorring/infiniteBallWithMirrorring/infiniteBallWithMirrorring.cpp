#include <opencv2/opencv.hpp>
#include <cstdlib>
#include <ctime>

using namespace cv;
using namespace std;

int main() {
    namedWindow("Mirroring Ball", WINDOW_AUTOSIZE);

    Mat image = Mat::zeros(500, 500, CV_8UC3);

    int radius = 25;
    Scalar color(255, 255, 0); // Red color in BGR format
    Point center(image.cols / 2, image.rows / 2);

    int dx = rand() % 5 - 2; // Random initial x direction
    int dy = rand() % 5 - 2; // Random initial y direction

    srand(static_cast<unsigned>(time(nullptr))); // Seed for rand()

    while (true) {
        // Clear the image
        image = Mat::zeros(500, 500, CV_8UC3);

        // Update the ball's position
        center.x += dx;
        center.y += dy;

        // Check for collision with the edges and bounce randomly
        if (center.x + radius > image.cols || center.x - radius < 0) {
            dx = -dx; // Reverse the x direction on collision
            dy = rand() % 5 - 2; // Random y direction after collision
        }
        if (center.y + radius > image.rows || center.y - radius < 0) {
            dy = -dy; // Reverse the y direction on collision
            dx = rand() % 5 - 2; // Random x direction after collision
        }

        // Draw the ball
        circle(image, center, radius, color, -1);

        // Display the image in the window
        imshow("Mirroring Ball", image);

        // Wait for a short duration
        waitKey(3);
    }

    destroyWindow("Mirroring Ball");

    return 0;
}
