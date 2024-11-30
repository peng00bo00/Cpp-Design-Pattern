#pragma once

// abstract iterator
template <typename T>
class myIter
{
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual T& CurrentItem() = 0;
	virtual ~myIter() { }
};

// abstract container
template <typename T>
class myContainer
{
public:
	virtual myIter<T>* CreateIterator() = 0;
	virtual T& getItem(int index) = 0;
	virtual int getSize() = 0;
	virtual ~myContainer() {}
};

// concrete iterator
template <typename T>
class myVectorIter : public myIter<T>
{
public:
	myVectorIter(myContainer<T>* tmpc) : myvector(tmpc) {
		m_current = 0;
	}

	void First() override {
		m_current = 0;
	}

	void Next() override {
		m_current++;
	}

	bool IsDone() override {
		if (m_current > myvector->getSize())
			return true;

		return false;
	}

	T& CurrentItem() {
		return myvector->getItem(m_current);
	}

private:
	myContainer<T>* myvector;
	int m_current;
};

// concrete container
template <typename T>
class myVector : public myContainer<T>
{
public:
	myVector() {
		for (size_t i = 0; i < 10; i++)
		{
			m_elem[i] = {};
		}
	}

	myIter<T>* CreateIterator() override {
		return new myVectorIter<T>(this);
	}

	T& getItem(int index) override {
		return m_elem[index];
	}

	virtual int getSize() override {
		return sizeof(m_elem) / sizeof(T);
	}

private:
	T m_elem[10];		// fix size vector
};