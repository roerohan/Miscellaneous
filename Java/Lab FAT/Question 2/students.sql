CREATE TABLE IF NOT EXISTS `students` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `registration_number` varchar(255) NOT NULL UNIQUE,
  PRIMARY KEY (`id`)
);

INSERT INTO `students` (`id`, `name`, `email`, `registration_number`) VALUES (1, 'John Doe', 'johndoe@gmail.com', '18BCE0221');
INSERT INTO `students` (`id`, `name`, `email`, `registration_number`) VALUES (2, 'Sam Hill', 'samhill@gmail.com', '18BCE0231');
INSERT INTO `students` (`id`, `name`, `email`, `registration_number`) VALUES (3, 'Anna Smith', 'annasmith@gmail.com', '18BCE0234');
INSERT INTO `students` (`id`, `name`, `email`, `registration_number`) VALUES (4, 'Joe Harvey', 'joeharvey@gmail.com', '18BCE0250');
INSERT INTO `students` (`id`, `name`, `email`, `registration_number`) VALUES (5, 'Carl Johnson', 'carljohnson@gmail.com', '18BCE0321');
