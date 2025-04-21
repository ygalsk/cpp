# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkremer <dkremer@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 16:02:58 by dkremer           #+#    #+#              #
#    Updated: 2025/04/20 12:37:55 by dkremer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = rpn

# Compiler and flags
CXX       = c++
CXXFLAGS  = -Wall -Werror -Wextra -g -std=c++17

# Include directories
INCLUDES  = -I./inc

# Source directory and Binary folder
SRCDIR    = src
BINDIR    = bin

# Source files and Object files (place objects under BINDIR)
SRCS      = $(wildcard $(SRCDIR)/*.cpp)
OBJS      = $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%.o,$(SRCS))

# Default target
all: $(NAME)

# Link objects to create the final binary
$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo $(GREEN)"Building $(NAME)"$(DEFAULT)
	
# Create bin directories if they don't exist
$(BINDIR):
	@mkdir -p $(BINDIR)

# Compile .cpp files into .o files
$(BINDIR)/%.o: $(SRCDIR)/%.cpp | $(BINDIR)
	@mkdir -p $(dir $@)  # Ensure subdirectories are created
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean object files and binary
clean:
	@rm -rf $(BINDIR)
	@echo $(RED)"Removing object files"$(DEFAULT)

# Clean everything, including the binary
fclean: clean
	@rm -f $(NAME)
	@echo $(RED)"Removing $(NAME)"$(DEFAULT)

# Rebuild everything
re: fclean all
	@echo $(GREEN)"Rebuilding everything"$(DEFAULT)

# Colors for output
DEFAULT   = "\033[39m"
GREEN     = "\033[32m"
RED       = "\033[31m"

.PHONY: all clean fclean re
