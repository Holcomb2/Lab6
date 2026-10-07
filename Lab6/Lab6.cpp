#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
int main() {
	string background = "images1/backgrounds/alebrije.png";
	string foreground = "images1/characters/yoda.png";
	Texture backgroundTex;
	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Texture foregroundTex;
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Image backgroundImage;
	backgroundImage = backgroundTex.copyToImage();
	Image foregroundImage;
	foregroundImage = foregroundTex.copyToImage();
	Vector2u sz = backgroundImage.getSize();
	for (int y = 0; y < sz.y; y++) {
		for (int x = 0; x < sz.x; x++) {
			// These two loops will run the code inside for each pixel in
				// You can access the current pixel at x,y like so:
				Color f = foregroundImage.getPixel(x,y);
				Color b = backgroundImage.getPixel(x, y);
				
				if (f.g > 200 && f.r < 100 && f.b < 100) {
					foregroundImage.setPixel(x, y, Color(0, 0, 0, 0));
				}
			

				
				
			
				

			// Color objects store the individual channel values like
		
		}
	}
	// By default, just show the foreground image
	RenderWindow window(VideoMode(1024, 768), "Here's the output");
	Sprite sprite1;
	Sprite sprite2;
	Texture tex1;
	Texture tex2;
	tex2.loadFromImage(backgroundImage);
	tex1.loadFromImage(foregroundImage);
	sprite1.setTexture(tex1);
	sprite2.setTexture(tex2);
	window.clear();
	window.draw(sprite2);
	window.draw(sprite1);
	window.display();
	while (true);
}