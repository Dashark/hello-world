/**
 * @file Units.cpp
 * @brief 单位转换程序
 *     - 单位转换程序，输入值和原单位，新单位，返回新单位下的值。
 *     - 重量单位：Kg, g, lb, gr,......
 *     - 压力单位：Pa, MPa, psi,......
 *     - 长度单位：m, km, ft, in,......
 *     - 其它单位：md, cp,......
 *     - 还有很多单位转换，有些单位是其它单位组合出来的
 *     - 没有用到windows API
 *     - 直接打开网页
 * @author LonDec/贺翔
 * @date   2018-06-17
 */

		#include <windows.h>
		#include <tchar.h>
		#include <assert.h>

		const TCHAR szOperation[] = _T("open");
		const TCHAR szAddress[]   = _T("https://www.convertworld.com/zh-hans/");
		int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR lpCmd, int nShow) {

			HINSTANCE hRslt = ShellExecute(NULL, szOperation, szAddress, NULL, NULL, SW_SHOWNORMAL);

			assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);

			return 0;
		}
