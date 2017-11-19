<?php
 session_start();
 $f1=fopen("test_marks.txt","r");
 $flag=1;
 while(!feof($f1)){
   $text=fgets($f1,1000);
   if($text==''){
     break;//this is because at the end the $text becomes empty string which gives a warning
   }
   $data=explode(",",$text);
   if($_SESSION['id']==$data[0]){
     echo "sorry, you have already taken test. You cannot take it again";
     $flag=0;
     break;
   }
 }
 if($flag){
   include "question.html";
 }
 ?>
