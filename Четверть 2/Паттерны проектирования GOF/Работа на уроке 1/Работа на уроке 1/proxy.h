#pragma once
#include <iostream>

class IFile
{
public:
	virtual void Write() = 0;
};

class RealDoc : public IFile
{
public:
	void Write() override
	{
		std::cout << "Doc is write" << std::endl;
	}
};

class ProxyDoc : public IFile
{
private:
	RealDoc* realDoc;
	bool CheckAcces() const
	{
		std::cout << "Proxy : Acces" << std::endl;
		return true;
	}
	void LogTime()
	{
		std::cout << "Proxy : Logtime" << std::endl;
	}
public:
	ProxyDoc() : realDoc(new RealDoc()) {}
	void Write() override
	{
		if (this->CheckAcces())
		{
			realDoc->Write();
			this->LogTime();
		}
	}
};