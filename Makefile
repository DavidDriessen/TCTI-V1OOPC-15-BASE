.PHONY: clean All

All:
	@echo "----------Building project:[ 22-2-patroon -  ]----------"
	@cd "22-2-patroon" && "$(MAKE)" -f  "22-2-patroon.mk"
clean:
	@echo "----------Cleaning project:[ 22-2-patroon -  ]----------"
	@cd "22-2-patroon" && "$(MAKE)" -f  "22-2-patroon.mk" clean
