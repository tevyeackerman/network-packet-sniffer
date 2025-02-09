#ifndef PACKET_CAPTURE_H
#define PACKET_CAPTURE_H

#include <iostream>

#include <sys/socket.h> //handles socket addresses
#include <netinet/in.h> // handles socket addresses
#include <pcap.h> //includes libpcap functions for capturing packets
#include <arpa/inet.h> //handles socket addresses

#include <cstdint>

class PACKET_CAPTURE{
	public:
		PACKET_CAPTURE();
		~PACKET_CAPTURE();

		bool START_CAPTURE(); //Starts capturing packets.
		static void PACKET_HANDLER(u_char *userData, const struct pcap_pkthdr *pkthdr, const u_char *packet); //Packet handler callback

	private:
		struct NETWORK_PACKET{
			uint16_t port_number; //Port number of the packet
			uint8_t protocol_type; //Protocol type (TCP,UDP etc.)
			uint32_t packet_size; //Size of the captured packet
			struct sockaddr_storage addr; //Address storage (could be IPv4 or IPv6)
		};

		pcap_t *handle; //pcap handle for live packet capture
}

#endif //PACKET_CAPTURE_H
