#ifndef INVENTORY_HPP_
#define INVENTORY_HPP_
//템플릿 클래스를 위한 hpp파일

#include <iostream>
#include <algorithm>

template<typename T>

class Inventory {
private:
	T* pItems_;
	int capacity_;
	int size_ = 0;

public:
	Inventory(int s) : size_(s) {
		pItems_ = new T[capacity_];
	}

	void AddItem(T item) {
		if (capacity_ == size_) {
			Resize(capacity_ * 2);
		}
		pItems_[size_] = item;
		size_++;
	}

	void RemoveLastItem() {
		if (size_) {
			pItems_[size_ - 1] = 0;
			size_--;
			std::cout << "제거 되었습니다." << std::endl;
		}
		else {
			std::cout << "인벤토리가 비었습니다." << std::endl;
		}
	}

	void PrintAllItems() {
		if (size_) {
			for (int i = 0; i < size_; i++) {
				std::cout << i + 1 << ". " << pItems_[i].PrintInfo();
			}
		}
		else {
			std::cout << "인벤토리가 비었습니다." << std::endl;
		}
	}

	void Resize(int newCapacity) {
		capacity_ = newCapacity;

		T* tmpItem = new T[newCapacity]; //새배열 임시할당

		for (int i = 0; i < size_; i++) { //내용물 복사
			tmpItem[i] = pItems_[i];
		}

		delete[] pItems_; //기존배열 할당해제

		pItems_ = tmpItem; //임시배열을 기존 아이템 포인터에 대입
	}

	//getter
	int GetSize() {
		return size_;
	}
	int GetCapacity() {
		return capacity_;
	}

	~Inventory() {
		delete[] pItems_;
	}

	//복사 생성자 주소값의 복사를 막아 깊은 복사를 위해
	Inventory(const Inventory& other) {
		this->capacity_ = other.capacity_;
		this->size_ = other.size_;
		this->pItems_ = new T[other.capacity_];

		for (int i = 0; i < this->size_; i++) {
			this->pItems_[i] = other.pItems_[i];
		}
	}

	//복사 대입 연산자
	Inventory& operator = (const Inventory& other) {
		if (this != &other) {
			delete[] this->pItems_;

			this->capacity_ = other.capacity_;
			this->size_ = other.size_;
			this->pItems_ = new T[other.capacity_];

			for (int i = 0; i < this->size_; i++) {
				this->pItems_[i] = other.pItems_[i];
			}
		}
		return *this;
	}

};
#endif