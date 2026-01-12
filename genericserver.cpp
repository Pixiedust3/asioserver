#include<boost/asio.hpp>
#include<iostream>

template<typename Connection_handler>

class asio_generic_server{
    public:
    using shared_handler_t=std::shared_ptr<Connection_handler>

    asio_generic_server(int thread_count=1)
    :thread_count_(thread_count),
    acceptor_(io_service_){}

    void start_server(u_int16_t port)
    {

    }
    private:
    void handle_new_connection(shared_handler_t handler,system::error_code const & error)
    {

    }

    int thread_count_;
    std::vector<std::thread> thread_pool_;
    asio::io_service io_service_;
    asio::ip::tcp::acceptor acceptor_;
};

