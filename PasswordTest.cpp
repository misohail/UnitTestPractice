/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, empty_string)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, no_repeat)
{
	Password my_password;
	int actual = my_password.count_leading_characters("abc");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, repeats_at_start)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaaaXYZ");
	ASSERT_EQ(4, actual);
}

TEST(PasswordTest, case_sensitive_repeat)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaA");
	ASSERT_EQ(1, actual);
}