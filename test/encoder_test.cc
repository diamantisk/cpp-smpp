/*
 * Copyright (C) 2014 OnlineCity
 * Licensed under the MIT license, which can be read at: http://www.opensource.org/licenses/mit-license.php
 */

#include <glog/logging.h>
#include <gflags/gflags.h>
#include <string>
#include "gtest/gtest.h"
#include "smpp/gsmencoding.h"

TEST(GsmEncoder, EncodeDecode) {
  std::string i1(
    "Ja r i høje @£$¥èéùìòÇØøÅåΔ_ΦΓΛΩΠΨΣΘΞÆæßÉÄÖÑÜ§¿äöñüà^{}\\[~]| "
    "Lorem ipsum, Lorem ipsum, Lorem ipsum, Lorem ipsum, Lorem ipsum, Lorem ipsum, ");
  std::string o1 = oc::tools::GsmEncoder::EncodeGsm0338(i1);
  std::string o3 = oc::tools::GsmEncoder::EncodeUtf8(o1);
  ASSERT_EQ(i1, o3);
}