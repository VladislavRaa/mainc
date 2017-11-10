//
// Created by Vladislav Raspopin on 07.11.17.
//
#ifndef SET_SET_H
#define SET_SET_H

#include <iostream>

template <class Stype>
class Set {

public:
    Set();
    explicit Set(int size);
    Set(const Set &ob);
    ~Set() { delete SetPtr; }

    Set <Stype> operator + (Stype member);
    friend Set<Stype> operator + (Stype member, Set <Stype> ob);
    Set <Stype> operator + (Set <Stype> &ob);
    Set <Stype> operator - (Stype member);
    Set <Stype> operator - (Set <Stype> &ob);
    Set <Stype> operator & (Set <Stype> &ob);
    Set <Stype>& operator = (const Set <Stype> &ob);
	Stype& operator[] (int index);


    int operator == (Set <Stype> &ob); // 1 если равно
    int operator != (Set <Stype> &); // 1 если не равно
    int operator < (Set <Stype> &ob); // 1 если подмножество
    friend int operator < (Stype member, Set <Stype> ob); // 1 если элемент множества
    operator int() {return NumMembers;} // преобразование в целое

	struct iterator;

	iterator begin() {
		return iterator{
			.ptr = SetPtr,
			.idx = 0,
			.maxIdx = NumMembers,
		};
	}

	iterator end() {
		return iterator{
			.ptr = SetPtr,
			.idx = NumMembers,
			.maxIdx = NumMembers,
		};
	}

private:
    Stype *SetPtr;
    int MaxSize;
    int NumMembers;
    void insert (Stype member);
    void remove (Stype member);
    int find (Stype member);
    int ismember (Stype member);

public:

	struct iterator {
		Stype *ptr;
		int idx;
		int maxIdx;

		iterator &operator ++() {
			idx++;
			return *this;
		}

		iterator &operator ++(int) {
			idx++;
			return *this;
		}

		Stype &operator *() {
			return ptr[idx];
		}

		bool operator != (iterator const& other) {
			return ptr != other.ptr || idx != other.idx;
		}
	};

public:
    friend std::istream &operator >> (std::istream &stream, Set <Stype> &ob) {
        Stype member;
        stream >> member;
        ob = ob + member;
        return stream;
    }
     friend std::ostream &operator << (std::ostream &stream, const Set<Stype> &ob) {
        for (int i = 0; i < ob.NumMembers; i++) {
            stream << ob.SetPtr[i] << ' ';
        }
        stream << std::endl;
        return stream;
    }
};

const int DEFEST = 100;

template <class Stype>
Set <Stype>::Set ()
        : NumMembers(0)
	, MaxSize(DEFEST)
	, SetPtr(new Stype [DEFEST])
{
}

template <class Stype>
Set <Stype>::Set (int size)
        : NumMembers(0),  MaxSize(size) {
    try {
        SetPtr = new Stype [size];
        if (!SetPtr) throw std::bad_alloc();

    } catch (const std::bad_alloc& e) {
        std::cerr << e.what() <<std::endl;
        exit(1);
    }
}

template <class Stype>
int Set <Stype>::find (Stype member) {
    for (int i = 0; i < NumMembers; i++) {
        if (SetPtr[i] == member) return 1;
    }
    return -1;
}

template <class Stype>
int Set <Stype>::ismember(Stype member) {
    if (find(member) != -1) return 1;
    else return 0;
}

template <class Stype>
void Set <Stype>::insert (Stype member) {
    try {
        if (NumMembers == MaxSize) throw std::out_of_range("MaxSize < NumMember");
    } catch (const std::bad_alloc &e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
    if (!ismember((member))) {
        SetPtr[NumMembers] = member;
        NumMembers++;
    }
}

template <class Stype>
void Set <Stype>::remove (Stype member) {
    int loc = find(member);
    if (loc != -1) {
        for (; loc < NumMembers - 1; loc++) {
            SetPtr[loc] = SetPtr[loc + 1];
            NumMembers--;
        }
    }
}

template <class Stype>
Set<Stype>::Set(const Set<Stype> &ob)
	: MaxSize(ob.MaxSize)
	, SetPtr(new Stype[ob.MaxSize])
	, NumMembers(0)
{
    for (int i = 0; i < ob.NumMembers; i++) {
        insert(ob.SetPtr[i]);
    }
}

template <class Stype>
Set<Stype>& Set<Stype>::operator = (const Set<Stype> &ob) {
    if(SetPtr == ob.SetPtr) return *this;

    if(ob.NumMembers > MaxSize) {
        delete SetPtr;
        try {
            SetPtr = new Stype[ob.NumMembers];
            if (!SetPtr) throw std::bad_alloc();
        } catch (const std::bad_alloc &e) {
            std::cerr << e.what() << std::endl;
            exit(1);
        }
        MaxSize = ob.NumMembers;
    }
    NumMembers = 0;
    for (int i = 0; i < ob.NumMembers; i++) {
        insert(ob.SetPtr[i]);
    }
    return *this;
}

template <class Stype>
Set<Stype> Set<Stype>::operator+(Stype member) {
    Set<Stype> temp(NumMembers+1);
    for (int i = 0; i < NumMembers; i++) {
        temp.insert(SetPtr[i]);
    }
    temp.insert(member);
    return temp;
}

template <class Stype>
Set<Stype> operator+(Stype member, Set<Stype> ob) {
    Set<Stype> temp(ob.NumMembers + 1);

    for (int i = 0; i < ob.NumMembers; i++) {
        temp.insert(ob.SetPtr[i]);
    }
    temp.insert(member);
    return temp;
}

template <class Stype>
Set<Stype> Set<Stype>::operator+(Set<Stype> &ob) {

    Set<Stype>temp (NumMembers+ob.NumMembers);
    for(int i = 0; i < NumMembers; i++) {
        temp.insert(SetPtr[i]);
    }

    for(int i = 0; i < ob.NumMembers; i++) {
        temp.insert(ob.SetPtr[i]);
    }
    return temp;

}

template <class Stype>
Set<Stype> Set<Stype>::operator-(Stype member) {
    Set<Stype> temp = *this;
    temp.remove(member);
    return temp;
}

template <class Stype>
Set<Stype> Set<Stype>::operator-(Set<Stype> &ob) {

    Set<Stype> temp = *this;

    for (int i = 0; i < NumMembers; i++) {
        if (ob.ismember(SetPtr[i])) {
            temp.remove(SetPtr[i]);
        }
    }
    return temp;
}

template <class Stype>
Set<Stype> Set<Stype>::operator& (Set<Stype> &ob) {
    Set<Stype> temp(NumMembers);
    for(int i = 0; i < NumMembers; i++)
        if(ob.ismember(SetPtr[i]))
            temp.insert(SetPtr[i]);
    return temp;
}

template <class Stype>
int Set<Stype>::operator == (Set<Stype> &ob) {
    if(NumMembers != ob.NumMembers) return 0;

    return *this < ob;
}

template <class Stype>
int Set<Stype>::operator != (Set<Stype> &ob) {
    return !(*this == ob);
}

template <class Stype>
int Set<Stype>::operator < (Set<Stype> &ob) {

    for (int i = 0; i < NumMembers; i++)
        if (!ob.ismember(SetPtr[i])) return 0;
    return 1;
}

template <class Stype>
int operator < (Stype member, Set<Stype> ob) {
    if (ob.ismember(member)) return 1;
    return 0;
}

template <class Stype>
Stype& Set<Stype>::operator[] (int index) {
    return SetPtr[index];
}

#endif //SET_SET_H
