#pragma once

#include <ove/core/util/types.hpp>

#include <windows.h>

namespace ove
{
	namespace system
	{
		//constexpr core::u8 KB_KEYNONE = 0x00; // No key pressed

		//constexpr core::u8 KB_ERR_ROLLOVER = 0x01; // Keyboard Error Roll Over
		//constexpr core::u8 KB_POST_FAIL = 0x02; // Keyboard POST Fail
		//constexpr core::u8 KB_ERR_UNDEFINED = 0x03; // Keyboard Error Undefined

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
		constexpr core::u8 WIN_KB_BACK = VK_BACK; // KEYCODE_BACK
		constexpr core::u8 WIN_KB_DELETE = VK_DELETE; // Keyboard DELETE (Backspace)
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

		//0x07 0x003a	Keyboard F1	0x003b	KEY_F1	3.0	0x0083	KEYCODE_F1
		//""	""	""	""	1.6	0x0052	KEYCODE_MENU
		//0x07 0x003b	Keyboard F2	0x003c	KEY_F2	3.0	0x0084	KEYCODE_F2
		//""	""	""	""	1.6	0x0002	KEYCODE_SOFT_RIGHT
		//0x07 0x003c	Keyboard F3	0x003d	KEY_F3	3.0	0x0085	KEYCODE_F3
		//""	""	""	""	1.6	0x0005	KEYCODE_CALL
		//0x07 0x003d	Keyboard F4	0x003e	KEY_F4	3.0	0x0086	KEYCODE_F4
		//""	""	""	""	1.6	0x0006	KEYCODE_ENDCALL
		//0x07 0x003e	Keyboard F5	0x003f	KEY_F5	3.0	0x0087	KEYCODE_F5
		//0x07 0x003f	Keyboard F6	0x0040	KEY_F6	3.0	0x0088	KEYCODE_F6
		//0x07 0x0040	Keyboard F7	0x0041	KEY_F7	3.0	0x0089	KEYCODE_F7
		//0x07 0x0041	Keyboard F8	0x0042	KEY_F8	3.0	0x008a	KEYCODE_F8
		//0x07 0x0042	Keyboard F9	0x0043	KEY_F9	3.0	0x008b	KEYCODE_F9
		//0x07 0x0043	Keyboard F10	0x0044	KEY_F10	3.0	0x008c	KEYCODE_F10
		//""	""	""	""	2.3	0x0052	KEYCODE_MENU
		//0x07 0x0044	Keyboard F11	0x0057	KEY_F11	3.0	0x008d	KEYCODE_F11
		//0x07 0x0045	Keyboard F12	0x0058	KEY_F12	3.0	0x008e	KEYCODE_F12
		//0x07 0x0046	Keyboard Print Screen	0x0063	KEY_SYSRQ	3.0	0x0078	KEYCODE_SYSRQ
		//0x07 0x0047	Keyboard Scroll Lock	0x0046	KEY_SCROLLLOCK	3.0	0x0074	KEYCODE_SCROLL_LOCK
		//0x07 0x0048	Keyboard Pause	0x0077	KEY_PAUSE	3.0	0x0079	KEYCODE_BREAK
		//0x07 0x0049	Keyboard Insert	0x006e	KEY_INSERT	3.0	0x007c	KEYCODE_INSERT
		//0x07 0x004a	Keyboard Home	0x0066	KEY_HOME	3.0	0x007a	KEYCODE_MOVE_HOME
		//""	""	""	""	1.6	0x0003	KEYCODE_HOME
		//0x07 0x004b	Keyboard Page Up	0x0068	KEY_PAGEUP	3.0	0x005c	KEYCODE_PAGE_UP
		//0x07 0x004c	Keyboard Delete Forward	0x006f	KEY_DELETE	3.0	0x0070	KEYCODE_FORWARD_DEL
		//0x07 0x004d	Keyboard End	0x006b	KEY_END	3.0	0x007b	KEYCODE_MOVE_END
		//""	""	""	""	1.6	0x0006	KEYCODE_ENDCALL
		//0x07 0x004e	Keyboard Page Down	0x006d	KEY_PAGEDOWN	3.0	0x005d	KEYCODE_PAGE_DOWN

		constexpr core::u8 WIN_KB_RIGHT = VK_RIGHT; // Keyboard Right Arrow
		constexpr core::u8 WIN_KB_LEFT = VK_LEFT; // Keyboard Left Arrow
		constexpr core::u8 WIN_KB_DOWN = VK_DOWN; // Keyboard Down Arrow
		constexpr core::u8 WIN_KB_UP = VK_UP; // Keyboard Up Arrow

		//0x07 0x0053	Keyboard Num Lock and Clear	0x0045	KEY_NUMLOCK	3.0	0x008f	KEYCODE_NUM_LOCK

