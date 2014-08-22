/* -*-mode:c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#ifndef LOCAL_PROXY_HH
#define LOCAL_PROXY_HH

#include <string>

#include "address.hh"
#include "socket.hh"
#include "event_loop.hh"
#include "socket.hh"
#include "secure_socket.hh"
#include "archive.hh"

static const std::string could_not_find = "HTTP/1.1 200 OK\r\nContent-Type: Text/html\r\nConnection: close\r\nContent-Length: 24\r\n\r\nCOULD NOT FIND AN OBJECT";

class LocalProxy
{
private:
    Socket listener_socket_;
    Address remote_proxy_addr_;

    Archive archive;

    template <class SocketType>
    std::string get_response( const HTTPRequest & new_request, const std::string & scheme, SocketType && server );

    template <class SocketType>
    void handle_client( SocketType && client, const std::string & scheme );

public:
    LocalProxy( const Address & listener_addr, const Address & remote_proxy_addr );

    Socket & tcp_listener( void ) { return listener_socket_; }

    void listen( EventLoop & event_loop );

    /* TODO: Need to fix these things */
    void register_handlers( EventLoop & event_loop ) { listen( event_loop ); }

    /* TODO: Serialize results to socket */
    void serialize_to_socket( Socket && socket_output __attribute__ ((unused)) ) { printf("WARNING NOT IMPLEMENTED\n"); }
};

#endif /* LOCAL_PROXY_HH */