#include <duke/cmdline/CmdLineParameters.h>
#include <duke/engine/Duke.h>

int main(int argc, char** argv) {
	using namespace duke;
	try {
		const CmdLineParameters parameters(argc, argv);
		Duke duke(parameters);
		duke.run();
	} catch (duke::commandline_error &e) {
		fprintf(stderr, "Command line says : %s\n", e.what());
		return EXIT_FAILURE;
	} catch (std::exception &e) {
		fprintf(stderr, "Unexpected error\n%s\n", e.what());
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
