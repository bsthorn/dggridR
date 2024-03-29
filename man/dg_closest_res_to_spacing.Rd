% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/dggridR.R
\name{dg_closest_res_to_spacing}
\alias{dg_closest_res_to_spacing}
\title{Determine grid resolution from desired spacing.}
\usage{
dg_closest_res_to_spacing(
  dggs,
  spacing,
  round = "nearest",
  show_info = TRUE,
  metric = TRUE
)
}
\arguments{
\item{dggs}{A dggs object from dgconstruct()}

\item{spacing}{The desired spacing between the center of adjacent cells}

\item{round}{What direction to search in. Must be nearest, up, or down.}

\item{show_info}{Print the area, spacing, and CLS of the chosen resolution.}

\item{metric}{Whether input and output should be in metric (TRUE) or
imperial (FALSE)}
}
\value{
A number representing the grid resolution
}
\description{
Determine an appropriate grid resolution based on a desired
                 spacing between the center of adjacent cells.
}
\examples{
library(dggridR)
dggs <- dgconstruct(res=20)
res  <- dg_closest_res_to_spacing(dggs,1)
dggs <- dgsetres(dggs,res)
}
