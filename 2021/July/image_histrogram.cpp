#include <iostream>
#include <vector>
using namespace std;

typedef uint8_t _byte;
typedef vector<vector<_byte>> image;

void read_img(image& img)
{

    int N = img.size();
    int M = img[0].size();
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> img[i][i];
        }
    }
}

void print_histogram(vector<unsigned int>& histogram) {

    for (int i = 0; i < 255; ++i) {
        cout << i << " " << histogram[i] << endl;
    }

}

int main()
{
    int N, M;
    cin >> N >> M;
    image img = vector<vector<_byte>>(N, vector<_byte>(N));
    read_img(img);

    vector<unsigned int> histogram = vector<unsigned int>(256, 0);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            ++histogram[img[i][j]];
        }
    }

    print_histogram(histogram);
}
