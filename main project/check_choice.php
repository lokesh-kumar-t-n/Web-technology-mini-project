<?php
 session_start();
 $f1=fopen("choice_entry.txt","r+");
 if($f1==null){
   echo "unable to open file";
   include "wtp_test_link.html";
 }
 while(!feof($f1)){
   $str=fgets($f1,100);
   $data=explode(",",$str);
   if($data[0]==$_SESSION['id']){
     echo "sorry, you have already entered the options. You cannot do it again";
     break;
   }
 }
 if(feof($f1)){
   include "enter_option.html";
 }
 ?>
