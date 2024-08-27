
template <typename T>
class Optional 
{
    private:
        bool hasValue = false;
        T value;
    
    public:
        Optional() = default;
    
        Optional(const T& suppliedValue): hasValue(true), value(suppliedValue)
        {
        }

        
        Optional(const Optional &optionalValue) = default;
        Optional(Optional&& other) noexcept = default;
        Optional& operator=(const Optional& other) = default;
        Optional& operator=(Optional&& other) noexcept = default;
        
        T get() const
        {
            if (hasValue)
            {
                return value;
            }
            throw std::logic_error("Attempted to access an empty Optional.");
        }

        bool has_value() const
        {
            return hasValue;
        }
    
        explicit operator bool() const
        {
            return hasValue;
        }
};
