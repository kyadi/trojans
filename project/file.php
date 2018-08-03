<?php
s : $conn = new mysqli('localhost','root','','data');
$file = fopen("ready_list.txt", "r");

while (!feof($file)) {
	$content = fgets($file);
	$array = explode("|", $content);
	list($clientid,$jobid,$result,$function,$time) = $array;
	$sql = "INSERT INTO `table_task`(`clientid`,`jobid`,`result`,`function`,`time`) VALUES ('$clientid','$jobid','$result','$function','$time')";
	$conn->query($sql);
}
	fclose($file);
	
?>
<html>
	<head>
		<meta http-EQUIV="refresh" CONTENT="60">
	</head>
</html>
