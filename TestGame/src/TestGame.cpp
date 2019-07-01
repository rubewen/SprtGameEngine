#include <SprtGameEngine.h>

class TestGame : public Sprt::Application
{
public:
	TestGame() {

	}

	~TestGame() {

	}
};

Sprt::Application* Sprt::CreateApplication()
{
	return new TestGame();
}