		//0x07 0x0054	Keypad /	0x0062	KEY_KPSLASH	3.0	0x009a	KEYCODE_NUMPAD_DIVIDE
		//0x07 0x0055	Keypad *	0x0037	KEY_KPASTERISK	3.0	0x009b	KEYCODE_NUMPAD_MULTIPLY
		//0x07 0x0056	Keypad -	0x004a	KEY_KPMINUS	3.0	0x009c	KEYCODE_NUMPAD_SUBTRACT
		//0x07 0x0057	Keypad +	0x004e	KEY_KPPLUS	3.0	0x009d	KEYCODE_NUMPAD_ADD
		//0x07 0x0058	Keypad ENTER	0x0060	KEY_KPENTER	3.0	0x00a0	KEYCODE_NUMPAD_ENTER
		//0x07 0x0059	Keypad 1 and End	0x004f	KEY_KP1	3.0	0x0091	KEYCODE_NUMPAD_1
		//0x07 0x005a	Keypad 2 and Down Arrow	0x0050	KEY_KP2	3.0	0x0092	KEYCODE_NUMPAD_2
		//0x07 0x005b	Keypad 3 and PageDn	0x0051	KEY_KP3	3.0	0x0093	KEYCODE_NUMPAD_3
		//0x07 0x005c	Keypad 4 and Left Arrow	0x004b	KEY_KP4	3.0	0x0094	KEYCODE_NUMPAD_4
		//0x07 0x005d	Keypad 5	0x004c	KEY_KP5	3.0	0x0095	KEYCODE_NUMPAD_5
		//0x07 0x005e	Keypad 6 and Right Arrow	0x004d	KEY_KP6	3.0	0x0096	KEYCODE_NUMPAD_6
		//0x07 0x005f	Keypad 7 and Home	0x0047	KEY_KP7	3.0	0x0097	KEYCODE_NUMPAD_7
		//0x07 0x0060	Keypad 8 and Up Arrow	0x0048	KEY_KP8	3.0	0x0098	KEYCODE_NUMPAD_8
		//0x07 0x0061	Keypad 9 and Page Up	0x0049	KEY_KP9	3.0	0x0099	KEYCODE_NUMPAD_9
		//0x07 0x0062	Keypad 0 and Insert	0x0052	KEY_KP0	3.0	0x0090	KEYCODE_NUMPAD_0
		//0x07 0x0063	Keypad . and Delete	0x0053	KEY_KPDOT	3.0	0x009e	KEYCODE_NUMPAD_DOT

		//0x07 0x0064	Keyboard Non-US \ and |	0x0056	KEY_102ND	4.0	0x0049	KEYCODE_BACKSLASH	1
		//0x07 0x0065	Keyboard Application	0x007f	KEY_COMPOSE	3.0	0x0052	KEYCODE_MENU
		//""	""	""	""	1.6	0x0054	KEYCODE_SEARCH
		//0x07 0x0066	Keyboard Power	0x0074	KEY_POWER	1.6	0x001a	KEYCODE_POWER

		//0x07 0x0067	Keypad =	0x0075	KEY_KPEQUAL	3.0	0x00a1	KEYCODE_NUMPAD_EQUALS

		//0x07 0x0068	Keyboard F13	0x00b7	KEY_F13
		//0x07 0x0069	Keyboard F14	0x00b8	KEY_F14
		//0x07 0x006a	Keyboard F15	0x00b9	KEY_F15
		//0x07 0x006b	Keyboard F16	0x00ba	KEY_F16
		//0x07 0x006c	Keyboard F17	0x00bb	KEY_F17
		//0x07 0x006d	Keyboard F18	0x00bc	KEY_F18
		//0x07 0x006e	Keyboard F19	0x00bd	KEY_F19
		//0x07 0x006f	Keyboard F20	0x00be	KEY_F20
		//0x07 0x0070	Keyboard F21	0x00bf	KEY_F21
		//0x07 0x0071	Keyboard F22	0x00c0	KEY_F22
		//0x07 0x0072	Keyboard F23	0x00c1	KEY_F23
		//0x07 0x0073	Keyboard F24	0x00c2	KEY_F24
		//0x07 0x0074	Keyboard Execute	0x0086	KEY_OPEN
		//0x07 0x0075	Keyboard Help	0x008a	KEY_HELP
		//0x07 0x0076	Keyboard Menu	0x0082	KEY_PROPS
		//0x07 0x0077	Keyboard Select	0x0084	KEY_FRONT
		//0x07 0x0078	Keyboard Stop	0x0080	KEY_STOP	3.0	0x0056	KEYCODE_MEDIA_STOP
		//0x07 0x0079	Keyboard Again	0x0081	KEY_AGAIN
		//0x07 0x007a	Keyboard Undo	0x0083	KEY_UNDO
		//0x07 0x007b	Keyboard Cut	0x0089	KEY_CUT
		//0x07 0x007c	Keyboard Copy	0x0085	KEY_COPY
		//0x07 0x007d	Keyboard Paste	0x0087	KEY_PASTE
		//0x07 0x007e	Keyboard Find	0x0088	KEY_FIND
		//0x07 0x007f	Keyboard Mute	0x0071	KEY_MUTE	3.0	0x00a4	KEYCODE_VOLUME_MUTE
		//0x07 0x0080	Keyboard Volume Up	0x0073	KEY_VOLUMEUP	1.6	0x0018	KEYCODE_VOLUME_UP
		//0x07 0x0081	Keyboard Volume Down	0x0072	KEY_VOLUMEDOWN	1.6	0x0019	KEYCODE_VOLUME_DOWN
		//0x07 0x0082	Keyboard Locking Caps Lock
		//0x07 0x0083	Keyboard Locking Num Lock
		//0x07 0x0084	Keyboard Locking Scroll Lock

