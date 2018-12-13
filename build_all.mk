include $(Rul)
all:
	cd $(Src)/Log/src/ && make all
	cd $(Src)/Algorithm/List/src/ && make all
clean:
	cd $(Src)/Log/src/ && make clean
	cd $(Src)/Algorithm/List/src/ && make clean
