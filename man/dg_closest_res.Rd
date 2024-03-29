% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/dggridR.R
\name{dg_closest_res}
\alias{dg_closest_res}
\title{Determine an appropriate grid resolution based on input data.}
\usage{
dg_closest_res(
  dggs,
  col,
  val,
  round = "nearest",
  show_info = TRUE,
  metric = TRUE
)
}
\arguments{
\item{dggs}{A dggs object from dgconstruct()}

\item{col}{Column in which to search for a close value. Should be:
area_km, spacing_km, or cls_km.}

\item{val}{The value to search for}

\item{round}{What direction to search in. Must be nearest, up, or down.}

\item{show_info}{Print the area, spacing, and CLS of the chosen resolution.}

\item{metric}{Whether input and output should be in metric (TRUE) or
imperial (FALSE)}
}
\value{
A number representing the grid resolution
}
\description{
This is a generic function that is used to determine an appropriate
         resolution given an area, cell spacing, or correlated length scale.
         It does so by extracting the appropriate length/area column and
         searching it for a value close to the input.
}
\examples{
library(dggridR)
dggs <- dgconstruct(res=20)
res  <- dg_closest_res(dggs,'area_km',1)
dggs <- dgsetres(dggs,res)
}
