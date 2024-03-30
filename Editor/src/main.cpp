#define IRD_APP_LOG
//#include <IridiumControl.h> 
#include <Iridium.h>
#include <iostream>
Ird::Application* Ird::CreateApp() {
	Ird::Application* Editor = new Ird::Application();
	std::cout << ECS(5, 10) << std::endl;
	return Editor;
}

