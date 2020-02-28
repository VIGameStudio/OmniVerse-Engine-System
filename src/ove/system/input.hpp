#pragma once

#include <ove/core/util/types.hpp>

namespace ove
{
	namespace system
	{
		constexpr core::u8 KEYS_STATE_MAXSIZE = 0xff; // Max size of key states.

		constexpr core::u8 BUTTON_STATE_MAXSIZE = 0x05; // Max size of mouse button states.

		constexpr core::u8 MBTN_LEFT = 0x01; // Mouse button left
		constexpr core::u8 MBTN_MIDDLE = 0x02; // Mouse button middle
		constexpr core::u8 MBTN_RIGHT = 0x03; // Mouse button right

		// https://source.android.com/devices/input/keyboard-devices.html
		// https://gist.github.com/MightyPork/6da26e382a7ad91b5496ee55fdc73db2

		constexpr core::u8 KB_NONE = 0x00; // No key pressed

		constexpr core::u8 KB_ERR_ROLLOVER = 0x01; // Keyboard Error Roll Over
		constexpr core::u8 KB_ERR_POST_FAIL = 0x02; // Keyboard POST Fail
		constexpr core::u8 KB_ERR_UNDEFINED = 0x03; // Keyboard Error Undefined

		constexpr core::u8 KB_A = 0x04; // Keyboard a and A
		constexpr core::u8 KB_B = 0x05; // Keyboard b and B
		constexpr core::u8 KB_C = 0x06; // Keyboard c and C
		constexpr core::u8 KB_D = 0x07; // Keyboard d and D
		constexpr core::u8 KB_E = 0x08; // Keyboard e and E
		constexpr core::u8 KB_F = 0x09; // Keyboard f and F
		constexpr core::u8 KB_G = 0x0a; // Keyboard g and G
		constexpr core::u8 KB_H = 0x0b; // Keyboard h and H
		constexpr core::u8 KB_I = 0x0c; // Keyboard i and I
		constexpr core::u8 KB_J = 0x0d; // Keyboard j and J
		constexpr core::u8 KB_K = 0x0e; // Keyboard k and K
		constexpr core::u8 KB_L = 0x0f; // Keyboard l and L
		constexpr core::u8 KB_M = 0x10; // Keyboard m and M
		constexpr core::u8 KB_N = 0x11; // Keyboard n and N
		constexpr core::u8 KB_O = 0x12; // Keyboard o and O
		constexpr core::u8 KB_P = 0x13; // Keyboard p and P
		constexpr core::u8 KB_Q = 0x14; // Keyboard q and Q
		constexpr core::u8 KB_R = 0x15; // Keyboard r and R
		constexpr core::u8 KB_S = 0x16; // Keyboard s and S
		constexpr core::u8 KB_T = 0x17; // Keyboard t and T
		constexpr core::u8 KB_U = 0x18; // Keyboard u and U
		constexpr core::u8 KB_V = 0x19; // Keyboard v and V
		constexpr core::u8 KB_W = 0x1a; // Keyboard w and W
		constexpr core::u8 KB_X = 0x1b; // Keyboard x and X
		constexpr core::u8 KB_Y = 0x1c; // Keyboard y and Y
		constexpr core::u8 KB_Z = 0x1d; // Keyboard z and Z

		constexpr core::u8 KB_1 = 0x1e; // Keyboard 1 and !
		constexpr core::u8 KB_2 = 0x1f; // Keyboard 2 and @
		constexpr core::u8 KB_3 = 0x20; // Keyboard 3 and #
		constexpr core::u8 KB_4 = 0x21; // Keyboard 4 and $
		constexpr core::u8 KB_5 = 0x22; // Keyboard 5 and %
		constexpr core::u8 KB_6 = 0x23; // Keyboard 6 and ^
		constexpr core::u8 KB_7 = 0x24; // Keyboard 7 and &
		constexpr core::u8 KB_8 = 0x25; // Keyboard 8 and *
		constexpr core::u8 KB_9 = 0x26; // Keyboard 9 and (
		constexpr core::u8 KB_0 = 0x27; // Keyboard 0 and )

