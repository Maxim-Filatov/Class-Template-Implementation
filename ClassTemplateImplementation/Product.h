#pragma once
// Class template
template <class T> class Product {
	private:
		int manufacturerId;
		bool presence;
		// Generic datatype
		T requestedValue;
	public:
		// Default constructor and destructor
		Product() { presence = false; };
		~Product() {};
		// Methods for accessing private data members
		void setId(int id) { manufacturerId = id; };
		int getId() { return manufacturerId; };
		void setPresence(bool presence) { this->presence = presence; };
		bool getPresence() { return presence; };

		// Constructor with parameter
		Product(T requestedValue) {
			this->requestedValue = requestedValue;
		};

		// Method for accessing generic data member
		T getRequestedValue() { return requestedValue; }
};