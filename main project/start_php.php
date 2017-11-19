<?php
  $servername="localhost";
  $username="root";
  $password="";
  $conn=mysqli_connect($servername,$username,$password);
  $query="CREATE DATABASE CET";
  $status=mysqli_query($conn,$query);
  mysqli_close($conn);
  $conn=mysqli_connect($servername,$username,$password,"CET");
  $query="CREATE TABLE Enrol (ID VARCHAR(20) PRIMARY KEY,FirstName VARCHAR(50),LastName VARCHAR(50),Password VARCHAR(50))";
  $status=mysqli_query($conn,$query);
  $query="CREATE TABLE Alloted (ID VARCHAR(20) PRIMARY KEY,College VARCHAR(100),Branch VARCHAR(100))";
  $status=mysqli_query($conn,$query);
  mysqli_close($conn);
 ?>
