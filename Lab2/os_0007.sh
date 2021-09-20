if [ "$1" = "" ]; then
	echo parameter not found
	exit
else
	if ! [[ "$1" =~ ^[[:digit:]]+$ ]];
	then
		echo pid = $1 not int
		exit
	fi
	if ps -p $1 > /dev/null
	then
		echo -n Name:
		ps -p $1 -o comm=
		echo Pid: $1
		echo -n PPid:
		ps -o ppid= -p $1

		if [ "$2" = "fd" ]; then
			ls -1 /proc/$1/fd
		fi
	else
		echo pid = $1 not found
		exit
	fi
fi