#include <string>

class Character {
public:
    Character(const std::string &name,
              const std::string &biography);

    const std::string &get_name() const;

    const std::string &get_biography() const;

    bool operator==(const Character &rhs) const;

    bool operator!=(const Character &rhs) const;

private:
    std::string name;
    std::string biography;
};