		//0x07 0x0085	Keypad Comma	0x0079	KEY_KPCOMMA	3.0	0x009f	KEYCODE_NUMPAD_COMMA
		//0x07 0x0086	Keypad Equal Sign

		//0x07 0x0087	Keyboard International1	0x0059	KEY_RO
		//0x07 0x0088	Keyboard International2	0x005d	KEY_KATAKANAHIRAGANA
		//0x07 0x0089	Keyboard International3	0x007c	KEY_YEN
		//0x07 0x008a	Keyboard International4	0x005c	KEY_HENKAN
		//0x07 0x008b	Keyboard International5	0x005e	KEY_MUHENKAN
		//0x07 0x008c	Keyboard International6	0x005f	KEY_KPJPCOMMA
		//0x07 0x008d	Keyboard International7
		//0x07 0x008e	Keyboard International8
		//0x07 0x008f	Keyboard International9
		//0x07 0x0090	Keyboard LANG1	0x007a	KEY_HANGEUL
		//0x07 0x0091	Keyboard LANG2	0x007b	KEY_HANJA
		//0x07 0x0092	Keyboard LANG3	0x005a	KEY_KATAKANA
		//0x07 0x0093	Keyboard LANG4	0x005b	KEY_HIRAGANA
		//0x07 0x0094	Keyboard LANG5	0x0055	KEY_ZENKAKUHANKAKU
		//0x07 0x0095	Keyboard LANG6
		//0x07 0x0096	Keyboard LANG7
		//0x07 0x0097	Keyboard LANG8
		//0x07 0x0098	Keyboard LANG9
		//0x07 0x0099	Keyboard Alternate Erase
		//0x07 0x009a	Keyboard SysReq/Attention
		//0x07 0x009b	Keyboard Cancel
		//0x07 0x009c	Keyboard Clear
		//0x07 0x009d	Keyboard Prior
		//0x07 0x009e	Keyboard Return
		//0x07 0x009f	Keyboard Separator
		//0x07 0x00a0	Keyboard Out
		//0x07 0x00a1	Keyboard Oper
		//0x07 0x00a2	Keyboard Clear/Again
		//0x07 0x00a3	Keyboard CrSel/Props
		//0x07 0x00a4	Keyboard ExSel

		//0x07 0x00b0	Keypad 00
		//0x07 0x00b1	Keypad 000
		//0x07 0x00b2	Thousands Separator
		//0x07 0x00b3	Decimal Separator
		//0x07 0x00b4	Currency Unit
		//0x07 0x00b5	Currency Sub-unit
		//0x07 0x00b6	Keypad (	0x00b3	KEY_KPLEFTPAREN	3.0	0x00a2	KEYCODE_NUMPAD_LEFT_PAREN
		//0x07 0x00b7	Keypad )	0x00b4	KEY_KPRIGHTPAREN	3.0	0x00a3	KEYCODE_NUMPAD_RIGHT_PAREN
		//0x07 0x00b8	Keypad {
		//0x07 0x00b9	Keypad }
		//0x07 0x00ba	Keypad Tab
		//0x07 0x00bb	Keypad Backspace
		//0x07 0x00bc	Keypad A
		//0x07 0x00bd	Keypad B
		//0x07 0x00be	Keypad C
		//0x07 0x00bf	Keypad D
		//0x07 0x00c0	Keypad E
		//0x07 0x00c1	Keypad F
		//0x07 0x00c2	Keypad XOR
		//0x07 0x00c3	Keypad ^
		//0x07 0x00c4	Keypad %
		//0x07 0x00c5	Keypad <
		//0x07 0x00c6	Keypad >
		//0x07 0x00c7	Keypad &
		//0x07 0x00c8	Keypad &&
		//0x07 0x00c9	Keypad |
		//0x07 0x00ca	Keypad ||
		//0x07 0x00cb	Keypad :
		//0x07 0x00cc	Keypad #
		//0x07 0x00cd	Keypad Space
		//0x07 0x00ce	Keypad @
		//0x07 0x00cf	Keypad !
		//0x07 0x00d0	Keypad Memory Store
		//0x07 0x00d1	Keypad Memory Recall
		//0x07 0x00d2	Keypad Memory Clear
		//0x07 0x00d3	Keypad Memory Add
		//0x07 0x00d4	Keypad Memory Subtract
		//0x07 0x00d5	Keypad Memory Multiply
		//0x07 0x00d6	Keypad Memory Divide
		//0x07 0x00d7	Keypad +/-
		//0x07 0x00d8	Keypad Clear
		//0x07 0x00d9	Keypad Clear Entry
		//0x07 0x00da	Keypad Binary
		//0x07 0x00db	Keypad Octal
		//0x07 0x00dc	Keypad Decimal
		//0x07 0x00dd	Keypad Hexadecimal

