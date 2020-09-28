#include <string>

class Character {
public:
    Character(const std::string &name,
              const std::string &biography);

    const std::string &GetName() const;

    const std::string &GetBiography() const;

    bool operator==(const Character &rhs) const;

    bool operator!=(const Character &rhs) const;

private:
    std::string name_;
    std::string biography_;
};