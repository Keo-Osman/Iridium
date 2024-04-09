#define IRD_APP_LOG
//#include <IridiumControl.h> 
#include <Iridium.h>
#include <iostream>
Ird::Application* Ird::CreateApp() {
	Ird::Application* Editor = new Ird::Application();
	return Editor;
}

