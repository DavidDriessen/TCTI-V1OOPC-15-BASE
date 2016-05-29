.PHONY: clean All

All:
	@echo "----------Building project:[ 21-04-window -  ]----------"
	@cd "21-04-window" && "$(MAKE)" -f  "21-04-window.mk"
clean:
	@echo "----------Cleaning project:[ 21-04-window -  ]----------"
	@cd "21-04-window" && "$(MAKE)" -f  "21-04-window.mk" clean
