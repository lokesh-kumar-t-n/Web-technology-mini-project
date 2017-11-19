<?php
  session_start();
	$servername="localhost";
	$username="root";
	$password="";
	$conn=mysqli_connect($servername,$username,$password,"CET");
	$id=$_POST['Board'].$_POST['rollno'];
	$_SESSION['id']=$id;
	$firstname=$_POST['firstname'];
	$lastname=$_POST['lastname'];
	$password=$_POST['password'];
	$query="SELECT * FROM Enrol WHERE (ID='$id')";
	$res=mysqli_query($conn,$query);
	if(mysqli_fetch_assoc($res)==NULL){
		$query="INSERT INTO Enrol VALUES('$id','$firstname','$lastname','$password')";
		mysqli_query($conn,$query);
		include "wtp_test_link.html";
	}
	else{
		include "main.html";
	}

?>
