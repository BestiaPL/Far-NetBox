//------------------------------------------------------------------------------
// testnetbox_01.cpp
// Тесты для NetBox
// testnetbox_01 --run_test=testnetbox_01/test1 --log_level=all
//------------------------------------------------------------------------------

#include "stdafx.h"
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

#include "boostdefines.hpp"
#define BOOST_TEST_MODULE "testnetbox_01"
#define BOOST_TEST_MAIN
// #define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
// #include <boost/type_traits/is_base_of.hpp>

#include "TestTexts.h"
#include "Common.h"

using namespace boost::unit_test;

/*******************************************************************************
            test suite
*******************************************************************************/

class base_fixture_t
{
public:
    base_fixture_t()
    {
        // BOOST_TEST_MESSAGE("base_fixture_t ctor");
    }

    virtual ~base_fixture_t()
    {
    }
public:
protected:
};

//------------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(testnetbox_01)

BOOST_FIXTURE_TEST_CASE(test1, base_fixture_t)
{
    TList list;
    BOOST_CHECK_EQUAL(0, list.GetCount());
    TObject obj1;
    TObject obj2;
    if (1)
    {
        list.Add(&obj1);
        BOOST_CHECK_EQUAL(1, list.GetCount());
        list.Add(&obj2);
        BOOST_CHECK_EQUAL(2, list.GetCount());
        BOOST_CHECK_EQUAL(0, list.IndexOf(&obj1));
        BOOST_CHECK_EQUAL(1, list.IndexOf(&obj2));
    }
    list.Clear();
    if (1)
    {
        BOOST_CHECK_EQUAL(0, list.GetCount());
        list.Insert(0, &obj1);
        BOOST_CHECK_EQUAL(1, list.GetCount());
        list.Insert(0, &obj2);
        BOOST_CHECK_EQUAL(2, list.GetCount());
        BOOST_CHECK_EQUAL(1, list.IndexOf(&obj1));
        BOOST_CHECK_EQUAL(0, list.IndexOf(&obj2));
    }
    if (1)
    {
        list.Delete(1);
        BOOST_CHECK_EQUAL(1, list.GetCount());
        BOOST_CHECK_EQUAL(-1, list.IndexOf(&obj1));
        BOOST_CHECK_EQUAL(0, list.IndexOf(&obj2));
        BOOST_CHECK_EQUAL(1, list.Add(&obj1));
        list.Delete(0);
        BOOST_CHECK_EQUAL(0, list.IndexOf(&obj1));
        BOOST_CHECK_EQUAL(0, list.Remove(&obj1));
        BOOST_CHECK_EQUAL(-1, list.IndexOf(&obj1));
        BOOST_CHECK_EQUAL(0, list.GetCount());
    }
    if (1)
    {
        list.Add(&obj1);
        list.Add(&obj2);
        list.Extract(&obj1);
        BOOST_CHECK_EQUAL(1, list.GetCount());
        BOOST_CHECK_EQUAL(0, list.IndexOf(&obj2));
        list.Add(&obj1);
        BOOST_CHECK_EQUAL(2, list.GetCount());
        list.Move(0, 1);
        BOOST_CHECK_EQUAL(0, list.IndexOf(&obj1));
        BOOST_CHECK_EQUAL(1, list.IndexOf(&obj2));
    }
}

