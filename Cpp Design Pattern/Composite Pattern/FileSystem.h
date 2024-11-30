#pragma once
#include <string>
#include <iostream>
#include <list>

class FileSystem
{
public:
	virtual void ShowName(int level) = 0;

	virtual int Add(FileSystem* pfilesys) = 0;
	virtual int Remove(FileSystem* pfilesys) = 0;
	virtual ~FileSystem() { }
};

class File : public FileSystem
{
public:
	File(std::string name) : m_name(name) { }

	void ShowName(int level) override {
		std::cout << std::string(2*level, ' ')
			<< "- " << m_name << std::endl;
	}

	int Add(FileSystem* pfilesys) override {
		// a file instance cannot add anything
		return -1;
	}

	int Remove(FileSystem* pfilesys) override {
		// a file instance cannot remove anything
		return -1;
	}

private:
	std::string m_name;
};

class Dir : public FileSystem
{
public:
	Dir(std::string name) : m_sname(name) {}

	void ShowName(int level) override {
		std::cout << std::string(2*level, ' ')
			<< "+ " << m_sname << std::endl;

		level++;
		for (auto iter = m_child.begin(); iter != m_child.end(); ++iter) {
			(*iter)->ShowName(level);
		}
	}

	int Add(FileSystem* pfilesys) override {
		m_child.push_back(pfilesys);
		return 0;
	}

	int Remove(FileSystem* pfilesys) override {
		m_child.remove(pfilesys);
		return 0;
	}

private:
	std::string m_sname;
	std::list<FileSystem*> m_child;
};