#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <stdexcept>
class DeckFileException: public std::logic_error
{
public:
    virtual ~DeckFileException() {}
    DeckFileException(const std::string& what) :std::logic_error(what)
{}
};

class DeckFileNotFound: public DeckFileException
{
 private:
   
    public:

    DeckFileNotFound():DeckFileException("Deck File Error: File not found"){}
};
class DeckFileFormatError: public DeckFileException
{
    public:
    DeckFileFormatError(int badLine):DeckFileException("Deck File Error: File format error in line " + std::to_string(badLine))
    {}
};

class DeckFileInvalidSize: public DeckFileException
{
    public:

    DeckFileInvalidSize():DeckFileException("Deck File Error: Deck size is invalid"){}
};
#endif

