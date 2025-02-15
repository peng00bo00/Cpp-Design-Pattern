#pragma once
#include <string>

class RaiseRequest
{
public:
	RaiseRequest(const std::string& sname, int salfigure) :
		m_sname(sname), m_isalfigure(salfigure) {  }

	const std::string& getName() const {
		return m_sname;
	}

	int getSalFigure() const {
		return m_isalfigure;
	}

private:
	std::string m_sname;
	int m_isalfigure;
};

