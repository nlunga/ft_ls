/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlunga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 08:39:20 by nlunga            #+#    #+#             */
/*   Updated: 2019/07/12 10:25:46 by nlunga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_libft/ft_libft.h"

int	main(void)
{
	//--- Masks ---//
	
	int vote = 1 << 0; // 1
	int add = 1 << 1; // 2
	int remove = 1 << 2; // 4
	int manage = 1 << 3; // 8
	int comment = 1 << 4; // 16
	int publish = 1 << 25; // 33554432

	//--- Sets ---//
	
	int user1 = vote | remove | manage; // can "vote", "remove", "manage"
	int user2 = user1 | publish; // all `user1` plus "publish"
	int user3 = user2 ^ manage; // all `user2` minus "manage"

	//--- Matches --->
	
	printf("USER 1 : %d\n", user1); // 13

	printf("%d\n", (user1 & vote)); // 1 : TRUE
	printf("%d\n", (user1 & add)); // 0 : FALSE
	printf("%d\n", (user1 & remove)); // 4 : TRUE
	printf("%d\n", (user1 & manage)); // 8 : TRUE
	printf("%d\n", (user1 & comment)); // 0 : FALSE
	printf("%d\n", (user1 & publish)); // 0 : FALSE

	printf("USER 2 : %d\n", user2); // 33554445

	printf("%d\n", (user2 & vote)); // 1 : TRUE
	printf("%d\n", (user2 & add)); // 0 : FALSE
	printf("%d\n", (user2 & remove)); // 4 : TRUE
	printf("%d\n", (user2 & manage)); // 8 : TRUE
	printf("%d\n", (user2 & comment)); // 0 : FALSE
	printf("%d\n", (user2 & publish)); // 33554432 : TRUE
	
	printf("USER 3 : %d\n", user3); // 33554437

	printf("%d\n", (user3 & vote)); // 1 : TRUE
	printf("%d\n", (user3 & add)); // 0 : FALSE
	printf("%d\n", (user3 & remove)); // 4 : TRUE
	printf("%d\n", (user3 & manage)); // 0 : FALSE
	printf("%d\n", (user3 & comment)); // 0 : FALSE
	printf("%d\n", (user3 & publish)); // 33554432 : TRUE
	return (0);
}
