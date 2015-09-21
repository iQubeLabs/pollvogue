-- phpMyAdmin SQL Dump
-- version 4.0.4
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: May 21, 2015 at 11:22 AM
-- Server version: 5.6.12-log
-- PHP Version: 5.4.16

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `pollvogue`
--

-- --------------------------------------------------------

--
-- Table structure for table `imagepoll`
--

CREATE TABLE IF NOT EXISTS `imagepoll` (
  `id` int(33) NOT NULL AUTO_INCREMENT,
  `user_id` int(33) NOT NULL,
  `image` varchar(444) COLLATE ascii_bin NOT NULL,
  `textimage` text COLLATE ascii_bin NOT NULL,
  `image_duration` varchar(233) COLLATE ascii_bin NOT NULL,
  `yes` int(12) NOT NULL,
  `no` int(12) NOT NULL,
  `maybe` int(12) NOT NULL,
  `total` int(12) NOT NULL,
  `poll_titlemage` varchar(233) COLLATE ascii_bin NOT NULL,
  `ratioImage` varchar(66) COLLATE ascii_bin NOT NULL,
  `access_list` text COLLATE ascii_bin NOT NULL,
  `created_at` datetime NOT NULL,
  `updated_at` datetime NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=ascii COLLATE=ascii_bin AUTO_INCREMENT=3 ;

-- --------------------------------------------------------

--
-- Table structure for table `notification`
--

CREATE TABLE IF NOT EXISTS `notification` (
  `id` int(23) NOT NULL,
  `text` varchar(2000) COLLATE ascii_bin NOT NULL,
  `seen` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=ascii COLLATE=ascii_bin;

-- --------------------------------------------------------

--
-- Table structure for table `polltable`
--

CREATE TABLE IF NOT EXISTS `polltable` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` varchar(30) DEFAULT NULL,
  `TextOrImage_id` int(11) DEFAULT NULL,
  `type` varchar(12) DEFAULT NULL,
  `votes` varchar(22) DEFAULT NULL,
  `created_at` datetime DEFAULT NULL,
  `updated_at` datetime DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `poll_titletext` (`user_id`),
  KEY `text_id` (`TextOrImage_id`),
  KEY `ratiotext` (`type`),
  KEY `updated_ontext` (`updated_at`),
  KEY `created_ontext` (`created_at`),
  KEY `image_id` (`votes`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `textpoll`
--

CREATE TABLE IF NOT EXISTS `textpoll` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `input_text` varchar(150) NOT NULL,
  `text_duration` int(33) NOT NULL,
  `input_image` varchar(333) DEFAULT NULL,
  `poll_titletext` varchar(30) DEFAULT 'What do u think',
  `yes` int(11) DEFAULT '0',
  `no` int(11) DEFAULT '0',
  `maybe` int(11) DEFAULT '0',
  `total` int(11) DEFAULT '0',
  `ratiotext` varchar(22) NOT NULL DEFAULT '00:00:00',
  `access_list` text,
  `created_at` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `updated_at` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  KEY `id` (`user_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=36 ;

-- --------------------------------------------------------

--
-- Table structure for table `userinfo`
--

CREATE TABLE IF NOT EXISTS `userinfo` (
  `id` int(4) NOT NULL AUTO_INCREMENT COMMENT 'user’s id',
  `nickname` varchar(20) NOT NULL,
  `phonenumber` bigint(15) NOT NULL COMMENT ' user’s phone number',
  `friend` text,
  `friends_to_be` text,
  `friend_requests` text,
  `password` varchar(535) DEFAULT NULL COMMENT ' user’s password',
  `created_at` datetime NOT NULL,
  `updated_at` datetime NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `phonenumber` (`phonenumber`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=49 ;

-- --------------------------------------------------------

--
-- Table structure for table `user_tokens`
--

CREATE TABLE IF NOT EXISTS `user_tokens` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `token` varchar(255) DEFAULT NULL,
  `user_id` int(11) DEFAULT NULL,
  `expires` datetime DEFAULT NULL,
  `lastusedate` datetime DEFAULT NULL,
  `created_at` datetime DEFAULT NULL,
  `updated_at` datetime DEFAULT NULL,
  `deleted_at` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