		constexpr core::u8 KB_ENTER = 0x28; // Keyboard Return (ENTER)
		constexpr core::u8 KB_ESCAPE = 0x29; // Keyboard ESCAPE
		constexpr core::u8 KB_BACKSPACE = 0x2a; // Keyboard DELETE (Backspace)
		constexpr core::u8 KB_TAB = 0x2b; // Keyboard Tab
		constexpr core::u8 KB_SPACE = 0x2c; // Keyboard Spacebar
		constexpr core::u8 KB_MINUS = 0x2d; // Keyboard - and _
		constexpr core::u8 KB_EQUAL = 0x2e; // Keyboard = and +
		constexpr core::u8 KB_LEFTBRACE = 0x2f; // Keyboard [ and {
		constexpr core::u8 KB_RRIGHTBRACE = 0x30; // Keyboard ] and }
		constexpr core::u8 KB_BACKSLASH = 0x31; // Keyboard \ and |
		constexpr core::u8 KB_HASHTILDE = 0x32; // Keyboard Non-US # and ~
		constexpr core::u8 KB_SEMICOLON = 0x33; // Keyboard ; and :
		constexpr core::u8 KB_APOSTROPHE = 0x34; // Keyboard ' and "
		constexpr core::u8 KB_GRAVE = 0x35; // Keyboard ` and ~
		constexpr core::u8 KB_COMMA = 0x36; // Keyboard , and <
		constexpr core::u8 KB_DOT = 0x37; // Keyboard .and >
		constexpr core::u8 KB_SLASH = 0x38; // Keyboard / and ?
		constexpr core::u8 KB_CAPSLOCK = 0x39; // Keyboard Caps Lock

		constexpr core::u8 KB_F1 = 0x3a; // Keyboard F1
		constexpr core::u8 KB_F2 = 0x3b; // Keyboard F2
		constexpr core::u8 KB_F3 = 0x3c; // Keyboard F3
		constexpr core::u8 KB_F4 = 0x3d; // Keyboard F4
		constexpr core::u8 KB_F5 = 0x3e; // Keyboard F5
		constexpr core::u8 KB_F6 = 0x3f; // Keyboard F6
		constexpr core::u8 KB_F7 = 0x40; // Keyboard F7
		constexpr core::u8 KB_F8 = 0x41; // Keyboard F8
		constexpr core::u8 KB_F9 = 0x42; // Keyboard F9
		constexpr core::u8 KB_F10 = 0x43; // Keyboard F10
		constexpr core::u8 KB_F11 = 0x44; // Keyboard F11
		constexpr core::u8 KB_F12 = 0x45; // Keyboard F12

		constexpr core::u8 KB_SYSRQ = 0x46; // Keyboard Print Screen
		constexpr core::u8 KB_SCROLLLOCK = 0x47; // Keyboard Scroll Lock
		constexpr core::u8 KB_PAUSE = 0x48; // Keyboard Pause
		constexpr core::u8 KB_INSERT = 0x49; // Keyboard Insert
		constexpr core::u8 KB_HOME = 0x4a; // Keyboard Home
		constexpr core::u8 KB_PAGEUP = 0x4b; // Keyboard Page Up
		constexpr core::u8 KB_DELETE = 0x4c; // Keyboard Delete Forward
		constexpr core::u8 KB_END = 0x4d; // Keyboard End
		constexpr core::u8 KB_PAGEDOWN = 0x4e; // Keyboard Page Down

		constexpr core::u8 KB_RIGHT = 0x4f; // Keyboard Right Arrow
		constexpr core::u8 KB_LEFT = 0x50; // Keyboard Left Arrow
		constexpr core::u8 KB_DOWN = 0x51; // Keyboard Down Arrow
		constexpr core::u8 KB_UP = 0x52; // Keyboard Up Arrow

