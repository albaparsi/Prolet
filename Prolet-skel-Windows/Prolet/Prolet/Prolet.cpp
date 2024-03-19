#include <iostream>

int get_int();
double calculate_per_capita_gdp_estimate(int quarters_from_epoch);
std::string format_money(double money);
std::string quarter_to_ordinal(int quarter);

/*The purpose of this program is to calculate the (working-age) per-capita GDP and display it in dollars and cents. 
In order to do that we need to calculate the epoch, the number of quarters between year zero and the user's chosen date, 
and the number of quarters between the 1st quarter 1977 and the date for which the user wants to calculate the expected (working-age) per-capita GDP.
After the calculation we use the given functions to calculate GDP and turn that into a properly formatted output.
The program prompts the user for two inputs (year and quarter). 
It gathers the inputs and does the appropriate calculation and at the end displays the proper output.
*/
int main() {
	const int EPOCH_YEAR = 1977;
	const int QUARTERS_PER_YEAR = 4;
	const int EPOCH_QUARTER = 1;
	const int EPOCH = EPOCH_YEAR * QUARTERS_PER_YEAR;
	int year = 0;
	int quarter = 0;

	std::cout << "Please enter the year for the calculation: ";
	year = get_int();
	std::cout << "Please enter the quarter for the calculation: ";
	quarter = get_int();

	int quarters_yearzero_chosenyear = 0;
	quarters_yearzero_chosenyear = (year * QUARTERS_PER_YEAR) + (quarter - EPOCH_QUARTER);
	int quarters_from_epoch = quarters_yearzero_chosenyear - EPOCH;
	double per_capita_gdp = calculate_per_capita_gdp_estimate(quarters_from_epoch);

	std::cout << "In the " << quarter_to_ordinal(quarter) << " quarter of " << year << ", the projected contribution to GDP per working-age person is $" << format_money(per_capita_gdp) << ".\n";
	

	return 0;
}
