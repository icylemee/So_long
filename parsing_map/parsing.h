/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:16:52 by mlemee            #+#    #+#             */
/*   Updated: 2025/06/16 18:33:43 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

char	**ft_parse(char *filename);
int		ft_check_zero(char *filename);
int		ft_check_pce(char *filename);
int		ft_check_len(char **split);
int		ft_check_columns(char **split);
int		ft_check_first_n_last(char **split, int nlines);
int		ft_count_line(char **split);
int		ft_find_player_y(char **split);
int		ft_find_player_x(char **split);
char	**parse_ff(char **split, int x, int y, char *filename);
void	flood_fill(char **copymap, int x, int y, int *countcpe);
void	ft_verif_split(char **split);
int		ft_case_valide(char c, int *countcpe);
char	**ft_free_split(char **split);
char	*ft_read(char *filename);

#endif