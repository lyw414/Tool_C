include $(Rul)
basic:
	cd $(Src)/Log/src/ && make all
	cd $(Src)/Algorithm/List/src/ && make all
	cd $(Src)/Algorithm/FixedLengthList/src/ && make all 
all:

clean:
	cd $(Src)/Log/src/ && make clean
	cd $(Src)/Algorithm/List/src/ && make clean
	cd $(Src)/Algorithm/FixedLengthList/src/ && make clean
