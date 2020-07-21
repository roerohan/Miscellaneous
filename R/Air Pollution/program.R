meanpollutant <- function(directory, pollutant, ids = 1:204) {
  currentDir <- paste(getwd(), "/", directory, "/", sep = "")

  files.list <- list.files(currentDir)
  df <- data.frame()
  for (id in ids) {
    df <- rbind(df, read.csv(paste(currentDir, files.list[id], sep = "")))
  }
  mean(df[, pollutant], na.rm = TRUE)
}


listofcomplete <- function(directory, id = 1:204) {
  complete <- function(fname) sum(complete.cases(read.csv(fname)))
  fnames <- list.files(directory, full.names = TRUE)[id]
  data.frame(id = id, nobs = unlist(lapply(fnames, complete)))
}

dirname <- "Airpollution"

print(paste("The mean pollution for nitrate is:", meanpollutant(dirname, "nitrate", 23), sep = " "))

print("The list of completely observed cases between id = 15 and id = 23")
print(listofcomplete(dirname, 15:23))
