#include "support/InputParser.h"
#include "GachaOptions.h"
#include "Gacha.h"

int main(int argc, char** argv)
{
	InputParser parser(argc, argv);
	Gacha::GachaOptions options{};
	if (options.fromParser(parser))
	{
		options.print();
		Gacha::GachaMainLoop(options);
	}
	system("PAUSE");
	return 0;
}