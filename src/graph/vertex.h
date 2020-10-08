template<typename T>
class Vertex {
public:
    Vertex(T data) : data(data) {}

    bool operator==(const Vertex &rhs) const {
        return data == rhs.data;
    }

    bool operator!=(const Vertex &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const Vertex &rhs) const {
        return data < rhs.data;
    }

    bool operator>(const Vertex &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Vertex &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Vertex &rhs) const {
        return !(*this < rhs);
    }

private:
    T data;
};
