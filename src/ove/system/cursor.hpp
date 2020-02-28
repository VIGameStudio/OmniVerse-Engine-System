#pragma once

#include <ove/core/util/types.hpp>

namespace ove
{
	namespace system
	{
		constexpr core::u8 WIN_CURSOR = 0x01;

		constexpr core::u8 WIN_CURSOR_NORMAL = 0x01;
		constexpr core::u8 WIN_CURSOR_HIDDEN = 0x02;
		constexpr core::u8 WIN_CURSOR_DISABLED = 0x03;

		constexpr core::u8 WIN_ARROW_CURSOR = 0x01;
		constexpr core::u8 WIN_IBEAM_CURSOR = 0x02;
		constexpr core::u8 WIN_VRESIZE_CURSOR = 0x03;
		constexpr core::u8 WIN_HRESIZE_CURSOR = 0x04;
		constexpr core::u8 WIN_HAND_CURSOR = 0x05;
		constexpr core::u8 WIN_RESIZE_ALL_CURSOR = 0x06;
		constexpr core::u8 WIN_RESIZE_NESW_CURSOR = 0x07;
		constexpr core::u8 WIN_RESIZE_NWSE_CURSOR = 0x08;
		constexpr core::u8 WIN_NOT_ALLOWED_CURSOR = 0x09;

		struct cursor_t
		{
		};
	}
}