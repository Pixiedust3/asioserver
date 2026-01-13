#include<boost/asio.hpp>
#include<iostream>

template<typename Connection_handler>

class asio_generic_server{
    public:
    using shared_handler_t=std::shared_ptr<Connection_handler>;

    asio_generic_server(int thread_count=1)
    :thread_count_(thread_count),
    acceptor_(io_service_){}

    void start_server(u_int16_t port)
    {
        auto handler=std::make_shared<Connection_handler>(io_service_);
        boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(),port);
        acceptor_.open(endpoint.protocol());
        acceptor_.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
        acceptor_.bind(endpoint);
        acceptor_.listen();

        acceptor_.async_accept(handler->socket(),[=](auto ec)
        {
            handle_new_connection(handler,ec);
        });

    }
    for( int i{0};i<thread_count_;++i)
    {
        thread_pool_.emplace_back([=]{
            io_service_.run();
        });
    }
    private:
    void handle_new_connection(shared_handler_t handler,system::error_code const & error)
    {
        if(error)
        {
            return;
        }
        handler->start();
         auto new_handler=std::make_shared<COnnectionHandler>(io_service_);
         
    }


    int thread_count_;
    std::vector<std::thread> thread_pool_;
    boost::asio::io_service io_service_;
    boost::asio::ip::tcp::acceptor acceptor_;
};

