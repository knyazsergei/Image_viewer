// stdafx.h: ���������� ���� ��� ����������� ��������� ���������� ������
// ��� ���������� ������ ��� ����������� �������, ������� ����� ������������, ��
// �� ����� ����������
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: ���������� ����� ������ �� �������������� ���������, ����������� ��� ���������
//tests dependencies
#define BOOST_TEST_INCLUDED
#pragma warning (disable: 4702)
#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string/replace.hpp>

//project dependencies
#include <atlbase.h>
#include <Gdiplus.h>