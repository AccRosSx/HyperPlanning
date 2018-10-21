-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost:3306
-- Généré le :  Dim 21 oct. 2018 à 23:22
-- Version du serveur :  10.0.36-MariaDB-0+deb8u1
-- Version de PHP :  7.1.14

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `bibiphzc_`
--

-- --------------------------------------------------------

--
-- Structure de la table `compogrpmatiere`
--

CREATE TABLE `compogrpmatiere` (
  `idMatiere` int(2) NOT NULL,
  `idGroupe` int(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `cours`
--

CREATE TABLE `cours` (
  `id` int(11) NOT NULL,
  `dureeCours` float NOT NULL,
  `idMatiere` int(3) NOT NULL,
  `idProfesseur` int(3) NOT NULL,
  `idSalle` int(2) NOT NULL,
  `idGroupe` int(2) NOT NULL,
  `dateCours` varchar(10) NOT NULL,
  `heureDebut` varchar(5) NOT NULL,
  `heureFin` varchar(5) NOT NULL,
  `typeCours` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `cours`
--

INSERT INTO `cours` (`id`, `dureeCours`, `idMatiere`, `idProfesseur`, `idSalle`, `idGroupe`, `dateCours`, `heureDebut`, `heureFin`, `typeCours`) VALUES
(1, 1, 1, 1, 1, 1, '13/10/2018', '8', '9', 'Amphi'),
(4, 1, 2, 1, 1, 1, '15/10/2018', '9', '10', 'Amphi'),
(5, 1, 3, 1, 1, 1, '15/10/2018', '8', '9', 'Amphi');

-- --------------------------------------------------------

--
-- Structure de la table `groupe`
--

CREATE TABLE `groupe` (
  `id` int(2) NOT NULL,
  `tailleMax` int(2) NOT NULL,
  `nomGroupe` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `groupe`
--

INSERT INTO `groupe` (`id`, `tailleMax`, `nomGroupe`) VALUES
(1, 10, 'LSI');

-- --------------------------------------------------------

--
-- Structure de la table `matiere`
--

CREATE TABLE `matiere` (
  `id` int(11) NOT NULL,
  `nbHeureTD` float NOT NULL,
  `nbHeureTP` float NOT NULL,
  `nbHeureProjet` float NOT NULL,
  `nbHeureAmphi` float NOT NULL,
  `nom` varchar(30) NOT NULL,
  `idEnseignant` int(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `matiere`
--

INSERT INTO `matiere` (`id`, `nbHeureTD`, `nbHeureTP`, `nbHeureProjet`, `nbHeureAmphi`, `nom`, `idEnseignant`) VALUES
(1, 10, 5, 10, 20, 'Maths', 1),
(2, 10, 5, 5, 20, 'Physique', 1),
(3, 10, 5, 10, 20, 'C++', 2);

-- --------------------------------------------------------

--
-- Structure de la table `personne`
--

CREATE TABLE `personne` (
  `id` int(5) NOT NULL,
  `mdp` varchar(30) NOT NULL,
  `role` int(1) NOT NULL,
  `matricule` varchar(8) NOT NULL,
  `nom` varchar(30) NOT NULL,
  `prenom` varchar(30) NOT NULL,
  `telDomicile` varchar(10) NOT NULL,
  `telPortable` varchar(10) NOT NULL,
  `nomRue` varchar(50) NOT NULL,
  `numRue` varchar(10) NOT NULL,
  `codeP` int(5) NOT NULL,
  `ville` varchar(30) NOT NULL,
  `dteNaissance` varchar(10) NOT NULL,
  `dteinscription` varchar(10) NOT NULL,
  `sexe` char(1) NOT NULL,
  `idGroupe` int(5) NOT NULL,
  `idMatiere` int(3) NOT NULL,
  `nbHeureMax` int(2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `personne`
--

INSERT INTO `personne` (`id`, `mdp`, `role`, `matricule`, `nom`, `prenom`, `telDomicile`, `telPortable`, `nomRue`, `numRue`, `codeP`, `ville`, `dteNaissance`, `dteinscription`, `sexe`, `idGroupe`, `idMatiere`, `nbHeureMax`) VALUES
(1, '', 1, 'Achvar1', 'Achvar', 'Didier', '', '', '', '', 0, '', '00/00/00', '', 'M', 1, 0, 45),
(2, '', 1, 'Karim2', 'Karim', 'Lahlou', '', '', '', '', 0, '', '00/00/00', '', 'M', 0, 0, 40),
(3, '', 0, '20180003', 'srichuthesgaran', 'birintha', '0160431601', '0651058671', 'du clos du village', '14', 77700, 'Serris', '22/02/1998', '2018', 'F', 1, 0, 0);

-- --------------------------------------------------------

--
-- Structure de la table `salle`
--

CREATE TABLE `salle` (
  `id` int(11) NOT NULL,
  `nbPlaces` int(3) NOT NULL,
  `batiment` varchar(1) NOT NULL,
  `numeroSalle` int(2) NOT NULL,
  `typeSalle` varchar(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `salle`
--

INSERT INTO `salle` (`id`, `nbPlaces`, `batiment`, `numeroSalle`, `typeSalle`) VALUES
(1, 10, 'A', 12, 'Amphi');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `cours`
--
ALTER TABLE `cours`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `groupe`
--
ALTER TABLE `groupe`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `matiere`
--
ALTER TABLE `matiere`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `personne`
--
ALTER TABLE `personne`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `salle`
--
ALTER TABLE `salle`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `cours`
--
ALTER TABLE `cours`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT pour la table `groupe`
--
ALTER TABLE `groupe`
  MODIFY `id` int(2) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT pour la table `matiere`
--
ALTER TABLE `matiere`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pour la table `personne`
--
ALTER TABLE `personne`
  MODIFY `id` int(5) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pour la table `salle`
--
ALTER TABLE `salle`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