BOOST_FIXTURE_TEST_CASE(test2, base_fixture_t)
{
    std::wstring str;
    if (1)
    {
        TStringList strings;
        BOOST_CHECK_EQUAL(0, strings.GetCount());
        BOOST_CHECK_EQUAL(0, strings.Add(L"line 1"));
        BOOST_CHECK_EQUAL(1, strings.GetCount());
        str = strings.GetString(0);
        // DEBUG_PRINTF(L"str = %s", str.c_str());
        BOOST_CHECK_EQUAL(::W2MB(str.c_str()), "line 1");
        strings.PutString(0, L"line 0");
        BOOST_CHECK_EQUAL(1, strings.GetCount());
        str = strings.GetString(0);
        BOOST_CHECK_EQUAL(::W2MB(str.c_str()), "line 0");
        strings.PutString(0, L"line 00");
        BOOST_CHECK_EQUAL(1, strings.GetCount());
        BOOST_CHECK_EQUAL(::W2MB(strings.GetString(0).c_str()), "line 00");
        strings.Add(L"line 11");
        BOOST_CHECK_EQUAL(2, strings.GetCount());
        BOOST_CHECK_EQUAL(::W2MB(strings.GetString(1).c_str()), "line 11");
        strings.Delete(1);
        BOOST_CHECK_EQUAL(1, strings.GetCount());
    }
    TStringList strings;
    if (1)
    {
        BOOST_CHECK_EQUAL(0, strings.GetCount());
        strings.Add(L"line 1");
        str = strings.GetText();
        // DEBUG_PRINTF(L"str = %s", str.c_str());
        BOOST_CHECK_EQUAL(::W2MB(str.c_str()).c_str(), "line 1\n");
    }
    if (1)
    {
        strings.Add(L"line 2");
        BOOST_CHECK_EQUAL(2, strings.GetCount());
        str = strings.GetText();
        // DEBUG_PRINTF(L"str = %s", str.c_str());
        BOOST_CHECK_EQUAL(::W2MB(str.c_str()).c_str(), "line 1\nline 2\n");
        strings.Insert(0, L"line 0");
        BOOST_CHECK_EQUAL(3, strings.GetCount());
        str = strings.GetText();
        BOOST_CHECK_EQUAL(::W2MB(str.c_str()).c_str(), "line 0\nline 1\nline 2\n");
        strings.PutObject(0, NULL);
        std::wstring str = strings.GetString(0);
        BOOST_CHECK_EQUAL(::W2MB(str.c_str()), "line 0");
    }
}

BOOST_FIXTURE_TEST_CASE(test3, base_fixture_t)
{
    std::wstring Text = L"text text text text text1\ntext text text text text2\n";
    TStringList Lines;
    Lines.SetText(Text);
    BOOST_CHECK_EQUAL(2, Lines.GetCount());
    BOOST_TEST_MESSAGE("Lines 0 = " << ::W2MB(Lines.GetString(0).c_str()));
    BOOST_TEST_MESSAGE("Lines 1 = " << ::W2MB(Lines.GetString(1).c_str()));
    BOOST_CHECK_EQUAL("text text text text text1", ::W2MB(Lines.GetString(0).c_str()).c_str());
    BOOST_CHECK_EQUAL("text text text text text2", ::W2MB(Lines.GetString(1).c_str()).c_str());
}

BOOST_FIXTURE_TEST_CASE(test4, base_fixture_t)
{
    std::wstring Text = L"text, text text, text text1\ntext text text, text text2\n";
    TStringList Lines;
    Lines.SetCommaText(Text);
    BOOST_CHECK_EQUAL(6, Lines.GetCount());
    BOOST_CHECK_EQUAL("text", ::W2MB(Lines.GetString(0).c_str()).c_str());
    BOOST_CHECK_EQUAL(" text text", ::W2MB(Lines.GetString(1).c_str()).c_str());
    BOOST_CHECK_EQUAL(" text text1", ::W2MB(Lines.GetString(2).c_str()).c_str());
    BOOST_CHECK_EQUAL("text text text", ::W2MB(Lines.GetString(3).c_str()).c_str());
    BOOST_CHECK_EQUAL(" text text2", ::W2MB(Lines.GetString(4).c_str()).c_str());
    std::wstring Text2 = Lines.GetCommaText();
    BOOST_TEST_MESSAGE("Text2 = " << ::W2MB(Text2.c_str()));
    BOOST_CHECK_EQUAL("\"text\",\" text text\",\" text text1\",\"text text text\",\" text text2\",\"\"", ::W2MB(Text2.c_str()).c_str());
}

BOOST_AUTO_TEST_SUITE_END()
