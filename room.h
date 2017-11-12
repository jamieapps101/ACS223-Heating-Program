#include <string>

class room
{
	private:
		int typeIndex;
		std::string type;
		int floorSpace;
		float hoursPerDayHeated;
		float daysPerYearHeated;
		float heatingTemp;

	public:
		room();
		void setTypeIndex(int &input); // pass by ref, not pass by pointer
		void setType(std::string &input);
		void setFloorSpace(int &input);
		void sethoursPerDayHeated(float &input);
		void setDaysPerYearHeated(float &input);
		void setHeatingTemp(float &input);

    int getTypeIndex();
    std::string getType();
    int getFloorSpace();
		float getHoursPerDayHeated();
		float getDaysPerYearHeated();
		float getHeatingTemp();
};
