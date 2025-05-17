<?php
error_reporting( E_ALL );
ini_set( "display_errors", 1 );
session_start();


function error($msg) {
    die("<script>alert('$msg'); history.back();</script>");
}

if(isset($_POST["upload"])) {
    $tmp_name = $_FILES["file"]["tmp_name"];
    $filename = urldecode($_FILES["file"]["name"]);

    $image = file_get_contents($tmp_name);
    
    if(!exif_imagetype($tmp_name))
        error("no exif");

    if(stripos($image, "<?") !== false)
        error("no php, no hack");

    $img_size = getimagesize($tmp_name);
    if ($img_size[0] < 100 || $img_size[1] < 100)
        error("We only accept high-resolution image");

    $signature = md5(time().$_SERVER["REMOTE_ADDR"].rand(10000, 99999));
    
    mkdir("uploads/{$signature}/");
    $dest = "uploads/{$signature}/{$filename}";
    move_uploaded_file($tmp_name, $dest);
    chmod($dest, 0777);

    if(!isset($_SESSION["files"]))
        $_SESSION["files"] = array();
    $_SESSION["files"][] = array($filename, $signature, $dest);
} else {
    echo "file not founded";
}
?>
<script>location.href="index.php";</script>