		constexpr core::u8 KB_NUMLOCK = 0x53; // Keyboard Num Lock and Clear
		constexpr core::u8 KB_KPSLASH = 0x54; // Keypad /
		constexpr core::u8 KB_KPASTERISK = 0x55; // Keypad *
		constexpr core::u8 KB_KPMINUS = 0x56; // Keypad -
		constexpr core::u8 KB_KPPLUS = 0x57; // Keypad +
		constexpr core::u8 KB_KPENTER = 0x58; // Keypad ENTER
		constexpr core::u8 KB_KP1 = 0x59; // Keypad 1 and End
		constexpr core::u8 KB_KP2 = 0x5a; // Keypad 2 and Down Arrow
		constexpr core::u8 KB_KP3 = 0x5b; // Keypad 3 and PageDn
		constexpr core::u8 KB_KP4 = 0x5c; // Keypad 4 and Left Arrow
		constexpr core::u8 KB_KP5 = 0x5d; // Keypad 5
		constexpr core::u8 KB_KP6 = 0x5e; // Keypad 6 and Right Arrow
		constexpr core::u8 KB_KP7 = 0x5f; // Keypad 7 and Home
		constexpr core::u8 KB_KP8 = 0x60; // Keypad 8 and Up Arrow
		constexpr core::u8 KB_KP9 = 0x61; // Keypad 9 and Page Up
		constexpr core::u8 KB_KP0 = 0x62; // Keypad 0 and Insert
		constexpr core::u8 KB_KPDOT = 0x63; // Keypad . and Delete

		constexpr core::u8 KB_102ND = 0x64; // Keyboard Non-US \ and |
		constexpr core::u8 KB_COMPOSE = 0x65; // Keyboard Application
		constexpr core::u8 KB_POWER = 0x66; // Keyboard Power
		constexpr core::u8 KB_KPEQUAL = 0x67; // Keypad =

		constexpr core::u8 KB_F13 = 0x68; // Keyboard F13
		constexpr core::u8 KB_F14 = 0x69; // Keyboard F14
		constexpr core::u8 KB_F15 = 0x6a; // Keyboard F15
		constexpr core::u8 KB_F16 = 0x6b; // Keyboard F16
		constexpr core::u8 KB_F17 = 0x6c; // Keyboard F17
		constexpr core::u8 KB_F18 = 0x6d; // Keyboard F18
		constexpr core::u8 KB_F19 = 0x6e; // Keyboard F19
		constexpr core::u8 KB_F20 = 0x6f; // Keyboard F20
		constexpr core::u8 KB_F21 = 0x70; // Keyboard F21
		constexpr core::u8 KB_F22 = 0x71; // Keyboard F22
		constexpr core::u8 KB_F23 = 0x72; // Keyboard F23
		constexpr core::u8 KB_F24 = 0x73; // Keyboard F24

