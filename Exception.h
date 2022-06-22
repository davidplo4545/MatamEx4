#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>
class DeckFileException: public std::logic_error
{
public:
    virtual ~DeckFileException() {}
    explicit DeckFileException(const std::string& what) :std::logic_error(what)
{}
};

class DeckFileNotFound: public DeckFileException
{
public:
    explicit DeckFileNotFound():DeckFileException("Deck File Error: File not found"){}
};
class DeckFileFormatError: public DeckFileException
{
public:
    explicit DeckFileFormatError(int badLine):DeckFileException("Deck File Error: File format error in line " + std::to_string(badLine))
    {}
};

class DeckFileInvalidSize: public DeckFileException
{
public:
    explicit DeckFileInvalidSize():DeckFileException("Deck File Error: Deck size is invalid"){}
};
#endif

