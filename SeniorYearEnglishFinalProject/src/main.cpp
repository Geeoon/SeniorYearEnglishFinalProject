#include <iostream>
#include "classes/scene/Scene.h"
#include "classes/ui/UI.h"

int main() {
	UI ui;
	Scene scene;
	ui.setObjFocus(scene.getPlayer());
	while (ui.isOpen()) {
		ui.reset();

		scene.update(ui.getAdjustedMouseLocation());
		ui.update();

		ui.draw(scene);
		ui.display();
		ui.pollEvent();
	}
	return 0;
}