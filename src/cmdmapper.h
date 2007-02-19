/******************************************************************************
 *
 * 
 *
 *
 * Copyright (C) 1997-2007 by Dimitri van Heesch.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby 
 * granted. No representations are made about the suitability of this software 
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 * Documents produced by Doxygen are derivative works derived from the
 * input used in their production; they are not affected by this license.
 *
 */

#ifndef _CMDMAPPER_H
#define _CMDMAPPER_H

#include <qdict.h>

struct CommandMap
{
  const char *cmdName;
  int cmdId;
};

const int SIMPLESECT_BIT = 0x1000;

enum CommandType
{
  CMD_UNKNOWN      = 0,
  CMD_ADDINDEX     = 1,   
  CMD_AMP          = 2,
  CMD_ANCHOR       = 3,  
  CMD_AT           = 4,
  CMD_ATTENTION    = 5  | SIMPLESECT_BIT,
  CMD_AUTHOR       = 6  | SIMPLESECT_BIT,
  CMD_AUTHORS      = 7  | SIMPLESECT_BIT,
  CMD_BOLD         = 8,
  CMD_BSLASH       = 9,
  CMD_CODE         = 10,
  CMD_COPYDOC      = 11,      
  CMD_DATE         = 12 | SIMPLESECT_BIT,
  CMD_DOLLAR       = 13,
  CMD_DONTINCLUDE  = 14,   
  CMD_DOTFILE      = 15,      
  CMD_EMPHASIS     = 16,
  CMD_ENDCODE      = 17,      
  CMD_ENDHTMLONLY  = 18,  
  CMD_ENDLATEXONLY = 19, 
  CMD_ENDLINK      = 20,      
  CMD_ENDSECREFLIST= 21,
  CMD_ENDVERBATIM  = 22, 
  CMD_ENDXMLONLY   = 23,
  CMD_EXCEPTION    = 24 | SIMPLESECT_BIT,
  CMD_FORMULA      = 25,
  CMD_GREATER      = 26,
  CMD_HASH         = 27,
  CMD_HTMLINCLUDE  = 28,
  CMD_HTMLONLY     = 29,
  CMD_IMAGE        = 30,           
  CMD_INCLUDE      = 31,
  CMD_INTERNAL     = 32,         
  CMD_INTERNALREF  = 33,
  CMD_INVARIANT    = 34 | SIMPLESECT_BIT ,
  CMD_LATEXONLY    = 35,
  CMD_LESS         = 36,
  CMD_LI           = 37,
  CMD_LINE         = 38,
  CMD_LINEBREAK    = 39,
  CMD_LINK         = 40,             
  CMD_NOTE         = 41 | SIMPLESECT_BIT,
  CMD_PAR          = 42 | SIMPLESECT_BIT,
  CMD_PARAM        = 43 | SIMPLESECT_BIT,
  CMD_PERCENT      = 44, 
  CMD_POST         = 45 | SIMPLESECT_BIT,
  CMD_PRE          = 46 | SIMPLESECT_BIT ,
  CMD_REF          = 47,
  CMD_SECREFITEM   = 48,
  CMD_REMARK       = 49 | SIMPLESECT_BIT ,
  CMD_RETURN       = 50 | SIMPLESECT_BIT ,
  CMD_RETVAL       = 51 | SIMPLESECT_BIT,
  CMD_SA           = 52 | SIMPLESECT_BIT ,
  CMD_SECREFLIST   = 53,
  CMD_SECTION      = 54,
  CMD_SUBPAGE      = 55,
  CMD_SUBSECTION   = 56,
  CMD_SUBSUBSECTION= 57,
  CMD_PARAGRAPH    = 58,
  CMD_SINCE        = 59 | SIMPLESECT_BIT,
  CMD_SKIP         = 60,
  CMD_SKIPLINE     = 61,
  CMD_STARTCODE    = 62,
  CMD_JAVALINK     = 63,
  CMD_UNTIL        = 64,
  CMD_VERBATIM     = 65,
  CMD_VERBINCLUDE  = 66,
  CMD_VERSION      = 67 | SIMPLESECT_BIT,
  CMD_WARNING      = 68 | SIMPLESECT_BIT,
  CMD_XREFITEM     = 69 | SIMPLESECT_BIT,
  CMD_XMLONLY      = 70,
  CMD_DOT          = 71,
  CMD_ENDDOT       = 72,
  CMD_MANONLY      = 73,
  CMD_ENDMANONLY   = 74,
  CMD_INCWITHLINES = 75,
  CMD_INHERITDOC   = 76
};

enum HtmlTagType
{
  HTML_UNKNOWN   = 0,
  HTML_CENTER    = 1,
  HTML_TABLE     = 2,
  HTML_CAPTION   = 3,
  HTML_SMALL     = 4,
  HTML_CODE      = 5,
  HTML_IMG       = 6,
  HTML_PRE       = 7,
  HTML_SUB       = 8,
  HTML_SUP       = 9,
  HTML_TR        = 10,
  HTML_TD        = 11,
  HTML_TH        = 12,
  HTML_OL        = 13,
  HTML_UL        = 14,
  HTML_LI        = 15,
  HTML_EMPHASIS  = 16,
  HTML_HR        = 17,
  HTML_DL        = 18,
  HTML_DT        = 19,
  HTML_DD        = 20,
  HTML_BR        = 21,
  HTML_A         = 22,
  HTML_BOLD      = 23,
  HTML_P         = 24,
  HTML_H1        = 25,
  HTML_H2        = 26,
  HTML_H3        = 27,
  HTML_H4        = 28,
  HTML_H5        = 29,
  HTML_H6        = 30,
  HTML_SPAN      = 31,
  HTML_DIV       = 32,

  XML_CmdMask    = 0x100,

  XML_C          = XML_CmdMask + 0,
  XML_CODE       = XML_CmdMask + 1,
  XML_DESCRIPTION= XML_CmdMask + 2,
  XML_EXAMPLE    = XML_CmdMask + 3,
  XML_EXCEPTION  = XML_CmdMask + 4,
  XML_INCLUDE    = XML_CmdMask + 5,
  XML_ITEM       = XML_CmdMask + 6,
  XML_LIST       = XML_CmdMask + 7,
  XML_PARA       = XML_CmdMask + 8,
  XML_PARAM      = XML_CmdMask + 9,
  XML_PARAMREF   = XML_CmdMask + 10,
  XML_PERMISSION = XML_CmdMask + 11,
  XML_REMARKS    = XML_CmdMask + 12,
  XML_RETURNS    = XML_CmdMask + 13,
  XML_SEE        = XML_CmdMask + 14,
  XML_SEEALSO    = XML_CmdMask + 15,
  XML_SUMMARY    = XML_CmdMask + 16,
  XML_VALUE      = XML_CmdMask + 17

};

class Mapper
{
  public:
    int map(const char *n)
    {
      QCString name=n;
      int *result;
      return !name.isEmpty() && (result=m_map.find(name.lower())) ? *result: 0;
    }

    Mapper(const CommandMap *cm) : m_map(89)
    {
      m_map.setAutoDelete(TRUE);
      const CommandMap *p = cm;
      while (p->cmdName)
      {
        m_map.insert(p->cmdName,new int(p->cmdId));
        p++;
      }
    }
  private:
    QDict<int> m_map;
};

struct Mappers
{
  static void freeMappers();
  static Mapper *cmdMapper;
  static Mapper *htmlTagMapper;
};


#endif
