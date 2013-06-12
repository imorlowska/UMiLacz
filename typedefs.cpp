#include "typedefs.h"


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
string getAccessibilityString(accessability a)
{
	switch (a)
	{
		case private_:      return "-";
		case public_:       return "+";
		case default_:      return "";
		case protected_:    return "#";
		case none_:         return "";
		default:			return "@";
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


accessability getBySymbol(char c)
{
	switch (c)
	{
	case '+':
		return accessability::public_;
	case '-':
		return accessability::private_;
	case '#':
		return accessability::protected_;
	default:
		return accessability::none_;
	}
}
