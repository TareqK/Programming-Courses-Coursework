SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

CREATE SCHEMA IF NOT EXISTS `hospitalDB` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci ;
USE `hospitalDB` ;
Doctor
-- -----------------------------------------------------
-- Table `hospitalDB`.`Doctor`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `hospitalDB`.`Doctor` (
  `DocID` INT NOT NULL ,
  `Name` VARCHAR(45) NULL ,
  `Department` VARCHAR(45) NULL ,
  `Specialization` VARCHAR(45) NULL ,
  `PhoneNo` VARCHAR(45) NULL ,
  `Address` VARCHAR(45) NULL ,
  PRIMARY KEY (`DocID`) )
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `hospitalDB`.`Department`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `hospitalDB`.`Department` (
  `DepartmentID` INT NOT NULL ,
  `Name` VARCHAR(45) NULL ,
  `DoctorID` INT NULL ,
  PRIMARY KEY (`DepartmentID`) ,
  INDEX `DorctorID_idx` (`DoctorID` ASC) ,
  CONSTRAINT `DorctorID`
    FOREIGN KEY (`DoctorID` )
    REFERENCES `hospitalDB`.`Doctor` (`DocID` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `hospitalDB`.`Room`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `hospitalDB`.`Room` (
  `RoomNo` INT NOT NULL ,
  `Location` VARCHAR(45) NULL ,
  PRIMARY KEY (`RoomNo`) )
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `hospitalDB`.`Patient`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `hospitalDB`.`Patient` (
  `PatientID` INT NOT NULL ,
  `Name` VARCHAR(45) NULL ,
  `PhoneNo` VARCHAR(45) NULL ,
  `Address` VARCHAR(45) NULL ,
  `Age` INT NULL ,
  `Sex` VARCHAR(45) NULL ,
  `RoomNo` INT NULL ,
  PRIMARY KEY (`PatientID`) ,
  INDEX `RoomNo_idx` (`RoomNo` ASC) ,
  CONSTRAINT `RoomNo`
    FOREIGN KEY (`RoomNo` )
    REFERENCES `hospitalDB`.`Room` (`RoomNo` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `hospitalDB`.`Staff`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `hospitalDB`.`Staff` (
  `StaffID` INT NOT NULL ,
  `Name` VARCHAR(45) NULL ,
  `Type` VARCHAR(45) NULL ,
  PRIMARY KEY (`StaffID`) )
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `hospitalDB`.`Bill`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `hospitalDB`.`Bill` (
  `BillNo` INT NOT NULL ,
  `Patient Name` VARCHAR(45) NULL ,
  `Amount` FLOAT NULL ,
  PRIMARY KEY (`BillNo`) )
ENGINE = InnoDB;

USE `hospitalDB` ;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
