<?php
  session_start();
  $_SESSION["id"]=$_POST["board"].$_POST["roll_no"];
  $servername="localhost";
  $username="root";
  $password="";
  $database="cet";
  $conn=mysqli_connect($servername,$username,$password,$database);
  if(!$conn){
    echo "unable to find open the server or database, Please try again later some time";
  }
  else{
    $a=$_POST["board"].$_POST["roll_no"];
    $b=$_POST["password"];
    $query="SELECT * from enrol where (ID='$a' and password='$b')";
    $result=mysqli_query($conn,$query);
    if($result==null){
      echo "Sorry, incorrect password or user roll number and board";
    }
    else{
      include "wtp_test_link.html";
    }
  }
  ?>
