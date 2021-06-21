all: ./philo/philo ./philo_bonus./philo_bonus

./philo/philo :
	@make -C ./philo/

./philo_bonus./philo_bonus :
	@make -C ./philo_bonus/

clean :
	@make clean -C ./philo/
	@make clean -C ./philo_bonus/

fclean :
	@make fclean -C ./philo/
	@make fclean -C ./philo_bonus/

re :
	@make re -C ./philo/
	@make re -C ./philo_bonus/
