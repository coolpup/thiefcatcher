#include "InputBox.h"

InputBox::InputBox() {
}

InputBox::InputBox(Font *font_, const Point &point_,
	const Dimension &dimension_) :
	font(font_), point(point_), dimension(dimension_) {
	background = Color(255, 255, 255);

	line = Text("", font);

	//	SDL_EnableUNICODE(1);
	//	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);

	setMaxChars(25);
}

InputBox::~InputBox() {
	//	SDL_EnableKeyRepeat(0, 0);
	//	SDL_EnableUNICODE(0);
}

void InputBox::setBackground(const Color & background) {
	this->background = background;
}

void InputBox::setForeground(const Color & foreground) {
	this->foreground = foreground;
}

void InputBox::setFont(Font * font) {
	this->font = font;
	this->font->setColor(foreground);

	line.setFont(font);
}

string InputBox::getText() {
	return text;
}

void InputBox::handleEvent(SDL_Event & e) {
	if (e.type == SDL_KEYDOWN) {
		SDL_Keycode key = e.key.keysym.sym;
		putChar(key);
	}
}

void InputBox::update() {
}

void InputBox::setMaxChars(unsigned short maxChars) {
	this->maxChars = maxChars;
}

unsigned short InputBox::getMaxChars() const {
	return maxChars;
}

string InputBox::get() {
	SDL_Event event;
	bool quit = false;
	while (!quit) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_RETURN) {
					quit = true;
				}
				break;
			}
			handleEvent(event);
			line.setText(text.c_str());
			update();
		}
		SDL_Delay(100);
	}

	return getText();
}

void InputBox::clear() {
	text.clear();
}

void InputBox::putChar(SDL_Keycode key) {
	if (text.size() < maxChars && ((key >= SDLK_a && key <= SDLK_z) || (key
		>= SDLK_0 && key <= SDLK_9) || key == SDLK_SPACE)) {
		text += key;
	}
	else if (key == SDLK_BACKSPACE) {
		text = text.substr(0, text.size() - 1);
	}
}
