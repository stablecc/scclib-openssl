/*
BSD 3-Clause License

Copyright (c) 2022, Stable Cloud Computing, Inc.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include <gtest/gtest.h>
#include <iostream>
#include <openssl/crypto.h>
#include <openssl/err.h>
#include <openssl/rand.h>

using std::cout;
using std::endl;

TEST(Openssl_test, openssl_version)
{
	const char* s;
	s = OpenSSL_version(OPENSSL_VERSION);
	ASSERT_NE(s, nullptr);
	cout << "Openssl version: " << s << endl;
	s = OpenSSL_version(OPENSSL_BUILT_ON);
	ASSERT_NE(s, nullptr);
	cout << "Openssl built on: " << s << endl;
	s = OpenSSL_version(OPENSSL_PLATFORM);
	ASSERT_NE(s, nullptr);
	cout << "Openssl platform: " << s << endl;
	s = OpenSSL_version(OPENSSL_CFLAGS);
	ASSERT_NE(s, nullptr);
	cout << "Openssl cflags: " << s << endl;
}

TEST(Openssl_test, openssl_errortest)
{
	const char* s = ERR_error_string(0, nullptr);
	ASSERT_NE(s, nullptr);
	cout << "Openssl error string (0): " << s << endl;
}

TEST(Openssl_test, openssl_thread)
{
	// support for thread locking added in 1.1.x
	CRYPTO_RWLOCK* l;
	l = CRYPTO_THREAD_lock_new();
	ASSERT_NE(l, nullptr);
	CRYPTO_THREAD_lock_free(l);
}

TEST(Openssl_test, random_bytes)
{
	cout << "Rand bytes: ";
	for (int i = 0; i < 128; i++)
	{
		unsigned char b[4];
		ASSERT_NE(RAND_bytes(b, 4), 0);
		cout << "[" << (int)b[0] << " " << (int)b[1] << " " << (int)b[2] << " " << (int)b[3] << "] ";
	}
	for (int i = 0; i < 32; i++)
	{
		unsigned int w;
		ASSERT_NE(RAND_bytes(reinterpret_cast<unsigned char*>(&w), sizeof(unsigned int)), 0);
		cout << "[" << w << "] ";
	}
	cout << endl;
}
