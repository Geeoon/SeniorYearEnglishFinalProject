#include <iostream>
#include "classes/scene/Scene.h"
#include "classes/ui/UI.h"

int main() {
	UI ui;
	Scene scene;
	while (ui.isOpen()) {
		ui.reset();
		
		scene.update();

		ui.draw(scene);
		ui.display();
		ui.pollEvent();
	}
	return 0;
}