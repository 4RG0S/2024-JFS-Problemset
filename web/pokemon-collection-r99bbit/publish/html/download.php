<?php
session_start();
function error($msg) {
    die("<script>alert('$msg'); history.back();</script>");
}

$sig = $_GET["sig"] ?? "";

if(!isset($_SESSION["files"]))
    error("no session");

$f = false;
foreach($_SESSION["files"] as $t) {
    if ($t[1] === $sig)
        $f = $t;
}

if($f === false)
    error("no file");

$realfile = $t[2];
header("Content-Type: application/octet-stream");
header('Content-Disposition: attachment; filename="'.basename($realfile).'"');
header("Content-Length: ".filesize($realfile));
readfile($realfile);
?>