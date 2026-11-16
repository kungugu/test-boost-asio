// main.cpp
#include <boost/asio.hpp>
#include <iostream>
using namespace boost::asio;

int main() {
    io_context io;
    ip::tcp::acceptor acceptor(io, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 12345));
    ip::tcp::socket socket(io);
    acceptor.accept(socket);
    std::cout << "клиент подключился\n";
    char buff[1024];
    size_t bytes = socket.read_some(buffer(buff));
    write(socket, buffer(buff, bytes));
    
}