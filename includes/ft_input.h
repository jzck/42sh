/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 02:05:22 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/14 13:50:33 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INPUT_H
# define FT_INPUT_H

/*
 * Input code mapping (!!!!LINUX!!!!)
 * TODO Same for MACOSX
*/

# ifdef LINUX
#  define RL_INSERT_CODE 0x7e325b1b					/* Insert */
#  define RL_CLEAR_CODE 0xc							/* Ctrl+L */
#  define RL_NL_CODE 0xa							/* Enter */
#  define RL_COMP_CODE 0x9							/* Tab */
#  define RL_LEFT_CODE 0x445b1b						/* Left */
#  define RL_RIGHT_CODE 0x435b1b					/* Right */
#  define RL_WLEFT_CODE 0x44323b315b1b				/* Maj+Left */
#  define RL_WRIGHT_CODE 0x43323b315b1b				/* Maj+Right */
#  define RL_HOME_CODE 0x485b1b						/* Home */
#  define RL_END_CODE 0x465b1b						/* End */
#  define RL_PAGEUP_CODE 0x7e355b1b					/* PageUp */
#  define RL_PAGEDOWN_CODE 0x7e365b1b				/* PageDown */
#  define RL_SELECT_RIGHT_CODE 0x43333b315b1b		/* Alt+Right */
#  define RL_SELECT_LEFT_CODE 0x44333b315b1b		/* Alt+Left */
#  define RL_SELECT_PAGEUP_CODE 0x7e333b355b1b		/* Alt+PageUp */
#  define RL_SELECT_PAGEDOWN_CODE 0x7e333b365b1b	/* Alt+PageDown */
#  define RL_SELECT_HOME_CODE 0x48333b315b1b		/* Alt+Home */
#  define RL_SELECT_END_CODE 0x46333b315b1b			/* Alt+End */
#  define RL_SELECT_WRIGHT_CODE 0x43343b315b1b		/* Alt+Maj+Right */
#  define RL_SELECT_WLEFT_CODE 0x44343b315b1b		/* Alt+Maj+Left */
#  define RL_RETARR_CODE 0x7f						/* RetArr */
#  define RL_SUPPR_CODE 0x7e335b1b					/* Suppr */
#  define RL_ESC_CODE 0x5c							/* Escape `\` */
#  define RL_QUOTE_CODE 0x27						/* Quote `'` */
#  define RL_DQUOTE_CODE 0x22						/* Double Quote `"` */
#  define RL_COPY_CODE 0x631b						/* Alt+C */
#  define RL_CUT_CODE 0x781b						/* Alt+X */
#  define RL_PASTE_CODE 0x761b						/* Alt+V */
# endif

# ifdef MACOSX
#  define RL_INSERT_CODE 0x53323b315b1b
#  define RL_CLEAR_CODE 0xc
#  define RL_NL_CODE 0xa
#  define RL_COMP_CODE 0x9
#  define RL_LEFT_CODE 0x445b1b
#  define RL_RIGHT_CODE 0x435b1b
#  define RL_WLEFT_CODE 0x44323b315b1b
#  define RL_WRIGHT_CODE 0x43323b315b1b
#  define RL_HOME_CODE 0x485b1b
#  define RL_END_CODE 0x465b1b
#  define RL_PAGEUP_CODE 0x7e355b1b
#  define RL_PAGEDOWN_CODE 0x7e365b1b
#  define RL_SELECT_RIGHT_CODE 0x435b1b1b
#  define RL_SELECT_LEFT_CODE 0x445b1b1b
#  define RL_SELECT_PAGEUP_CODE 0x7e355b1b1b
#  define RL_SELECT_PAGEDOWN_CODE 0x7e365b1b1b
#  define RL_SELECT_HOME_CODE 0X48393b315b1b
#  define RL_SELECT_END_CODE 0X46393b315b1b
#  define RL_SELECT_WRIGHT_CODE 0x4330313b315b1b
#  define RL_SELECT_WLEFT_CODE 0x4430313b315b1b
#  define RL_RETARR_CODE 0x7f
#  define RL_SUPPR_CODE 0x7e335b1b
#  define RL_ESC_CODE 0x5c
#  define RL_QUOTE_CODE 0x27
#  define RL_DQUOTE_CODE 0x22
#  define RL_COPY_CODE 0xa7c3
#  define RL_CUT_CODE 0x8889e2
#  define RL_PASTE_CODE 0x9a88e2
# endif

#endif
