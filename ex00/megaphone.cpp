/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:40:07 by baouragh          #+#    #+#             */
/*   Updated: 2024/10/25 18:12:51 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ios>
#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < ac ; i++)
    {
        for (int j = 0 ; av[i][j]; j++)
            std::cout << (char)toupper(av[i][j]);
    }
    std::cout << std::endl;
    return (0);
}