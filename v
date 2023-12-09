ARG=`cat $1`; valgrind --leak-check=full -s ./push_swap "$ARG" | valgrind --leak-check=full ./checker "$ARG"