		constexpr core::u8 KB_OPEN = 0x74; // Keyboard Execute
		constexpr core::u8 KB_HELP = 0x75; // Keyboard Help
		constexpr core::u8 KB_PROPS = 0x76; // Keyboard Menu
		constexpr core::u8 KB_FRONT = 0x77; // Keyboard Select
		constexpr core::u8 KB_STOP = 0x78; // Keyboard Stop
		constexpr core::u8 KB_AGAIN = 0x79; // Keyboard Again
		constexpr core::u8 KB_UNDO = 0x7a; // Keyboard Undo
		constexpr core::u8 KB_CUT = 0x7b; // Keyboard Cut
		constexpr core::u8 KB_COPY = 0x7c; // Keyboard Copy
		constexpr core::u8 KB_PASTE = 0x7d; // Keyboard Paste
		constexpr core::u8 KB_FIND = 0x7e; // Keyboard Find
		constexpr core::u8 KB_MUTE = 0x7f; // Keyboard Mute
		constexpr core::u8 KB_VOLUMEUP = 0x80; // Keyboard Volume Up
		constexpr core::u8 KB_VOLUMEDOWN = 0x81; // Keyboard Volume Down
		//constexpr core::u8 KB_ = 0x82  Keyboard Locking Caps Lock
		//constexpr core::u8 KB_ = 0x83  Keyboard Locking Num Lock
		//constexpr core::u8 KB_ = 0x84  Keyboard Locking Scroll Lock
		constexpr core::u8 KB_KPCOMMA = 0x85; // Keypad Comma
		//constexpr core::u8 KB_ = 0x86  Keypad Equal Sign
		constexpr core::u8 KB_RO = 0x87; // Keyboard International1
		constexpr core::u8 KB_KATAKANAHIRAGANA = 0x88; // Keyboard International2
		constexpr core::u8 KB_YEN = 0x89; // Keyboard International3
		constexpr core::u8 KB_HENKAN = 0x8a; // Keyboard International4
		constexpr core::u8 KB_MUHENKAN = 0x8b; // Keyboard International5
		constexpr core::u8 KB_KPJPCOMMA = 0x8c; // Keyboard International6
		//constexpr core::u8 KB_ = 0x8d  Keyboard International7
		//constexpr core::u8 KB_ = 0x8e  Keyboard International8
		//constexpr core::u8 KB_ = 0x8f  Keyboard International9
		constexpr core::u8 KB_HANGEUL = 0x90; // Keyboard LANG1
		constexpr core::u8 KB_HANJA = 0x91; // Keyboard LANG2
		constexpr core::u8 KB_KATAKANA = 0x92; // Keyboard LANG3
		constexpr core::u8 KB_HIRAGANA = 0x93; // Keyboard LANG4
		constexpr core::u8 KB_ZENKAKUHANKAKU = 0x94; // Keyboard LANG5
		//constexpr core::u8 KB_ = 0x95  Keyboard LANG6
		//constexpr core::u8 KB_ = 0x96  Keyboard LANG7
		//constexpr core::u8 KB_ = 0x97  Keyboard LANG8
		//constexpr core::u8 KB_ = 0x98  Keyboard LANG9
		//constexpr core::u8 KB_ = 0x99  Keyboard Alternate Erase
		//constexpr core::u8 KB_ = 0x9a  Keyboard SysReq/Attention
		//constexpr core::u8 KB_ = 0x9b  Keyboard Cancel
		//constexpr core::u8 KB_ = 0x9c  Keyboard Clear
		//constexpr core::u8 KB_ = 0x9d  Keyboard Prior
		//constexpr core::u8 KB_ = 0x9e  Keyboard Return
		//constexpr core::u8 KB_ = 0x9f  Keyboard Separator
		//constexpr core::u8 KB_ = 0xa0  Keyboard Out
		//constexpr core::u8 KB_ = 0xa1  Keyboard Oper
		//constexpr core::u8 KB_ = 0xa2  Keyboard Clear/Again
		//constexpr core::u8 KB_ = 0xa3  Keyboard CrSel/Props
		//constexpr core::u8 KB_ = 0xa4  Keyboard ExSel

		//constexpr core::u8 KB_ = 0xb0  Keypad 00
		//constexpr core::u8 KB_ = 0xb1  Keypad 000
		//constexpr core::u8 KB_ = 0xb2  Thousands Separator
		//constexpr core::u8 KB_ = 0xb3  Decimal Separator
		//constexpr core::u8 KB_ = 0xb4  Currency Unit
		//constexpr core::u8 KB_ = 0xb5  Currency Sub-unit
		constexpr core::u8 KB_KPLEFTPAREN = 0xb6; // Keypad (
		constexpr core::u8 KB_KPRIGHTPAREN = 0xb7; // Keypad )
		//constexpr core::u8 KB_ = 0xb8  Keypad {
		//constexpr core::u8 KB_ = 0xb9  Keypad }
		//constexpr core::u8 KB_ = 0xba  Keypad Tab
		//constexpr core::u8 KB_ = 0xbb  Keypad Backspace
		//constexpr core::u8 KB_ = 0xbc  Keypad A
		//constexpr core::u8 KB_ = 0xbd  Keypad B
		//constexpr core::u8 KB_ = 0xbe  Keypad C
		//constexpr core::u8 KB_ = 0xbf  Keypad D
		//constexpr core::u8 KB_ = 0xc0  Keypad E
		//constexpr core::u8 KB_ = 0xc1  Keypad F
		//constexpr core::u8 KB_ = 0xc2  Keypad XOR
		//constexpr core::u8 KB_ = 0xc3  Keypad ^
		//constexpr core::u8 KB_ = 0xc4  Keypad %
		//constexpr core::u8 KB_ = 0xc5  Keypad <
		//constexpr core::u8 KB_ = 0xc6  Keypad >
		//constexpr core::u8 KB_ = 0xc7  Keypad &
		//constexpr core::u8 KB_ = 0xc8  Keypad &&
		//constexpr core::u8 KB_ = 0xc9  Keypad |
		//constexpr core::u8 KB_ = 0xca  Keypad ||
		//constexpr core::u8 KB_ = 0xcb  Keypad :
		//constexpr core::u8 KB_ = 0xcc  Keypad #
		//constexpr core::u8 KB_ = 0xcd  Keypad Space
		//constexpr core::u8 KB_ = 0xce  Keypad @
		//constexpr core::u8 KB_ = 0xcf  Keypad !
		//constexpr core::u8 KB_ = 0xd0  Keypad Memory Store
		//constexpr core::u8 KB_ = 0xd1  Keypad Memory Recall
		//constexpr core::u8 KB_ = 0xd2  Keypad Memory Clear
		//constexpr core::u8 KB_ = 0xd3  Keypad Memory Add
		//constexpr core::u8 KB_ = 0xd4  Keypad Memory Subtract
		//constexpr core::u8 KB_ = 0xd5  Keypad Memory Multiply
		//constexpr core::u8 KB_ = 0xd6  Keypad Memory Divide
		//constexpr core::u8 KB_ = 0xd7  Keypad +/-
		//constexpr core::u8 KB_ = 0xd8  Keypad Clear
		//constexpr core::u8 KB_ = 0xd9  Keypad Clear Entry
		//constexpr core::u8 KB_ = 0xda  Keypad Binary
		//constexpr core::u8 KB_ = 0xdb  Keypad Octal
		//constexpr core::u8 KB_ = 0xdc  Keypad Decimal
		//constexpr core::u8 KB_ = 0xdd  Keypad Hexadecimal