		// TODO: https://open.spotify.com/track/527xklI1BeHbnWtAP9t3u6?si=D_nnQxB4Q0-7r6CbBMgeKA
		constexpr core::u8 WIN_KB_LEFTCTRL = VK_CONTROL; // Keyboard Left Control
		constexpr core::u8 WIN_KB_LEFTSHIFT = VK_SHIFT; // Keyboard Left Shift
		constexpr core::u8 WIN_KB_LEFTALT = VK_MENU; // Keyboard Left Alt
		//constexpr core::u8 WIN_KB_LEFTMETA = 0xe3; // Keyboard Left GUI
		constexpr core::u8 WIN_KB_RIGHTCTRL = VK_CONTROL; // Keyboard Right Control
		constexpr core::u8 WIN_KB_RIGHTSHIFT = VK_SHIFT; // Keyboard Right Shift
		constexpr core::u8 WIN_KB_RIGHTALT = VK_MENU; // Keyboard Right Alt
		//constexpr core::u8 WIN_KB_RIGHTMETA = 0xe7; // Keyboard Right GUI

		//0x07 0x00e8		0x00a4	KEY_PLAYPAUSE	3.0	0x0055	KEYCODE_MEDIA_PLAY_PAUSE
		//0x07 0x00e9		0x00a6	KEY_STOPCD	3.0	0x0056	KEYCODE_MEDIA_STOP
		//0x07 0x00ea		0x00a5	KEY_PREVIOUSSONG	3.0	0x0058	KEYCODE_MEDIA_PREVIOUS
		//0x07 0x00eb		0x00a3	KEY_NEXTSONG	3.0	0x0057	KEYCODE_MEDIA_NEXT
		//0x07 0x00ec		0x00a1	KEY_EJECTCD	3.0	0x0081	KEYCODE_MEDIA_EJECT
		//0x07 0x00ed		0x0073	KEY_VOLUMEUP	1.6	0x0018	KEYCODE_VOLUME_UP
		//0x07 0x00ee		0x0072	KEY_VOLUMEDOWN	1.6	0x0019	KEYCODE_VOLUME_DOWN
		//0x07 0x00ef		0x0071	KEY_MUTE	3.0	0x00a4	KEYCODE_VOLUME_MUTE
		//0x07 0x00f0		0x0096	KEY_WWW	1.6	0x0040	KEYCODE_EXPLORER
		//0x07 0x00f1		0x009e	KEY_BACK	1.6	0x0004	KEYCODE_BACK
		//0x07 0x00f2		0x009f	KEY_FORWARD	3.0	0x007d	KEYCODE_FORWARD
		//0x07 0x00f3		0x0080	KEY_STOP	3.0	0x0056	KEYCODE_MEDIA_STOP
		//0x07 0x00f4		0x0088	KEY_FIND
		//0x07 0x00f5		0x00b1	KEY_SCROLLUP	3.0	0x005c	KEYCODE_PAGE_UP
		//0x07 0x00f6		0x00b2	KEY_SCROLLDOWN	3.0	0x005d	KEYCODE_PAGE_DOWN
		//0x07 0x00f7		0x00b0	KEY_EDIT
		//0x07 0x00f8		0x008e	KEY_SLEEP
		//0x07 0x00f9		0x0098	KEY_COFFEE	4.0	0x001a	KEYCODE_POWER
		//0x07 0x00fa		0x00ad	KEY_REFRESH
		//0x07 0x00fb		0x008c	KEY_CALC	4.0.3	0x00d2	KEYCODE_CALCULATOR
	}
}