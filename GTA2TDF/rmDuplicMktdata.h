#pragma once
#include <map>
#include <memory>
#include <cstring>
using namespace std;

struct TDF_MARKET_DATA;

class RmDuplicMarketdata {
public:
	//true �۲⵽�ظ���MARKET_DATA
	bool rmDuplic(shared_ptr<TDF_MARKET_DATA> m);
protected:
	map<string, shared_ptr<TDF_MARKET_DATA> > m_map;
};
