#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#pragma once
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

string getStringT(accessability a);
string getStringT(simpleType s);
string getStringT(complexTypeUnary c);
string getStringT(complexTypeBinary c);
string getStringT(specialType s);

#endif
