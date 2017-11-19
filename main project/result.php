<?php
  session_start();
  exec("gcc web_help.c");
  exec("a.exe");
  echo "over";
  echo "<html>
  <head> <title> alloted seat </title>
  </head>
  <body>
    <link href=\"main.css\" rel=\"stylesheet\" type=\"text/css\" >
    <div class=\"heading\">
      <img src=\"KCET.jpg\" float=\"left\" width=\"300px\" height=\"150px\" style=\"display:inline\">
      <h1 style=\"display:inline\"> Karnataka Common Entrance Test </h1>
      <img src=\"ele.jpg\" float=\"right\" width=\"300px\" height=\"150px\" style=\"display:inline\">
     </div>";
  $f1=fopen("allocate.txt","r");
  while(!feof($f1)){
    $str=fgets($f1,100);
    $data=explode(",",$str);
    if($data[0]==$_SESSION['id']){
      echo "<div class='content'>";
      echo "<h1>The allocated seat is:</h1>";
      echo "<h2>College: ".$data[1];
      echo "<br>";
      echo "Branch: ".$data[2];
      echo "</h2></div>";
      break;
    }
  }
  if(feof($f1)){
    echo "<div class='content'>Sorry, we could not allocate any seat to you based on your marks and your choices</div>";
  }
  echo "</body>";
  echo "</html>";
?>
