#ifndef MENU_H
#define MENU_H

#include <vector>
using std::vector;

#include <Surface.h>
#include <Font.h>
#include <FontManager.h>
#include <Area.h>
#include <MediaSound.h>
#include <SensitiveAreas.h>
#include <EventHandler.h>

#include "MenuItem.h"

class Menu : public EventHandler {
	private:
		short selectedItem;
		
		vector<MenuItem> items;
		
		SensitiveAreas sensAreas;
		short currentItem;
		
		Font headerFont;
		Font font;

		Surface *window;
		Surface backgroundSurf;		
		Surface pipeSurf;

		MediaSound sound;
		
		int lastY;

		void update();
		
	public:
		Menu(Surface *window);
		virtual ~Menu();

		void setSelectedItem(short selectedItem);
		short addItem(string item);
		short getSelectedItem();
		
		void reset();
		
	private:
		void onQuit(SDL_QuitEvent e);
		void onKeyDown(SDL_KeyboardEvent e);
		void onKeyUp(SDL_KeyboardEvent e);
		void onMouseButtonDown(SDL_MouseButtonEvent e);
		void onMouseButtonUp(SDL_MouseButtonEvent e);
		void onMouseMotion(SDL_MouseMotionEvent e);
};

#endif