		constexpr core::u8 KB_LEFTCTRL = 0xe0; // Keyboard Left Control
		constexpr core::u8 KB_LEFTSHIFT = 0xe1; // Keyboard Left Shift
		constexpr core::u8 KB_LEFTALT = 0xe2; // Keyboard Left Alt
		constexpr core::u8 KB_LEFTMETA = 0xe3; // Keyboard Left GUI
		constexpr core::u8 KB_RIGHTCTRL = 0xe4; // Keyboard Right Control
		constexpr core::u8 KB_RIGHTSHIFT = 0xe5; // Keyboard Right Shift
		constexpr core::u8 KB_RIGHTALT = 0xe6; // Keyboard Right Alt
		constexpr core::u8 KB_RIGHTMETA = 0xe7; // Keyboard Right GUI

		constexpr core::u8 KB_MEDIA_PLAYPAUSE = 0xe8;
		constexpr core::u8 KB_MEDIA_STOPCD = 0xe9;
		constexpr core::u8 KB_MEDIA_PREVIOUSSONG = 0xea;
		constexpr core::u8 KB_MEDIA_NEXTSONG = 0xeb;
		constexpr core::u8 KB_MEDIA_EJECTCD = 0xec;
		constexpr core::u8 KB_MEDIA_VOLUMEUP = 0xed;
		constexpr core::u8 KB_MEDIA_VOLUMEDOWN = 0xee;
		constexpr core::u8 KB_MEDIA_MUTE = 0xef;
		constexpr core::u8 KB_MEDIA_WWW = 0xf0;
		constexpr core::u8 KB_MEDIA_BACK = 0xf1;
		constexpr core::u8 KB_MEDIA_FORWARD = 0xf2;
		constexpr core::u8 KB_MEDIA_STOP = 0xf3;
		constexpr core::u8 KB_MEDIA_FIND = 0xf4;
		constexpr core::u8 KB_MEDIA_SCROLLUP = 0xf5;
		constexpr core::u8 KB_MEDIA_SCROLLDOWN = 0xf6;
		constexpr core::u8 KB_MEDIA_EDIT = 0xf7;
		constexpr core::u8 KB_MEDIA_SLEEP = 0xf8;
		constexpr core::u8 KB_MEDIA_COFFEE = 0xf9;
		constexpr core::u8 KB_MEDIA_REFRESH = 0xfa;
		constexpr core::u8 KB_MEDIA_CALC = 0xfb;
	}
}