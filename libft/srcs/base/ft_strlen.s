/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:47:13 by vkovsh            #+#    #+#             */
/*   Updated: 2017/12/04 14:46:44 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*.code32
.globl ft_strlen
ft_strlen:
       ; pushl %ebp
        ;movl  %esp, %ebp

        pushl %edi

        movl  8(%ebp), %edi

        movl  $0xffffffff, %ecx
        xorl  %eax, %eax

        repne scasb

        notl  %ecx
        decl  %ecx

        movl  %ecx, %eax

        popl  %edi

        ;movl  %ebp, %esp
       ;popl  %ebp
        ret

/*#include <string.h>

size_t		ft_strlen(const char *s)
{
	size_t	start;

	start = (size_t)s;
	while (*s++)
		;
	return ((size_t)s - start - 1);
}*/
