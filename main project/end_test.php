<?php
  session_start();
  $f1=fopen("test_marks.txt","a");
  fwrite($f1,$_SESSION['id']);
  fwrite($f1,",".$_GET['marks']);
  fwrite($f1,"\n");
  fclose($f1);
  include "wtp_test_link.html";
 ?>
