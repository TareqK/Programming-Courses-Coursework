SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

DROP SCHEMA IF EXISTS `hospitalDB` ;
CREATE SCHEMA IF NOT EXISTS `hospitalDB` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci ;
SHOW WARNINGS;
USE `hospitalDB` ;

-- -----------------------------------------------------
-- Table `Doctor`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `Doctor` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `Doctor` (
  `DocID` INT NOT NULL ,
  `Name` VARCHAR(45) NULL ,
  `Department` VARCHAR(45) NULL ,
  `Specialization` VARCHAR(45) NULL ,
  `PhoneNo` VARCHAR(45) NULL ,
  `Address` VARCHAR(45) NULL ,
  PRIMARY KEY (`DocID`) )
ENGINE = InnoDB;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `Department`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `Department` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `Department` (
  `DepartmentID` INT NOT NULL ,
  `Name` VARCHAR(45) NULL ,
  `DoctorID` INT NULL ,
  PRIMARY KEY (`DepartmentID`) )
ENGINE = InnoDB;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `Room`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `Room` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `Room` (
  `RoomNo` INT NOT NULL ,
  `Location` VARCHAR(45) NULL ,
  PRIMARY KEY (`RoomNo`) )
ENGINE = InnoDB;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `Patient`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `Patient` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `Patient` (
  `PatientID` INT NOT NULL ,
  `Name` VARCHAR(45) NULL ,
  `PhoneNo` VARCHAR(45) NULL ,
  `Address` VARCHAR(45) NULL ,
  `Age` INT NULL ,
  `Sex` VARCHAR(45) NULL ,
  `RoomNo` INT NULL ,
  PRIMARY KEY (`PatientID`) )
ENGINE = InnoDB;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `Staff`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `Staff` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `Staff` (
  `StaffID` INT NOT NULL ,
  `Name` VARCHAR(45) NULL ,
  `Type` VARCHAR(45) NULL ,
  PRIMARY KEY (`StaffID`) )
ENGINE = InnoDB;

SHOW WARNINGS;

-- -----------------------------------------------------
-- Table `Bill`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `Bill` ;

SHOW WARNINGS;
CREATE  TABLE IF NOT EXISTS `Bill` (
  `BillNo` INT NOT NULL ,
  `Patient Name` VARCHAR(45) NULL ,
  `Amount` FLOAT NULL ,
  PRIMARY KEY (`BillNo`) )
ENGINE = InnoDB;

SHOW WARNINGS;
USE `hospitalDB` ;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
