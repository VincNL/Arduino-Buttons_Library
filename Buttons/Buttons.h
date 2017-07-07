#ifndef Buttonss_h
#define Buttonss_h

class Buttons {

public:
	Buttons(int a, bool kind);
	void help();
	bool Press();
	bool Release();
	bool Click();
	bool Hold();
	bool doubleClick();
	bool buttRead, buttState, buttPressed, buttHold = 0;
	int buttDelay = 400;
	bool click();

private:
	bool dRun;
	bool c = false;
	int buttPin;
	
};

#endif
