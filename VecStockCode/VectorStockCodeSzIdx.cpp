#include "VectorStockCodeSzIdx.h"
#if 0
399001	��֤��ָ
399002	���ָR
399003	�ɷ�Bָ
399005	��С��ָ
399006	��ҵ��ָ
399300	����300
#endif
bool VectorStockCodeSzIdx::code_filter(const char *stockCode) {
	if (stockCode[8] == 'Z') {
		string strCode = stockCode;
		strCode = strCode.substr(0, 6);
		int code = stoi(strCode);
		switch (code) {
		case 399001:
		case 399002:
		case 399003:
		case 399005:
		case 399006:
		case 399300:
			return true;
		}
	}
	return false;
}
