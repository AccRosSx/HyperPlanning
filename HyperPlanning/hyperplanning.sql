SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

CREATE DATABASE IF NOT EXISTS `hyperplanning` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `hyperplanning`;

CREATE TABLE `formateurs` (
  `idFormateur` int(11) NOT NULL,
  `nom` varchar(20) DEFAULT NULL,
  `prenom` varchar(20) DEFAULT NULL,
  `idMatiere` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `formateurs` (`idFormateur`, `nom`, `prenom`, `idMatiere`) VALUES
(1, 'LAHLOU', 'Abdelkrim', 1),
(3, 'VELIKSON', 'Boris', 2),
(4, 'BARBOT', 'Hervé', 3),
(5, 'ACHVAR', 'Didier', 5);

CREATE TABLE `groupes` (
  `idGroupe` int(11) NOT NULL,
  `idFormateur` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `groupes` (`idGroupe`, `idFormateur`) VALUES
(1, 1),
(2, 3),
(3, 4),
(4, 5);

CREATE TABLE `log` (
  `usr` varchar(20) DEFAULT NULL,
  `pwd` varchar(20) DEFAULT NULL,
  `id` int(11) DEFAULT NULL,
  `acces` enum('1','2','3','4') DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

INSERT INTO `log` (`usr`, `pwd`, `id`, `acces`) VALUES
('nb', '123', 1, '1'),
('al', '123', 1, '2'),
('bv', '123', 3, '2'),
('bh', '123', 4, '2'),
('ad', '123', 5, '3'),
('admin', 'admin', 0, '4');

CREATE TABLE `matieres` (
  `idMatiere` int(11) NOT NULL,
  `nom` varchar(100) DEFAULT NULL,
  `volumeHoraire` int(11) DEFAULT NULL,
  `type` enum('TP','TD','Amphi') DEFAULT NULL,
  `dureeExamen` enum('0','1','2') DEFAULT NULL,
  `dateRattrapage` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `matieres` (`idMatiere`, `nom`, `volumeHoraire`, `type`, `dureeExamen`, `dateRattrapage`) VALUES
(1, 'C/C++', 2, 'TP', '1', '2019-07-01'),
(2, 'Mathématiques pour L\'informatique', 52, 'TD', '2', '2019-07-01'),
(3, 'Théorie des Graphes', 52, 'TD', '2', '2019-07-01'),
(5, 'Théorie du Signal', 52, 'TP', '1', '2019-07-01');

CREATE TABLE `reservations` (
  `idReservation` int(11) NOT NULL,
  `idSalle` int(11) NOT NULL,
  `idGroupe` int(11) NOT NULL,
  `hDebut` int(11) DEFAULT NULL,
  `hFin` int(11) DEFAULT NULL,
  `dateJour` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `reservations` (`idReservation`, `idSalle`, `idGroupe`, `hDebut`, `hFin`, `dateJour`) VALUES
(1, 1, 1, 8, 10, '2018-10-08'),
(2, 2, 2, 10, 12, '2018-10-08'),
(6, 2, 2, 8, 10, '2018-10-22'),
(10, 2, 2, 10, 12, '2018-10-23');

CREATE TABLE `salles` (
  `idSalle` int(11) NOT NULL,
  `type` enum('TP','TD','Amphi') DEFAULT NULL,
  `nbPlaces` int(11) DEFAULT '20'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `salles` (`idSalle`, `type`, `nbPlaces`) VALUES
(1, 'TP', 20),
(2, 'TD', 20),
(3, 'TD', 0);

CREATE TABLE `stagiaires` (
  `idMatricule` int(11) NOT NULL,
  `nom` varchar(30) DEFAULT NULL,
  `prenom` varchar(30) DEFAULT NULL,
  `dateNaissance` date DEFAULT NULL,
  `dateTs` datetime DEFAULT CURRENT_TIMESTAMP,
  `dateInscription` date AS (cast(dateTs as date)) VIRTUAL,
  `sexe` enum('H','F') DEFAULT NULL,
  `numeroRue` varchar(5) DEFAULT NULL,
  `nomRue` varchar(50) DEFAULT NULL,
  `codePostal` varchar(10) DEFAULT NULL,
  `nomVille` varchar(30) DEFAULT NULL,
  `numeroDom` char(10) DEFAULT NULL,
  `numeroMob` char(10) DEFAULT NULL,
  `idGroupe1` int(11) DEFAULT '0',
  `idGroupe2` int(11) DEFAULT '0',
  `idGroupe3` int(11) DEFAULT '0',
  `idGroupe4` int(11) DEFAULT '0',
  `idGroupe5` int(11) DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `stagiaires` (`idMatricule`, `nom`, `prenom`, `dateNaissance`, `dateTs`, `sexe`, `numeroRue`, `nomRue`, `codePostal`, `nomVille`, `numeroDom`, `numeroMob`, `idGroupe1`, `idGroupe2`, `idGroupe3`, `idGroupe4`, `idGroupe5`) VALUES
(1, 'BENCHIMOL', 'NICOLAS', '1999-03-16', '2018-10-04 20:15:40', 'H', '135', 'Rue de Neuilly', '93250', 'Villemomble', '0123456789', '0123456789', 1, 2, 0, 0, 0),
(2, 'BEZAIN', 'Alexandre', '1998-09-15', '2018-10-12 20:36:13', 'H', NULL, NULL, NULL, NULL, NULL, NULL, 1, 2, 0, 0, 0),
(3, 'SRICHUTHESGARAN', 'Birintha', '1998-02-22', '2018-10-13 20:07:56', 'F', NULL, NULL, NULL, NULL, NULL, NULL, 1, 0, 3, 0, 0);


ALTER TABLE `formateurs`
  ADD PRIMARY KEY (`idFormateur`),
  ADD KEY `fk_idMatiere` (`idMatiere`);

ALTER TABLE `groupes`
  ADD PRIMARY KEY (`idGroupe`),
  ADD KEY `fk_idFormateur` (`idFormateur`);

ALTER TABLE `matieres`
  ADD PRIMARY KEY (`idMatiere`);

ALTER TABLE `reservations`
  ADD PRIMARY KEY (`idReservation`),
  ADD KEY `idGroupe` (`idGroupe`),
  ADD KEY `dateJour` (`dateJour`),
  ADD KEY `idSalle` (`idSalle`);

ALTER TABLE `salles`
  ADD PRIMARY KEY (`idSalle`);

ALTER TABLE `stagiaires`
  ADD PRIMARY KEY (`idMatricule`);


ALTER TABLE `formateurs`
  MODIFY `idFormateur` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

ALTER TABLE `groupes`
  MODIFY `idGroupe` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

ALTER TABLE `matieres`
  MODIFY `idMatiere` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

ALTER TABLE `reservations`
  MODIFY `idReservation` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

ALTER TABLE `salles`
  MODIFY `idSalle` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

ALTER TABLE `stagiaires`
  MODIFY `idMatricule` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;


ALTER TABLE `formateurs`
  ADD CONSTRAINT `fk_idMatiere` FOREIGN KEY (`idMatiere`) REFERENCES `matieres` (`idmatiere`);

ALTER TABLE `groupes`
  ADD CONSTRAINT `fk_idFormateur` FOREIGN KEY (`idFormateur`) REFERENCES `formateurs` (`idFormateur`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
