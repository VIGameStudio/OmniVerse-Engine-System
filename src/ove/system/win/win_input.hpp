#pragma once

#include <ove/core/util/types.hpp>

#include <windows.h>

namespace ove
{
	namespace system
	{
		//constexpr core::u8 WIN_KB_KEYNONE = 0x00; // No key pressed

		//constexpr core::u8 WIN_KB_ERR_ROLLOVER = 0x01; // Keyboard Error Roll Over
		//constexpr core::u8 WIN_KB_POST_FAIL = 0x02; // Keyboard POST Fail
		//constexpr core::u8 WIN_KB_ERR_UNDEFINED = 0x03; // Keyboard Error Undefined

		constexpr core::u8 WIN_KB_A = 0x41; // Keyboard a and A
		constexpr core::u8 WIN_KB_B = 0x42; // Keyboard b and B
		constexpr core::u8 WIN_KB_C = 0x43; // Keyboard c and C
		constexpr core::u8 WIN_KB_D = 0x44; // Keyboard d and D
		constexpr core::u8 WIN_KB_E = 0x45; // Keyboard e and E
		constexpr core::u8 WIN_KB_F = 0x46; // Keyboard f and F
		constexpr core::u8 WIN_KB_G = 0x47; // Keyboard g and G
		constexpr core::u8 WIN_KB_H = 0x48; // Keyboard h and H
		constexpr core::u8 WIN_KB_I = 0x49; // Keyboard i and I
		constexpr core::u8 WIN_KB_J = 0x4a; // Keyboard j and J
		constexpr core::u8 WIN_KB_K = 0x4b; // Keyboard k and K
		constexpr core::u8 WIN_KB_L = 0x4c; // Keyboard l and L
		constexpr core::u8 WIN_KB_M = 0x4d; // Keyboard m and M
		constexpr core::u8 WIN_KB_N = 0x4e; // Keyboard n and N
		constexpr core::u8 WIN_KB_O = 0x4f; // Keyboard o and O
		constexpr core::u8 WIN_KB_P = 0x50; // Keyboard p and P
		constexpr core::u8 WIN_KB_Q = 0x51; // Keyboard q and Q
		constexpr core::u8 WIN_KB_R = 0x52; // Keyboard r and R
		constexpr core::u8 WIN_KB_S = 0x53; // Keyboard s and S
		constexpr core::u8 WIN_KB_T = 0x54; // Keyboard t and T
		constexpr core::u8 WIN_KB_U = 0x55; // Keyboard u and U
		constexpr core::u8 WIN_KB_V = 0x56; // Keyboard v and V
		constexpr core::u8 WIN_KB_W = 0x57; // Keyboard w and W
		constexpr core::u8 WIN_KB_X = 0x58; // Keyboard x and X
		constexpr core::u8 WIN_KB_Y = 0x59; // Keyboard y and Y
		constexpr core::u8 WIN_KB_Z = 0x5A; // Keyboard z and Z

		constexpr core::u8 WIN_KB_1 = 0x1e; // Keyboard 1 and !
		constexpr core::u8 WIN_KB_2 = 0x1f; // Keyboard 2 and @
		constexpr core::u8 WIN_KB_3 = 0x20; // Keyboard 3 and #
		constexpr core::u8 WIN_KB_4 = 0x21; // Keyboard 4 and $
		constexpr core::u8 WIN_KB_5 = 0x22; // Keyboard 5 and %
		constexpr core::u8 WIN_KB_6 = 0x23; // Keyboard 6 and ^
		constexpr core::u8 WIN_KB_7 = 0x24; // Keyboard 7 and &
		constexpr core::u8 WIN_KB_8 = 0x25; // Keyboard 8 and *
		constexpr core::u8 WIN_KB_9 = 0x26; // Keyboard 9 and (
		constexpr core::u8 WIN_KB_0 = 0x27; // Keyboard 0 and )

