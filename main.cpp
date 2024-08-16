#include <blend2d.h>
#include <emscripten.h>

constexpr int WIDTH = 400;
constexpr int HEIGHT = 400;

int main()
{
    BLImage img(WIDTH, HEIGHT, BL_FORMAT_PRGB32);
    BLContext c(img);

    BLPath p;
    p.addCircle(BLCircle(200.0f, 200.0f, 200.0f));
    c.fillPath(p, BLRgba32(255, 0, 0));

    c.end();

    BLImageData imgData;
    img.getData(&imgData);

    EM_ASM({
        let canvas = document.getElementById("canvas");
        let c = canvas.getContext("2d");

        canvas.width = $0;
        canvas.height = $1;

        let start = $2;
        let end = start + ($0 * $1 * 4);
        let pixels = new Uint8ClampedArray(HEAPU8.slice(start, end));
        let imageData = new ImageData(pixels, $0, $1);

        c.putImageData(imageData, 0, 0);
    }, WIDTH, HEIGHT, imgData.pixelData);
}
