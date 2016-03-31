#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include "vrpn-master/vrpn_Connection.h"
#include "vrpn-master/vrpn_Button.h"
#include "vrpn-master/vrpn_Tracker_RazerHydra.h"

int main(int argc, char* argv[])
{
	vrpn_Connection *connection = vrpn_create_server_connection();
	vrpn_Tracker    *tracker;
	vrpn_Button *button;

	tracker = new vrpn_Tracker_RazerHydra("Tracker1", connection);
	button = new vrpn_Button_Python("Button0", connection, 1);
	
	while (true) {
		button->mainloop();

		// Let all the trackers generate reports
		tracker->mainloop();

		// Send and receive all messages
		connection->mainloop();
	}
}
