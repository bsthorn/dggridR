/*******************************************************************************
    Copyright (C) 2021 Kevin Sahr

    This file is part of DGGRID.

    DGGRID is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    DGGRID is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*******************************************************************************/
////////////////////////////////////////////////////////////////////////////////
//
// DgOutPRCellsFile.h: DgOutRandPtsText class definitions
//
// Version 7.0 - Kevin Sahr, 12/14/14
//
////////////////////////////////////////////////////////////////////////////////

#ifndef DGOUTPRCELLSFILE_H
#define DGOUTPRCELLSFILE_H

#include "DgOutLocTextFile.h"

#include <cstdio>

class DgDVec2D;
class DgPolygon;

////////////////////////////////////////////////////////////////////////////////
class DgOutPRCellsFile : public DgOutLocTextFile {

   using DgOutLocFile::insert;

   public:

      DgOutPRCellsFile (const DgRFBase& rfIn, const string& fileNameIn = "",
                   int precision = 7, DgReportLevel failLevel = DgBase::Fatal);

      virtual ~DgOutPRCellsFile (void) { if (good()) close(); }

      virtual void close (void) { ofstream::close(); }

      virtual DgOutLocFile& insert (DgLocation& loc, const string* label = NULL);
      virtual DgOutLocFile& insert (DgLocVector& vec, const string* label = NULL,
                                const DgLocation* cent = NULL);
      virtual DgOutLocFile& insert (DgPolygon& poly, const string* label = NULL,
                                const DgLocation* cent = NULL);

   private:

      virtual DgOutLocFile& insert (const DgDVec2D& pt);

      virtual void setFormatStr(void)
      {
          ostringstream os;
          os << " %#." << getPrecision() << "LF, "
             << "%#." << getPrecision() << "LF";

          formatStr_ = os.str();
      }
};

////////////////////////////////////////////////////////////////////////////////

#endif
