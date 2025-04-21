all: teste

run: teste
	./teste

teste: chocolate.o vinho.o livro.o filme.o produto.o lista.o main.o
	@gcc -o teste chocolate.o vinho.o livro.o filme.o produto.o lista.o main.o -g

chocolate.o: chocolate.c chocolate.h
	@gcc -c chocolate.c -Wall -Werror -Wextra -g

vinho.o: vinho.c vinho.h
	@gcc -c vinho.c -Wall -Werror -Wextra -g

livro.o: livro.c livro.h
	@gcc -c livro.c -Wall -Werror -Wextra -g

filme.o: filme.c filme.h
	@gcc -c filme.c -Wall -Werror -Wextra -g

produto.o: produto.c produto.h
	@gcc -c produto.c -Wall -Werror -Wextra -g

lista.o: lista.c lista.h
	@gcc -c lista.c -Wall -Werror -Wextra -g

main.o: main.c chocolate.h vinho.h livro.h filme.h produto.h lista.h
	@gcc -c main.c -Wall -Werror -Wextra -g

clean:
	@rm -rf *.o teste