		constexpr core::u8 WIN_KB_ENTER = VK_RETURN; // Keyboard Return (ENTER)
		constexpr core::u8 WIN_KB_ESCAPE = VK_ESCAPE; // Keyboard ESCAPE
		constexpr core::u8 WIN_KB_BACKSPACE = VK_BACK; // Keyboard DELETE (Backspace)
		constexpr core::u8 WIN_KB_TAB = VK_TAB; // Keyboard Tab
		constexpr core::u8 WIN_KB_SPACE = VK_SPACE; // Keyboard Spacebar
		constexpr core::u8 WIN_KB_MINUS = VK_OEM_MINUS; // Keyboard - and _
		constexpr core::u8 WIN_KB_EQUAL = 0x00; // Keyboard = and +
		constexpr core::u8 WIN_KB_LEFTBRACE = VK_OEM_4; // Keyboard [ and {
		constexpr core::u8 WIN_KB_RRIGHTBRACE = VK_OEM_6; // Keyboard ] and }
		constexpr core::u8 WIN_KB_BACKSLASH = VK_OEM_5; // Keyboard \ and |
		constexpr core::u8 WIN_KB_HASHTILDE = 0x00; // Keyboard Non-US # and ~
		constexpr core::u8 WIN_KB_SEMICOLON = VK_OEM_1; // Keyboard ; and :
		constexpr core::u8 WIN_KB_APOSTROPHE = VK_OEM_7; // Keyboard ' and "
		constexpr core::u8 WIN_KB_GRAVE = VK_OEM_3; // Keyboard ` and ~
		constexpr core::u8 WIN_KB_COMMA = VK_OEM_COMMA; // Keyboard , and <
		constexpr core::u8 WIN_KB_DOT = VK_OEM_PERIOD; // Keyboard .and >
		constexpr core::u8 WIN_KB_SLASH = VK_OEM_2; // Keyboard / and ?
		constexpr core::u8 WIN_KB_CAPSLOCK = VK_CAPITAL; // Keyboard Caps Lock

		constexpr core::u8 WIN_KB_F1 = VK_F1; // Keyboard F1
		constexpr core::u8 WIN_KB_F2 = VK_F2; // Keyboard F2
		constexpr core::u8 WIN_KB_F3 = VK_F3; // Keyboard F3
		constexpr core::u8 WIN_KB_F4 = VK_F4; // Keyboard F4
		constexpr core::u8 WIN_KB_F5 = VK_F5; // Keyboard F5
		constexpr core::u8 WIN_KB_F6 = VK_F6; // Keyboard F6
		constexpr core::u8 WIN_KB_F7 = VK_F7; // Keyboard F7
		constexpr core::u8 WIN_KB_F8 = VK_F8; // Keyboard F8
		constexpr core::u8 WIN_KB_F9 = VK_F9; // Keyboard F9
		constexpr core::u8 WIN_KB_F10 = VK_F10; // Keyboard F10
		constexpr core::u8 WIN_KB_F11 = VK_F11; // Keyboard F11
		constexpr core::u8 WIN_KB_F12 = VK_F12; // Keyboard F12

		constexpr core::u8 WIN_KB_SYSRQ = VK_SNAPSHOT; // Keyboard Print Screen
		constexpr core::u8 WIN_KB_SCROLLLOCK = VK_SCROLL; // Keyboard Scroll Lock
		constexpr core::u8 WIN_KB_PAUSE = VK_PAUSE; // Keyboard Pause
		constexpr core::u8 WIN_KB_INSERT = VK_INSERT; // Keyboard Insert
		constexpr core::u8 WIN_KB_HOME = VK_HOME; // Keyboard Home
		constexpr core::u8 WIN_KB_PAGEUP = VK_PRIOR; // Keyboard Page Up
		constexpr core::u8 WIN_KB_DELETE = VK_DELETE; // Keyboard Delete Forward
		constexpr core::u8 WIN_KB_END = VK_END; // Keyboard End
		constexpr core::u8 WIN_KB_PAGEDOWN = VK_NEXT; // Keyboard Page Down

		constexpr core::u8 WIN_KB_RIGHT = VK_RIGHT; // Keyboard Right Arrow
		constexpr core::u8 WIN_KB_LEFT = VK_LEFT; // Keyboard Left Arrow
		constexpr core::u8 WIN_KB_DOWN = VK_DOWN; // Keyboard Down Arrow
		constexpr core::u8 WIN_KB_UP = VK_UP; // Keyboard Up Arrow

