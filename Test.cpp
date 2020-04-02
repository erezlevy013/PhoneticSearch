/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Erez Levy
 * 
 * Date: 2020-02
 */

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;



TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
}


TEST_CASE("w and v, u and o, y and i, z and s ") {
    string text = "vhu yz iuor heru";
    CHECK(find(text, "who") == string("vhu"));
    CHECK(find(text, "is") == string("yz"));
    CHECK(find(text, "your") == string("iuor"));
    CHECK(find(text, "hero") == string("heru"));
}



TEST_CASE("w and v, u and o, y and i, z and s ") {
    string text = "Do you like or dislike";
    CHECK(find(text, "do") == string("Do"));
    CHECK(find(text, "Du") == string("Do"));
    CHECK(find(text, "iuo") == string("you"));
    CHECK(find(text, "iuu") == string("you"));
    CHECK(find(text, "lyqe") == string("like"));
    CHECK(find(text, "lyce") == string("like"));
    CHECK(find(text, "liqe") == string("like"));
    CHECK(find(text, "ur") == string("or"));
    CHECK(find(text, "tyzlyce") == string("dislike"));
    CHECK(find(text, "dyzlyce") == string("dislike"));
    CHECK(find(text, "dizlike") == string("dislike"));
    CHECK(find(text, "dizlice") == string("dislike"));
    CHECK(find(text, "dizlyke") == string("dislike"));
    CHECK(find(text, "dyzlyke") == string("dislike"));
    CHECK(find(text, "disLIKE") == string("dislike"));



}


TEST_CASE("w and v, u and o, y and i, z and s.... ") {
    string text = "xxx surprises yyyy";
    CHECK(find(text, "zorbryzez") == string("surprises"));
    CHECK(find(text, "zurfryzez") == string("surprises"));
    CHECK(find(text, "zurpryzez") == string("surprises"));
    CHECK(find(text, "sorbrizes") == string("surprises"));
    CHECK(find(text, "zorbryZeZ") == string("surprises"));
    CHECK(find(text, "zOrbRyzez") == string("surprises"));
    CHECK(find(text, "sorBrizEs") == string("surprises"));
    CHECK(find(text, "SOrbRizes") == string("surprises"));
}


TEST_CASE("c and k and q, u and o, z and s ") {
    string text = "xxx knows yyyy";
    CHECK(find(text, "knuws") == string("knows"));
    CHECK(find(text, "knovs") == string("knows"));
    CHECK(find(text, "knuvz") == string("knows"));
    CHECK(find(text, "cnuws") == string("knows"));
    CHECK(find(text, "cnovs") == string("knows"));
    CHECK(find(text, "cnuvz") == string("knows"));
    CHECK(find(text, "qnuws") == string("knows"));
    CHECK(find(text, "qnovs") == string("knows"));
    CHECK(find(text, "qnuvz") == string("knows"));
}

TEST_CASE("w and v, u and o, y and i, z and s.... ") {
    string text = "xxx yyy would";
    CHECK(find(text, "wuolt") == string("would"));
    CHECK(find(text, "woolt") == string("would"));
    CHECK(find(text, "voult") == string("would"));
    CHECK(find(text, "wuuld") == string("would"));
    CHECK(find(text, "vuult") == string("would"));
    CHECK(find(text, "voold") == string("would"));
    CHECK(find(text, "wuulT") == string("would"));
    CHECK(find(text, "WuUld") == string("would"));
}

TEST_CASE("w and v, u and o, y and i, z and s.... ") {
    string text = "xxx deserted yyyy";
    CHECK(find(text, "dezerded") == string("deserted"));
    CHECK(find(text, "tesertet") == string("deserted"));
    CHECK(find(text, "teserted") == string("deserted"));
    CHECK(find(text, "dezerdet") == string("deserted"));
    CHECK(find(text, "dezerdet") == string("deserted"));
    CHECK(find(text, "tezertet") == string("deserted"));
    CHECK(find(text, "tezerded") == string("deserted"));
    CHECK(find(text, "deserteT") == string("deserted"));
}

TEST_CASE("w and v, u and o, y and i, z and s.... ") {
    string text = "xxx without yyyy";
    CHECK(find(text, "withoud") == string("without"));
    CHECK(find(text, "withoud") == string("without"));
    CHECK(find(text, "vythuod") == string("without"));
    CHECK(find(text, "wythout") == string("without"));
    CHECK(find(text, "wydhoud") == string("without"));
    CHECK(find(text, "wydhuot") == string("without"));
    CHECK(find(text, "vidhout") == string("without"));
    CHECK(find(text, "vidhuod") == string("without"));
}


TEST_CASE("w and v, u and o, y and i, z and s.... ") {
    string text = "xxx pillows yyyy";
    CHECK(find(text, "pillowz") == string("pillows"));
    CHECK(find(text, "pillovs") == string("pillows"));
    CHECK(find(text, "pillovz") == string("pillows"));
    CHECK(find(text, "billowz") == string("pillows"));
    CHECK(find(text, "billovs") == string("pillows"));
    CHECK(find(text, "billovz") == string("pillows"));
    CHECK(find(text, "fillowz") == string("pillows"));
    CHECK(find(text, "fillovs") == string("pillows"));
    CHECK(find(text, "fillovz") == string("pillows"));
}


TEST_CASE("w and v, u and o, y and i, z and s.... ") {
    string text = "xxx building yyyy";
    CHECK(find(text, "builting") == string("building"));
    CHECK(find(text, "boilting") == string("building"));
    CHECK(find(text, "boilding") == string("building"));
    CHECK(find(text, "foilting") == string("building"));
    CHECK(find(text, "foilting") == string("building"));
    CHECK(find(text, "foilding") == string("building"));
    CHECK(find(text, "puilting") == string("building"));
    CHECK(find(text, "poilting") == string("building"));
    CHECK(find(text, "poilding") == string("building"));
}

TEST_CASE("w and v, u and o, y and i, z and s....") {
    string text = "hello butterfly how here you";
    CHECK(find(text, "butterfly") == string("butterfly"));
    CHECK(find(text, "bodterpli") == string("butterfly"));
    CHECK(find(text, "botterply") == string("butterfly"));
    CHECK(find(text, "botderply") == string("butterfly"));
    CHECK(find(text, "botterbly") == string("butterfly"));
    CHECK(find(text, "bodterbly") == string("butterfly"));
}

TEST_CASE("w and v, u and o, y and i, z and s....") {
    string text = "hello intervention is start";
    CHECK(find(text, "intervention") == string("intervention"));
    CHECK(find(text, "indervendion") == string("intervention"));
    CHECK(find(text, "yntervendion") == string("intervention"));
    CHECK(find(text, "yndervendion") == string("intervention"));
}

TEST_CASE("w and v, u and o, y and i, z and s.... ") {
    string text = "xxx tallest yyyy";
    CHECK(find(text, "tallezd") == string("tallest"));
    CHECK(find(text, "tallezt") == string("tallest"));
    CHECK(find(text, "tallesd") == string("tallest"));
    CHECK(find(text, "tallezd") == string("tallest"));
    CHECK(find(text, "tallezt") == string("tallest"));
    CHECK(find(text, "tallesd") == string("tallest"));
}




