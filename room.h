#include <string>

class room
{
	private:
		int typeIndex;
		std:string type;
		int floorSpace;

	public:
		void setTypeIndex(int &input); // pass by ref, not pass by pointer
		void setType(std::string &input);
		void setFloorSpace(int &input);
}