		/*constexpr core::u8 WIN_KB_NUMLOCK = 0x53; // Keyboard Num Lock and Clear
		constexpr core::u8 WIN_KB_KPSLASH = 0x54; // Keypad /
		constexpr core::u8 WIN_KB_KPASTERISK = 0x55; // Keypad *
		constexpr core::u8 WIN_KB_KPMINUS = 0x56; // Keypad -
		constexpr core::u8 WIN_KB_KPPLUS = 0x57; // Keypad +
		constexpr core::u8 WIN_KB_KPENTER = 0x58; // Keypad ENTER
		constexpr core::u8 WIN_KB_KP1 = 0x59; // Keypad 1 and End
		constexpr core::u8 WIN_KB_KP2 = 0x5a; // Keypad 2 and Down Arrow
		constexpr core::u8 WIN_KB_KP3 = 0x5b; // Keypad 3 and PageDn
		constexpr core::u8 WIN_KB_KP4 = 0x5c; // Keypad 4 and Left Arrow
		constexpr core::u8 WIN_KB_KP5 = 0x5d; // Keypad 5
		constexpr core::u8 WIN_KB_KP6 = 0x5e; // Keypad 6 and Right Arrow
		constexpr core::u8 WIN_KB_KP7 = 0x5f; // Keypad 7 and Home
		constexpr core::u8 WIN_KB_KP8 = 0x60; // Keypad 8 and Up Arrow
		constexpr core::u8 WIN_KB_KP9 = 0x61; // Keypad 9 and Page Up
		constexpr core::u8 WIN_KB_KP0 = 0x62; // Keypad 0 and Insert
		constexpr core::u8 WIN_KB_KPDOT = 0x63; // Keypad . and Delete

		constexpr core::u8 WIN_KB_102ND = 0x64; // Keyboard Non-US \ and |
		constexpr core::u8 WIN_KB_COMPOSE = 0x65; // Keyboard Application
		constexpr core::u8 WIN_KB_POWER = 0x66; // Keyboard Power
		constexpr core::u8 WIN_KB_KPEQUAL = 0x67; // Keypad =

		constexpr core::u8 WIN_KB_F13 = 0x68; // Keyboard F13
		constexpr core::u8 WIN_KB_F14 = 0x69; // Keyboard F14
		constexpr core::u8 WIN_KB_F15 = 0x6a; // Keyboard F15
		constexpr core::u8 WIN_KB_F16 = 0x6b; // Keyboard F16
		constexpr core::u8 WIN_KB_F17 = 0x6c; // Keyboard F17
		constexpr core::u8 WIN_KB_F18 = 0x6d; // Keyboard F18
		constexpr core::u8 WIN_KB_F19 = 0x6e; // Keyboard F19
		constexpr core::u8 WIN_KB_F20 = 0x6f; // Keyboard F20
		constexpr core::u8 WIN_KB_F21 = 0x70; // Keyboard F21
		constexpr core::u8 WIN_KB_F22 = 0x71; // Keyboard F22
		constexpr core::u8 WIN_KB_F23 = 0x72; // Keyboard F23
		constexpr core::u8 WIN_KB_F24 = 0x73; // Keyboard F24

		constexpr core::u8 WIN_KB_OPEN = 0x74; // Keyboard Execute
		constexpr core::u8 WIN_KB_HELP = 0x75; // Keyboard Help
		constexpr core::u8 WIN_KB_PROPS = 0x76; // Keyboard Menu
		constexpr core::u8 WIN_KB_FRONT = 0x77; // Keyboard Select
		constexpr core::u8 WIN_KB_STOP = 0x78; // Keyboard Stop
		constexpr core::u8 WIN_KB_AGAIN = 0x79; // Keyboard Again
		constexpr core::u8 WIN_KB_UNDO = 0x7a; // Keyboard Undo
		constexpr core::u8 WIN_KB_CUT = 0x7b; // Keyboard Cut
		constexpr core::u8 WIN_KB_COPY = 0x7c; // Keyboard Copy
		constexpr core::u8 WIN_KB_PASTE = 0x7d; // Keyboard Paste
		constexpr core::u8 WIN_KB_FIND = 0x7e; // Keyboard Find
		constexpr core::u8 WIN_KB_MUTE = 0x7f; // Keyboard Mute
		constexpr core::u8 WIN_KB_VOLUMEUP = 0x80; // Keyboard Volume Up
		constexpr core::u8 WIN_KB_VOLUMEDOWN = 0x81; // Keyboard Volume Down
		//constexpr core::u8 WIN_KB_ = 0x82  Keyboard Locking Caps Lock
		//constexpr core::u8 WIN_KB_ = 0x83  Keyboard Locking Num Lock
		//constexpr core::u8 WIN_KB_ = 0x84  Keyboard Locking Scroll Lock
		constexpr core::u8 WIN_KB_KPCOMMA = 0x85; // Keypad Comma
		//constexpr core::u8 WIN_KB_ = 0x86  Keypad Equal Sign
		constexpr core::u8 WIN_KB_RO = 0x87; // Keyboard International1
		constexpr core::u8 WIN_KB_KATAKANAHIRAGANA = 0x88; // Keyboard International2
		constexpr core::u8 WIN_KB_YEN = 0x89; // Keyboard International3
		constexpr core::u8 WIN_KB_HENKAN = 0x8a; // Keyboard International4
		constexpr core::u8 WIN_KB_MUHENKAN = 0x8b; // Keyboard International5
		constexpr core::u8 WIN_KB_KPJPCOMMA = 0x8c; // Keyboard International6
		//constexpr core::u8 WIN_KB_ = 0x8d  Keyboard International7
		//constexpr core::u8 WIN_KB_ = 0x8e  Keyboard International8
		//constexpr core::u8 WIN_KB_ = 0x8f  Keyboard International9
		constexpr core::u8 WIN_KB_HANGEUL = 0x90; // Keyboard LANG1
		constexpr core::u8 WIN_KB_HANJA = 0x91; // Keyboard LANG2
		constexpr core::u8 WIN_KB_KATAKANA = 0x92; // Keyboard LANG3
		constexpr core::u8 WIN_KB_HIRAGANA = 0x93; // Keyboard LANG4
		constexpr core::u8 WIN_KB_ZENKAKUHANKAKU = 0x94; // Keyboard LANG5
		//constexpr core::u8 WIN_KB_ = 0x95  Keyboard LANG6
		//constexpr core::u8 WIN_KB_ = 0x96  Keyboard LANG7
		//constexpr core::u8 WIN_KB_ = 0x97  Keyboard LANG8
		//constexpr core::u8 WIN_KB_ = 0x98  Keyboard LANG9
		//constexpr core::u8 WIN_KB_ = 0x99  Keyboard Alternate Erase
		//constexpr core::u8 WIN_KB_ = 0x9a  Keyboard SysReq/Attention
		//constexpr core::u8 WIN_KB_ = 0x9b  Keyboard Cancel
		//constexpr core::u8 WIN_KB_ = 0x9c  Keyboard Clear
		//constexpr core::u8 WIN_KB_ = 0x9d  Keyboard Prior
		//constexpr core::u8 WIN_KB_ = 0x9e  Keyboard Return
		//constexpr core::u8 WIN_KB_ = 0x9f  Keyboard Separator
		//constexpr core::u8 WIN_KB_ = 0xa0  Keyboard Out
		//constexpr core::u8 WIN_KB_ = 0xa1  Keyboard Oper
		//constexpr core::u8 WIN_KB_ = 0xa2  Keyboard Clear/Again
		//constexpr core::u8 WIN_KB_ = 0xa3  Keyboard CrSel/Props
		//constexpr core::u8 WIN_KB_ = 0xa4  Keyboard ExSel

		//constexpr core::u8 WIN_KB_ = 0xb0  Keypad 00
		//constexpr core::u8 WIN_KB_ = 0xb1  Keypad 000
		//constexpr core::u8 WIN_KB_ = 0xb2  Thousands Separator
		//constexpr core::u8 WIN_KB_ = 0xb3  Decimal Separator
		//constexpr core::u8 WIN_KB_ = 0xb4  Currency Unit
		//constexpr core::u8 WIN_KB_ = 0xb5  Currency Sub-unit
		constexpr core::u8 WIN_KB_KPLEFTPAREN = 0xb6; // Keypad (
		constexpr core::u8 WIN_KB_KPRIGHTPAREN = 0xb7; // Keypad )
		//constexpr core::u8 WIN_KB_ = 0xb8  Keypad {
		//constexpr core::u8 WIN_KB_ = 0xb9  Keypad }
		//constexpr core::u8 WIN_KB_ = 0xba  Keypad Tab
		//constexpr core::u8 WIN_KB_ = 0xbb  Keypad Backspace
		//constexpr core::u8 WIN_KB_ = 0xbc  Keypad A
		//constexpr core::u8 WIN_KB_ = 0xbd  Keypad B
		//constexpr core::u8 WIN_KB_ = 0xbe  Keypad C
		//constexpr core::u8 WIN_KB_ = 0xbf  Keypad D
		//constexpr core::u8 WIN_KB_ = 0xc0  Keypad E
		//constexpr core::u8 WIN_KB_ = 0xc1  Keypad F
		//constexpr core::u8 WIN_KB_ = 0xc2  Keypad XOR
		//constexpr core::u8 WIN_KB_ = 0xc3  Keypad ^
		//constexpr core::u8 WIN_KB_ = 0xc4  Keypad %
		//constexpr core::u8 WIN_KB_ = 0xc5  Keypad <
		//constexpr core::u8 WIN_KB_ = 0xc6  Keypad >
		//constexpr core::u8 WIN_KB_ = 0xc7  Keypad &
		//constexpr core::u8 WIN_KB_ = 0xc8  Keypad &&
		//constexpr core::u8 WIN_KB_ = 0xc9  Keypad |
		//constexpr core::u8 WIN_KB_ = 0xca  Keypad ||
		//constexpr core::u8 WIN_KB_ = 0xcb  Keypad :
		//constexpr core::u8 WIN_KB_ = 0xcc  Keypad #
		//constexpr core::u8 WIN_KB_ = 0xcd  Keypad Space
		//constexpr core::u8 WIN_KB_ = 0xce  Keypad @
		//constexpr core::u8 WIN_KB_ = 0xcf  Keypad !
		//constexpr core::u8 WIN_KB_ = 0xd0  Keypad Memory Store
		//constexpr core::u8 WIN_KB_ = 0xd1  Keypad Memory Recall
		//constexpr core::u8 WIN_KB_ = 0xd2  Keypad Memory Clear
		//constexpr core::u8 WIN_KB_ = 0xd3  Keypad Memory Add
		//constexpr core::u8 WIN_KB_ = 0xd4  Keypad Memory Subtract
		//constexpr core::u8 WIN_KB_ = 0xd5  Keypad Memory Multiply
		//constexpr core::u8 WIN_KB_ = 0xd6  Keypad Memory Divide
		//constexpr core::u8 WIN_KB_ = 0xd7  Keypad +/-
		//constexpr core::u8 WIN_KB_ = 0xd8  Keypad Clear
		//constexpr core::u8 WIN_KB_ = 0xd9  Keypad Clear Entry
		//constexpr core::u8 WIN_KB_ = 0xda  Keypad Binary
		//constexpr core::u8 WIN_KB_ = 0xdb  Keypad Octal
		//constexpr core::u8 WIN_KB_ = 0xdc  Keypad Decimal
		//constexpr core::u8 WIN_KB_ = 0xdd  Keypad Hexadecimal*/

