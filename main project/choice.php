<?php
 session_start();
 $entry=explode(";",$_GET["choices"]);
 $f1=fopen("choice_entry.txt","a");
 foreach ($entry as $key => $value) {
   if($value==''){
     continue;
   }
   $ind=explode(",",$value);

   fwrite($f1,$_SESSION['id']);
   fwrite($f1,",");
   fwrite($f1,$ind[0]);
   fwrite($f1,",");
   fwrite($f1,$ind[1]);
   fwrite($f1,"\n");
 }
 fclose($f1);
 include "wtp_test_link.html";

 ?>
