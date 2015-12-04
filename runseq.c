#include "functions.h"

int main() {
	unsigned char buf[9];
	char *line;
	int ret;

	if(init_device() != 0)
		return 1;

	while(1) {
	   
		line = readline("> ");
		if(line == NULL)
			break;

		if(line[0] == '#') /* comment */
			goto skip_line;

		if(line[0] == 'q') /* quit */
			break;

		if(line[0] == 'w') /* wait */ {
			usleep(100000);
			goto skip_line;
		}

		ret = parse_bytes(line, buf);
		if(ret != 0) {
			fprintf(stderr, "Error: invalid input - \"%s\"\n", line);
			break;
		}

		ret = send_message(buf);
		if(ret != 0) {
			fprintf(stderr, "Error: failed to send message\n");
			break;
		}

		add_history(line);

	skip_line:
		free(line);
		line = NULL;
	}

	if(line)
		free(line);

	deinit_device();

	printf("\n");
	return ret;
}