		constexpr core::u8 WIN_KB_LEFTCTRL = VK_CONTROL; // Keyboard Left Control
		constexpr core::u8 WIN_KB_LEFTSHIFT = VK_SHIFT; // Keyboard Left Shift
		constexpr core::u8 WIN_KB_LEFTALT = VK_MENU; // Keyboard Left Alt
		//constexpr core::u8 WIN_KB_LEFTMETA = 0xe3; // Keyboard Left GUI
		constexpr core::u8 WIN_KB_RIGHTCTRL = VK_CONTROL; // Keyboard Right Control
		constexpr core::u8 WIN_KB_RIGHTSHIFT = VK_SHIFT; // Keyboard Right Shift
		constexpr core::u8 WIN_KB_RIGHTALT = VK_MENU; // Keyboard Right Alt
		//constexpr core::u8 WIN_KB_RIGHTMETA = 0xe7; // Keyboard Right GUI

		/*constexpr core::u8 WIN_KB_MEDIA_PLAYPAUSE = 0xe8;
		constexpr core::u8 WIN_KB_MEDIA_STOPCD = 0xe9;
		constexpr core::u8 WIN_KB_MEDIA_PREVIOUSSONG = 0xea;
		constexpr core::u8 WIN_KB_MEDIA_NEXTSONG = 0xeb;
		constexpr core::u8 WIN_KB_MEDIA_EJECTCD = 0xec;
		constexpr core::u8 WIN_KB_MEDIA_VOLUMEUP = 0xed;
		constexpr core::u8 WIN_KB_MEDIA_VOLUMEDOWN = 0xee;
		constexpr core::u8 WIN_KB_MEDIA_MUTE = 0xef;
		constexpr core::u8 WIN_KB_MEDIA_WWW = 0xf0;
		constexpr core::u8 WIN_KB_MEDIA_BACK = 0xf1;
		constexpr core::u8 WIN_KB_MEDIA_FORWARD = 0xf2;
		constexpr core::u8 WIN_KB_MEDIA_STOP = 0xf3;
		constexpr core::u8 WIN_KB_MEDIA_FIND = 0xf4;
		constexpr core::u8 WIN_KB_MEDIA_SCROLLUP = 0xf5;
		constexpr core::u8 WIN_KB_MEDIA_SCROLLDOWN = 0xf6;
		constexpr core::u8 WIN_KB_MEDIA_EDIT = 0xf7;
		constexpr core::u8 WIN_KB_MEDIA_SLEEP = 0xf8;
		constexpr core::u8 WIN_KB_MEDIA_COFFEE = 0xf9;
		constexpr core::u8 WIN_KB_MEDIA_REFRESH = 0xfa;
		constexpr core::u8 WIN_KB_MEDIA_CALC = 0xfb;*/
	}
}