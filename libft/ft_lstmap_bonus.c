/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:47:25 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/18 15:00:39 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*ref;
	t_list	*first;

	if (!lst || !f || !del)
		return (NULL);
	first = ft_lstnew(f(lst -> content));
	if (!first)
		return (NULL);
	ref = first;
	lst = lst -> next;
	while (lst)
	{
		new = ft_lstnew(f(lst -> content));
		if (!new)
		{
			del(new->content);
			ft_lstclear(&ref, del);
			return (NULL);
		}
		ft_lstadd_back(&ref, new);
		lst = lst -> next;
	}
	return (ref);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h" 

// Fonction qui sera utilisée pour transformer le contenu de chaque nœud
void *transform_content(void *content)
{
    char *str = (char *)content;
    char *new_str = strdup(str);
    
    // Transforme tous les caractères en majuscules
    for (int i = 0; new_str[i]; i++)
        if (new_str[i] >= 'a' && new_str[i] <= 'z')
            new_str[i] = new_str[i] - 32;
    
    return new_str;
}

// Fonction pour libérer le contenu d'un nœud
void delete_content(void *content)
{
    free(content);
}

// Fonction pour afficher le contenu d'une liste
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main(void)
{
    // Création de la liste originale
    t_list *lst = NULL;
    t_list *new_node;
    
    // Ajout de quelques éléments
    new_node = ft_lstnew(strdup("hello"));
    ft_lstadd_back(&lst, new_node);
    
    new_node = ft_lstnew(strdup("world"));
    ft_lstadd_back(&lst, new_node);
    
    new_node = ft_lstnew(strdup("42"));
    ft_lstadd_back(&lst, new_node);
    
    // Affichage de la liste originale
    printf("Liste originale : ");
    print_list(lst);
    
    // Application de ft_lstmap
    t_list *mapped_lst = ft_lstmap(lst, transform_content, delete_content);
    
    // Affichage de la nouvelle liste
    printf("Liste transformée : ");
    print_list(mapped_lst);
    
    // Nettoyage de la mémoire
    ft_lstclear(&lst, delete_content);
    ft_lstclear(&mapped_lst, delete_content);
    
    return 0;
}*/
