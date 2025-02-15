#pragma once
#include "RaiseRequest.h"
#include <iostream>

class ParSalApprover
{
public:
	ParSalApprover() : m_nextChain(nullptr) { }
	virtual ~ParSalApprover() { }

	void setNextChain(ParSalApprover* next) {
		m_nextChain = next;
	}

	virtual void processRequest(const RaiseRequest& req) = 0;

protected:
	void sendRequestToNextHandler(const RaiseRequest& req) {
		if (m_nextChain != nullptr) {
			m_nextChain->processRequest(req);
		}
		else {
			std::cout << "Request cannot be handled!" << std::endl;
		}
	}

private:
	ParSalApprover* m_nextChain;
};

class depManager_SA : public ParSalApprover
{
public:
	virtual void processRequest(const RaiseRequest& req)
	{
		int salfigure = req.getSalFigure();

		if (salfigure <= 1000) {
			std::cout << "Request is handled by Department Manager." << std::endl;
		}
		else {
			sendRequestToNextHandler(req);
		}
	}
};

class CTO_SA : public ParSalApprover
{
public:
	virtual void processRequest(const RaiseRequest& req)
	{
		int salfigure = req.getSalFigure();

		if (1000 < salfigure && salfigure <= 5000) {
			std::cout << "Request is handled by CTO." << std::endl;
		}
		else {
			sendRequestToNextHandler(req);
		}
	}
};

class genmMnager_SA : public ParSalApprover
{
public:
	virtual void processRequest(const RaiseRequest& req)
	{
		int salfigure = req.getSalFigure();

		if (salfigure > 5000) {
			std::cout << "Request is handled by Manager." << std::endl;
		}
		else {
			sendRequestToNextHandler(req);
		}
	}
};