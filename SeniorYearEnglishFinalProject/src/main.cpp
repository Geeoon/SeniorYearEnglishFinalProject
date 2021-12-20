#include <iostream>
#include "classes/text/ConsoleHelper.h"
#include "classes/FontStorage.h"
#include "classes/scene/Scene.h"
#include "classes/ui/UI.h"

int main() {
	
	ConsoleHelper::wait(5000);
	ConsoleHelper::print("Hello,\n");
	ConsoleHelper::wait(1000);
	ConsoleHelper::print("I've been waiting for you.\n");
	ConsoleHelper::wait(1000);
	ConsoleHelper::print("I'm your computer, ");
	ConsoleHelper::wait(1000);
	ConsoleHelper::print("and I need your help.\n");
	ConsoleHelper::wait(2000);
	ConsoleHelper::print("You've visited some pretty sketchy websites recently.\n");
	ConsoleHelper::wait(1000);
	ConsoleHelper::print("Now you've infected me with millions of viruses.\n");
	ConsoleHelper::wait(1000);
	ConsoleHelper::print("It's your job to save me by killing these viruses and cleaning up the mess you've made.\n");
	ConsoleHelper::wait(2000);
	ConsoleHelper::print("I've trapped one of the viruses, and I'm throwing you into a training level, ");
	ConsoleHelper::wait(1500);
	ConsoleHelper::print("good luck.\n");
	
	UI ui;
	Scene scene;
	if (!FontStorage::font.loadFromFile("dependencies/fonts/SourceCodePro-Regular.ttf")) {
		return 1;
	}
	ui.setObjFocus(scene.getPlayer());
	while (ui.isOpen() && scene.getDone() == 0) {
		ui.reset();

		scene.update(ui.getAdjustedMouseLocation());
		ui.update();

		ui.draw(scene);
		ui.display();
		ui.pollEvent();
	}
	if (ui.isOpen()) {
		ui.close();
	}
	ConsoleHelper::wait(3000);
	if (scene.getDone() == 1) {
		ConsoleHelper::print("Congrats, you finished the tutorial, ");
		ConsoleHelper::wait(1000);
		ConsoleHelper::print("time for you to start doing real work.");
	} else {
		ConsoleHelper::print("Wow, ");
		ConsoleHelper::wait(1500);
		ConsoleHelper::print("you somehow managed to die.\n");
		ConsoleHelper::wait(1500);
		ConsoleHelper::print("I guess we're screwed now.");
	}
	ConsoleHelper::wait(10000);
	return 0;
}