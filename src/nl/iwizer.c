/*
 
 Brain Rarely Accepts Incoherent Nonsense (BRAIN)
 Copyright 2012-2013 Joshua Hawcroft
 
 This file is part of BRAIN.
 
 BRAIN is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 BRAIN is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with BRAIN.  If not, see <http://www.gnu.org/licenses/>.
 
 */
/* input nl word-concept lookup */

#include "common.h"


/* TODO: supposed to be using plugin wordizer;
 decide if this is necessary and if it isn't, then get rid of that plugin interface */


int nl_wordize(NLInput *in_input, NLWordizer *in_wordizer)
{
    for (int s = 0; s < array_count(in_input->sentences); s++)
    {
        NLSentence *sentence = array_item(in_input->sentences, s);
        for (int t = 0; t < sentence->token_count; t++)
        {
            NLToken *token = sentence->tokens[t];
            if (token->flags & NL_TOKFLG_TEXT)
                token->concepts = kn_text_to_concept_set(token->characters);
        }
    }
    return NL_OK;
}





