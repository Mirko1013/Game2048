#pragma once

class Command {
public:
	virtual void execute() {};
	virtual bool check() { return false; };
};
