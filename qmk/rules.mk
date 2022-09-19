# Enabled Features
KEY_LOCK_ENABLE = yes        # Key Lock ~6%
TAP_DANCE_ENABLE = yes       # Tap Dance ~3%
DEBOUNCE_TYPE = sym_eager_pk # Eager Per-key Symmetrical Debouncing
STENO_ENABLE = yes           # Stenography ~5% + 3 endpoints
STENO_LAYERS = yes

# By default, MOUSEKEY, EXTRAKEY, and NKRO are combined into a single endpoint.
EXTRAKEY_ENABLE = yes        # Audio control and System control ~2%
MOUSEKEY_ENABLE = yes        # Mouse ~4%
NKRO_ENABLE = yes            # USB Nkey Rollover

# Disabled Features
AUTO_SHIFT_ENABLE = no       # Auto Shift ~12%
BOOTMAGIC_ENABLE = no        # Virtual DIP switch configuration ~3%
COMBO_ENABLE = no            # Combo ~1%
COMMAND_ENABLE = no          # Commands for debug and configuration ~17%
CONSOLE_ENABLE = no          # Console for debug ~6%
DEBUG_MATRIX = no            #
DEBUG_MATRIX_SCAN_RATE  = no #
GRAVE_ESC_ENABLE = no        #
KEY_OVERRIDE_ENABLE = no     #
LEADER_ENABLE = no           #
LTO_ENABLE = no              #
MAGIC_ENABLE = no            #
MUSIC_ENABLE = no            #
POINTING_DEVICE_ENABLE = no  # Pointing Device ~2%
RAW_ENABLE = no              #
RGB_MATRIX_ENABLE = no       #
SEQUENCER_ENABLE = no        # Sequencer ~3%
SPACE_CADET_ENABLE = no      #
SWAP_HANDS_ENABLE = no       #
UCIS_ENABLE = no             # Unicode UCIS ~7%
UNICODE_ENABLE = no          # Unicode ~4%
UNICODEMAP_ENABLE = no       # Unicode Map ~5%
VERBOSE = no                 #
WPM_ENABLE = no              #
CUSTOM_MATRIX = no           #

# Optimizations
KEYBOARD_SHARED_EP = yes     # Frees up one more endpoint, but it can prevent the keyboard working in (some) BIOSes
LTO_ENABLE = yes             # Link Time Optimization (disables Action Functions and Action Macros)