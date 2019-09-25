#include <stdio.h>
#include <stdio_ext.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

int main(int argc, char **argv)
{
    struct sockaddr_rc addr = { 0 };
    int s, status;
    char dest[18] = "00:12:11:21:14:00";
	char byte;

    // allocate a socket
    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

    // set the connection parameters (who to connect to)
    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = (uint8_t) 1;
    str2ba( dest, &addr.rc_bdaddr );

    // connect to server
    status = connect(s, (struct sockaddr *)&addr, sizeof(addr));

    // send a message
    if( status == 0 ) {
		while(1){
			printf("Press 1 to move forward, 0 to stop, 2 to move backward,\n3 to turn right, 4 to turn left and 5 to quit\n");
			__fpurge(stdin);
			scanf("%c", &byte);
			status = write(s, &byte, 1);
			if (byte=='5')
				break;
		}
    }

    if( status < 0 ) perror("uh oh");

    close(s);
    return 0;
}
