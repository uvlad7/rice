namespace Rice
{
  inline Symbol::Symbol(VALUE value) : Object(value)
  {
    detail::protect(rb_check_type, value, (int)T_SYMBOL);
  }

  inline Symbol::Symbol(Object value) : Object(value)
  {
    detail::protect(rb_check_type, value.value(), (int)T_SYMBOL);
  }

  inline Symbol::Symbol(char const* s)
    : Object(ID2SYM(rb_intern(s)))
  {
  }

  inline Symbol::Symbol(std::string const& s)
    : Object(ID2SYM(rb_intern(s.c_str())))
  {
  }

  inline Symbol::Symbol(Identifier id) : Object(ID2SYM(id))
  {
  }

  inline char const* Symbol::c_str() const
  {
    return to_id().c_str();
  }

  inline std::string Symbol::str() const
  {
    return to_id().str();
  }

  inline Identifier Symbol::to_id() const
  {
    return rb_to_id(value());
  }
}

namespace Rice::detail
{
  template<>
  struct Type<Symbol>
  {
    static bool verify()
    {
      return true;
    }
  };
  
  template<>
  struct To_Ruby<Symbol>
  {
    VALUE convert(Object const& x)
    {
      return x.value();
    }
  };

  template<>
  class From_Ruby<Symbol>
  {
  public:
    Object convert(VALUE value)
    {
      return Object(value);
    }
  };
}