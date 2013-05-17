#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include "includes.h"

enum accessability {private_, public_, default_, protected_};
enum connectionType {extends_, implements_, contains_, other_};
enum connectionNumber { one2one, one2many, one2zeroplus,
                        many2one, many2many, many2zeroplus,
                        zeroplus2one, zeroplus2many, zeroplus2zeroplus};
enum specialType {normal_, abstract_, interface_, const_, static_};
enum typeKinds {simple_, unary_, binary_};
enum simpleType {int_, string_, double_, float_};
enum complexTypeUnary {list_, set_, multiset_};
enum complexTypeBinary {map_, multimap_, hashmap_, multihashmap, pair_};

string getString(accessability a)
{
    switch (a)
    {
        case private_:      return "private";
                            break;
        case public_:       return "public";
                            break;
        case default_:      return "default";
                            break;
        case protected_:    return "protected";
                            break;
        default:            return "Accessability error!";
                            break;
    }

}

#endif
