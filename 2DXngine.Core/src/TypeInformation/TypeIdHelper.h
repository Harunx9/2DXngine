template<typename Type>
struct TypeIdInfo
{
    static TypeInfo getType()
    {
        return TypeInfo();
    }
};

template <typename T>
struct RegisterType;

template<typename T>
inline TypeInfo TypeInfo::get()
{
    return TypeIdInfo<T>::getType();
}

template<typename T>
inline TypeInfo TypeInfo::get(T *)
{
    return TypeIdInfo<T*>::getType();
}

template<typename T>
static TypeInfo getTypeInfoFromInstance(const T*)
{
    return TypeIdInfo<T>::getType();
}

TypeInfo getOrRegisterTypeInChache(const char* name, const char* parentTypeName);
#define CAT_IMPL(a, b) a##b
#define CAT(a, b) CAT_IMPL(a, b)
//in .h files
#define DECLARE_TYPE_INFO(Type, BaseType)                                            \
                                                                                     \
template<>                                                                           \
struct TypeIdInfo<Type>                                                              \
{                                                                                    \
    static TypeInfo getType()                                                        \
    {                                                                                \
        static const TypeInfo typeInfo = getOrRegisterTypeInChache(#Type, #BaseType);\
        return typeInfo;                                                             \
    }                                                                                \
};                                                                                   \

#define DECLARE_TYPE_INFO_VARIANTS(Type, BaseType) DECLARE_TYPE_INFO(Type, BaseType)\
                                           DECLARE_TYPE_INFO(Type*, BaseType)\
                                           DECLARE_TYPE_INFO(const Type*, BaseType)

//in .cpp files
#define DEFINE_TYPE_INFO(Type)      \
                                    \
template<>                          \
struct RegisterType<Type>           \
{                                   \
    RegisterType()                  \
    {                               \
       TypeIdInfo<Type>::getType(); \
    }                               \
};                                  \
static const RegisterType<Type> CAT(registerType, __COUNTER__);

#define DEFINE_TYPE_INFO_VARIANTS(Type) DEFINE_TYPE_INFO(Type)\
                                        DEFINE_TYPE_INFO(Type*)\
                                        DEFINE_TYPE_INFO(const Type*)
