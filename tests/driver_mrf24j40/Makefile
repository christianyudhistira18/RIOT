APPLICATION = driver_at86rf2xx
include ../Makefile.tests_common

FEATURES_REQUIRED = periph_spi periph_gpio

BOARD_INSUFFICIENT_MEMORY := nucleo-f334 stm32f0discovery weio

USEMODULE += auto_init_gnrc_netif
USEMODULE += gnrc_netif
USEMODULE += gnrc_nomac
USEMODULE += gnrc_pktdump
USEMODULE += shell
USEMODULE += shell_commands
USEMODULE += ps

# define the driver to be used for selected boards
ifneq (,$(filter samr21-xpro,$(BOARD)))
  DRIVER := mrf24j40
endif
ifneq (,$(filter iotlab-m3 fox,$(BOARD)))
  DRIVER := mrf24j40
endif
ifneq (,$(filter mulle,$(BOARD)))
  DRIVER := mrf24j40
endif
ifneq (,$(filter stm32f4discovery,$(BOARD)))
  DRIVER := mrf24j40
endif

# use the at86rf231 as fallback device
DRIVER ?= mrf24j40

# include the selected driver
USEMODULE += $(DRIVER)

CFLAGS += -DDEVELHELP

include $(RIOTBASE)/Makefile.include
