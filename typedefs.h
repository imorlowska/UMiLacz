#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include "includes.h"

enum accessability {private_, public_, default_, protected_, none_};
enum connectionType {extends_, implements_, contains_, other_};
enum connectionNumber { one2one, one2many, one2zeroplus,
                        many2one, many2many, many2zeroplus,
                        zeroplus2one, zeroplus2many, zeroplus2zeroplus};
enum specialType {normal_, abstract_, interface_, const_, static_};
enum typeKinds {simple_, unary_, binary_, internal_};
enum simpleType {int_, string_, double_, float_,bool_};
enum complexTypeUnary {list_, set_, multiset_};
enum complexTypeBinary {map_, multimap_, hashmap_, multihashmap_, pair_};

string getStringT(accessability a)
{
    switch (a)
    {
        case private_:      return "private ";
                            break;
        case public_:       return "public ";
                            break;
        case default_:      return "default ";
                            break;
        case protected_:    return "protected ";
                            break;
        case none_:         return "";
                            break;
        default:            return "Accessability error!";
                            break;
    }
}
string getStringT(simpleType s)
{
    switch (s)
    {
        case int_:          return "int";
                            break;
        case string_:       return "string";
                            break;
        case double_:       return "double";
                            break;
        case float_:        return "float";
                            break;
        case bool_:         return "bool";
                            break;
        default:            return "Type error!";
                            break;
    }
}
string getStringT(complexTypeUnary c)
{
    switch (c)
    {
        case list_:         return "list";
                            break;
        case set_:          return "set";
                            break;
        case multiset_:     return "multiset";
                            break;
        default:            return "Type error!";
                            break;
    }
}
string getStringT(complexTypeBinary c)
{
    switch (c)
    {
        case map_:          return "map";
                            break;
        case hashmap_:      return "hashmap";
                            break;
        case multimap_:     return "multimap";
                            break;
        case multihashmap_: return "multihashmap";
                            break;
        case pair_:         return "pair";
                            break;
        default:            return "Type error!";
                            break;
    }
}
string getStringT(specialType s)
{
    switch (s)
    {
        case normal_:       return "";
                            break;
        case abstract_:     return "abstract ";
                            break;
        case interface_:    return "interface ";
                            break;
        case const_:        return "const ";
                            break;
        case static_:       return "static ";
                            break;
        default:            return "Type error!";
                            break;
    }
}
#endif
