ifndef IMPORT_OPENSSL
IMPORT_OPENSSL := 1

BLDLIBS += $(BASE)/import/openssl

SLIBS := -lcrypto -lssl $(SLIBS)

ifeq ($(BLDTYPE),debug)
SLIBS := -limportopenssld $(SLIBS)
else
SLIBS := -limportopenssl $(SLIBS)
endif

endif
