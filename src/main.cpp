int main(int argc, char* argv[])
{
		FILE* fd = fopen("input.net", "r");
		
		readHeader();
		std::vector parts = readParts(fd);
		std::vector wires = readParts(fd);
}
