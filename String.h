

#ifndef STRING_H
#define STRING_H



class String
{
public:
    // Initializes a string to be empty (i.e., its length will
    // be zero and toChars() will return "").
    String() noexcept(false);
    
    // Initializes a string to contain the characters in the
    // given C-style string, which is assumed to be null-terminated.
    String(const char* chars) noexcept(false);
    
    // Initializes a string to be a copy of an existing string,
    // meaning that it contains the same characters and has the
    // same length.
    String(const String& s) noexcept(false);
    
    // Destroys a string, releasing any memory that is being
    // managed by this object.
    ~String() noexcept;
    
    // Assigns an existing string into this one, replacing the
    // contents of this string with a copy of the contents of
    // the other.
    String& operator=(const String& s) noexcept(false);
    
    // append() modifies this string so that it contains all
    // of the characters it currently contains, followed by
    // all of the characters of s.
    void append(const String& s);
    
    // at() returns one of the characters in the string, given
    // a zero-based index (i.e., the index 0 is the first
    // character of the string).  There are two variants of
    // this member function, so that it is possible to use
    // this to modify a string's characters, but only if
    // the string is not constant.
    //
    // If the given index is not the index of a character
    // within the string (e.g., if a string's length is
    // five, valid indices range from 0..4 inclusive),
    // this member function throws an OutOfBoundsException.
    char at(unsigned int index) const;
    char& at(unsigned int index);
    
    // clear() makes this string be empty.
    void clear();
    
    // compareTo() compares the contents of this string to the
    // contents of another string lexicographically, returning
    // zero if they're exactly equal, a negative value if this
    // string is "less than" the other one lexicographically,
    // or a positive value if this string is "greater than"
    // the other one lexicographically.
    int compareTo(const String& s) const noexcept;
    
    // concatenate() returns a string that contains the
    // characters in this string followed by the characters
    // in s.
    String concatenate(const String& s) const;
    
    // contains() returns true if this string contains the
    // given substring somewhere (e.g., the string "Is Boo
    // happy today?" contains the substring "Boo"), or false
    // otherwise.
    bool contains(const String& substring) const noexcept;
    
    // equals() returns true if this string is equivalent to
    // the given string (i.e., they both have the same length
    // and contain the same sequence of characters).
    bool equals(const String& s) const noexcept;
    
    // find() returns the index where the given substring is
    // found within this string, or -1 if it's not found.
    int find(const String& substring) const noexcept;
    
    // isEmpty() returns true if this string is empty, or
    // false otherwise.
    bool isEmpty() const noexcept;
    
    // length() returns the number of characters in this string.
    unsigned int length() const noexcept;
    
    // substring() returns a substring of this substring,
    // containing the characters beginning at startIndex
    // and ending at (but not including) endIndex.  For
    // example, in the string "Boo is happy today",
    // substring(7, 12) would return "happy".
    String substring(unsigned int startIndex, unsigned int endIndex) const;
    
    // toChars() returns a C-style string that is equivalent
    // (i.e., has the same length and contains the same
    // sequence of characters) as this string.  Note that
    // the C-style string is not allocated by this member
    // function, so it is not necessary to deallocate it.
    const char* toChars() const noexcept;
private:
    char *letters;
    int len;
};



#endif

