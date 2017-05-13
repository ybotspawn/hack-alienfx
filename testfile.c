#include "functions.h"
#include <syslog.h>
/*
 * This method sends a line to the keyboard
 * Returns:
 *   0 - On success
 *   4 - On invalid line
 *   5 - On error sending the line
 */
int __apply_theme_component__(char* line){
  int ret;
  unsigned char buf[9];

  ret = parse_bytes(line, buf);
  if(ret != 0) {
    return 4;
  }
  usleep(150);
  ret = send_message(buf);
  if(ret != 0) {
    return 5;
  }
  return 0;
}

int apply_theme(int argc, char** argv){
  char* line = NULL;
  char* clean = NULL;
  size_t len = 0;
  ssize_t read;

  while ((read = getline(&line, &len, file)) != -1) {	    
      if (line!=NULL && strcmp(line, "\n") && lineDoesNotStartwith#) {
        clean = trim(line);
        switch (__apply_theme_component__(clean)){
          case 0:
            //printf(" - %s\n", clean);
            break;
          case 4:
            //printf(" + Invalid line: %s\n", clean);
            break;
          case 5:
            //printf(" + Cannot send message: %s\n", clean);
            break;
          default:
            //printf(" + This was unexpected and not my fault\n");
            fclose(file);
            deinit_device();
            return -1;
        }
        }
      }
	  }

	  fclose(file);
	  deinit_device();
	  return 0;
}

int write_log_message() {
  return 0;
}

int clear(){
  	libusb_device_handle *dev;
	int ret;

	ret = libusb_init(NULL);
	if(ret != 0) {
		fprintf(stderr, "failed to initialize libusb\n");
		return 1;
	}

	// DEBUG
	libusb_set_debug(NULL, LIBUSB_LOG_LEVEL_DEBUG);

	dev = libusb_open_device_with_vid_pid(NULL, 0x187c, 0x0527);
	if(dev == NULL) {
		fprintf(stderr, "failed to open usb device\n");
		return 1;
	}

	libusb_detach_kernel_driver(dev, 0);
	libusb_reset_device(dev);
	libusb_close(dev);

	libusb_exit(NULL);
	return 0;
}

int main(int argc, char** argv){
    char* clean = NULL;
    clean = trim("02:03:02:00:00:08:0f:00");
    printf("Cleaned Output: %s\n", clean);
    int ret;
    unsigned char buf[9];
    ret = parse_bytes(clean, buf);
    printf("Parse_bytes (ret) output: %i\n", ret);
    int i;
    for (i = 0; i<10; i++)
    	printf("Parse_bytes (buf) output: %i\n", buf[i]);
    printf("EOL\n");
}
