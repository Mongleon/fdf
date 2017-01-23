NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2
RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

all: $(NOM)

$(NOM):	$(OBJ)
	@ar rc $(NOM) $(OBJ)
	@ranlib $(NOM)
	@echo "$(GREEN)[✓]$(NC) library $@ built"

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.m
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app
	@echo "$(RED)[-]$(NC) Objects of $(NOM) cleaned"

re: clean all
