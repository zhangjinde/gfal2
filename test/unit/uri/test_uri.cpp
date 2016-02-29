#include <utils/uri/gfal_uri.h>
#include <gtest/gtest.h>


TEST(gfalURI, regular_parsing)
{
    GError* tmp_err=NULL;
    gfal2_uri parsed;
    int ret;

    ret = gfal2_parse_uri(
            "gsiftp://dcache-door-desy09.desy.de:2811/pnfs/desy.de/dteam/gfal2-tests/testread0011",
            &parsed,
            &tmp_err);

    ASSERT_EQ(0, ret);

    ASSERT_STREQ("gsiftp", parsed.scheme);
    ASSERT_STREQ("dcache-door-desy09.desy.de", parsed.domain);
    ASSERT_EQ(2811, parsed.port);
    ASSERT_STREQ("/pnfs/desy.de/dteam/gfal2-tests/testread0011", parsed.path);
    ASSERT_EQ('\0', parsed.query[0]);
}


TEST(gfalURI, malformed)
{
    GError* tmp_err=NULL;
    gfal2_uri parsed;
    int ret;

    ret = gfal2_parse_uri(
            "malformed",
            &parsed,
            &tmp_err);

    ASSERT_EQ(-1, ret);
}


TEST(gfalURI, no_port)
{
    GError* tmp_err=NULL;
    gfal2_uri parsed;
    int ret;

    ret = gfal2_parse_uri(
            "https://some.domain.com/path",
            &parsed,
            &tmp_err);

    ASSERT_EQ(0, ret);

    ASSERT_STREQ("https", parsed.scheme);
    ASSERT_STREQ("some.domain.com", parsed.domain);
    ASSERT_EQ(0, parsed.port);
    ASSERT_STREQ("/path", parsed.path);
}


TEST(gfalURI, ipv4)
{
    GError* tmp_err=NULL;
    gfal2_uri parsed;
    int ret;

    ret = gfal2_parse_uri(
        "gsiftp://192.168.1.1:1234/path",
        &parsed,
        &tmp_err);

    ASSERT_EQ(0, ret);

    ASSERT_STREQ("gsiftp", parsed.scheme);
    ASSERT_STREQ("192.168.1.1", parsed.domain);
    ASSERT_EQ(1234, parsed.port);
    ASSERT_STREQ("/path", parsed.path);
}


TEST(gfalURI, ipv6)
{
    GError* tmp_err=NULL;
    gfal2_uri parsed;
    int ret;

    ret = gfal2_parse_uri(
        "gsiftp://[2001:1458:301:a8ae::100:24]:1234/path",
        &parsed,
        &tmp_err);

    ASSERT_EQ(0, ret);

    ASSERT_STREQ("gsiftp", parsed.scheme);
    ASSERT_STREQ("[2001:1458:301:a8ae::100:24]", parsed.domain);
    ASSERT_EQ(1234, parsed.port);
    ASSERT_STREQ("/path", parsed.path);
}
