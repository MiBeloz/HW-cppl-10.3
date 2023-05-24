#pragma once


template<class T>
class unique_ptr {
public:
	explicit unique_ptr(T* const ptr = nullptr) : m_ptr(ptr) {};
	
	~unique_ptr();
	
	T& operator*() const;
	T* operator->() const;
	T* get() const;
	T* release();
	void reset(T* const new_ptr = nullptr);
	void swap(unique_ptr& right);
	explicit operator bool() const;

	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;

	friend std::ostream& operator<<(std::ostream& os, const unique_ptr<T>& obj) {
		return os << &*obj;
	}

private:
	T* m_ptr;
};

template<class T>
inline unique_ptr<T>::~unique_ptr() {
	delete m_ptr;
	m_ptr = nullptr;
}

template<class T>
T& unique_ptr<T>::operator*() const {
	return *m_ptr;
}

template<class T>
T* unique_ptr<T>::operator->() const {
	return m_ptr;
}

template<class T>
T* unique_ptr<T>::get() const {
	return m_ptr;
}

template<class T>
T* unique_ptr<T>::release() {
	T* other_ptr = m_ptr;
	m_ptr = nullptr;
	return other_ptr;
}

template<class T>
void unique_ptr<T>::reset(T* const new_ptr) {
	if (m_ptr) {
		delete m_ptr;
		m_ptr = nullptr;
	}
	if (new_ptr) {
		m_ptr = new_ptr;
	}
}

template<class T>
void unique_ptr<T>::swap(unique_ptr& right) {
	std::swap(m_ptr, right.m_ptr);
}

template<class T>
unique_ptr<T>::operator bool() const {
	return static_cast<bool>(m_ptr);
}
