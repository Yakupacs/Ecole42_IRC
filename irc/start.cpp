#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
	// Soket oluşturma
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		std::cerr << "Soket oluşturulamadı." << std::endl;
		return 1;
	}

	// Sunucu adresi ve portu
	std::string serverIP = "127.0.0.1";
	int serverPort = 8080;

	// Sunucu adres ve portunu ayarlama
	sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = inet_addr(serverIP.c_str());
	serverAddress.sin_port = htons(serverPort);

	// Sunucuya bağlanma
	if (connect(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
		std::cerr << "Sunucuya bağlanılamadı." << std::endl;
		close(sockfd);
		return 1;
	}

	// Soket işlemleri

	// Soketi kapatma
	close(sockfd);

	return 0;
}
