#include "VectorStockCodeShIdx.h"
#if 0
990009	��֤380		000009
990132	��֤100		000132
990133	��֤150		000133
990851	�ٷ�100		000851
990852	��֤1000	000852
990903	��֤100		000903
990904	��֤200		000904
990905	��֤500		000905
990906	��֤800		000906
990907	��֤700		000907
999987	��֤50		000016
999991	��֤180		000010
999997	B��ָ��		000003
999998	A��ָ��		000002
999999	��ָ֤��	000001
000300	����300		000300
#endif
bool VectorStockCodeShIdx::code_filter(const char *stockCode) {
	if (stockCode[8] == 'S') {
		string strCode = stockCode;
		strCode = strCode.substr(0, 6);
		int code = stoi(strCode);
		switch (code) {
			case 9:
			case 132:
			case 133:
			case 851:
			case 852:
			case 903:
			case 904:
			case 905:
			case 906:
			case 907:
			case 16:
			case 10:
			case 3:
			case 2:
			case 1:
			case 300:
				return true;
		}
	}
	return false;
}
