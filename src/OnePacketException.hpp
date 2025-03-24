#ifndef ONEPACKETEXCEPTION_HPP
#define ONEPACKETEXCEPTION_HPP

#include <exception>
#include <string>
#include <utility>

class OnePacketException : public std::exception {
public:
    virtual int errorCode() const { return -1; };
};

class CRCException final : public OnePacketException {
    std::string message;

public:
    explicit CRCException(std::string msg) : message(std::move(msg)) {
    }

    int errorCode() const override { return -2; }

    const char *what() const noexcept override {
        return ("Failed to pass CRC check:" + message).c_str();
    }
};

class BufferRangeOverflow final : public OnePacketException {
    std::string message;

public:
    explicit BufferRangeOverflow(std::string msg) : message(std::move(msg)) {
    }

    int errorCode() const override { return -3; }

    const char *what() const noexcept override {
        return ("The buffer passed in has exceeded preset length: " + message).c_str();
    }
};


#endif //ONEPACKETEXCEPTION_HPP
