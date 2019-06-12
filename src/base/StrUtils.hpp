#pragma once

#include <Classes.hpp>

NB_CORE_EXPORT UnicodeString ReplaceStr(UnicodeString Str, UnicodeString What, UnicodeString ByWhat);
NB_CORE_EXPORT bool StartsStr(UnicodeString SubStr, UnicodeString Str);
NB_CORE_EXPORT bool EndsStr(UnicodeString SubStr, UnicodeString Str);
NB_CORE_EXPORT bool EndsText(UnicodeString SubStr, UnicodeString Str);
NB_CORE_EXPORT UnicodeString LeftStr(UnicodeString AStr, intptr_t Len);

NB_CORE_EXPORT UnicodeString EncodeBase64(const char* AStr, intptr_t Len);
NB_CORE_EXPORT rde::vector<uint8_t> DecodeBase64(UnicodeString AStr);
